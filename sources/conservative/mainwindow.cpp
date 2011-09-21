#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    this->ui->setupUi(this);
    this->setFixedSize(QSize::QSize(900,350));
    this->ui->Species_list->header()->setResizeMode(QHeaderView::ResizeToContents);
    this->ui->Species_list->header()->setSortIndicator(0,Qt::AscendingOrder);
    this->ui->Reactions_list->header()->setResizeMode(QHeaderView::ResizeToContents);
    this->ui->Reactions_list->header()->setSortIndicator(0,Qt::AscendingOrder);
    this->ui->Species_list->header()->setResizeMode(QHeaderView::ResizeToContents);
}

MainWindow::~MainWindow()
{
    delete ui;
}

//*********************************************//
//                Species Part                 //
//*********************************************//


void MainWindow::on_add_species_clicked()
{
    this->dia = new addSpeciesDialog;
    connect(this->dia,SIGNAL(addSpeciesRequestFromDia(string,float)),this,SLOT(requestFromAddSpeciesDia(string,float)));
    this->dia->exec();
}

void MainWindow::on_remove_species_clicked()
{
    QTreeWidgetItem *del_item;
    del_item = this->ui->Species_list->currentItem();
    if(del_item!=NULL){
        string del_name = del_item->text(0).toStdString();
        emit removeSpeciesRequestFromUi(del_name);
    }
}

void MainWindow::on_modify_species_clicked()
{
    QTreeWidgetItem *modify_item;
    modify_item = this->ui->Species_list->currentItem();
    if(modify_item!=NULL){
    QString modify_name = modify_item->text(0);
    QString modify_value = modify_item->text(1);
    this->dia = new modifySpeciesDial(0,modify_name,modify_value);
    connect(this->dia,SIGNAL(modifySpeciesRequestFromDia(string,float)),this,SLOT(requestFromModifySpeciesDia(string,float)));
    this->dia->exec();
    }
}

void MainWindow::requestFromAddSpeciesDia(string name, float initial_value){
    emit addSpeciesRequestFromUi(name, initial_value);
}

void MainWindow::speciesAddingResult(bool res,string name, float initial_value){

    if(res){
        QString item_name = QString::fromStdString(name);
        QString item_ini_val;
        item_ini_val.setNum (initial_value);

        QTreeWidgetItem *item = new QTreeWidgetItem();
        item->setText(0,item_name); item->setText(1,item_ini_val);
        this->ui->Species_list->addTopLevelItem(item);
        QMessageBox::information(this,"Species added","The species "+item_name+" has been added successfully");
    }
    else{
        QMessageBox::warning(this, "Adding Error", "The species has not been added");
    }
}

void MainWindow::speciesRemovingResult(bool res,string name){
    if(res){
        QTreeWidgetItem *del_item;
        del_item = this->ui->Species_list->currentItem();
        int index = this->ui->Species_list->indexOfTopLevelItem(del_item);
        this->ui->Species_list->takeTopLevelItem(index);
        QMessageBox::information(this,"Species removed","The species "+QString::fromStdString(name)+" has been removed successfully");
    }
    else{
        QMessageBox::warning(this, "Removing Error", "The species has not been removed");
    }
}

void MainWindow::requestFromModifySpeciesDia(string name, float initial_value){
    emit modifySpeciesRequestFromUi(name, initial_value);
}

void MainWindow::speciesModifiingResult(bool res,string name, float initial_value){
    if(res){
        QString item_name = QString::fromStdString(name);
        QTreeWidgetItem *modif_item = this->ui->Species_list->currentItem();
        int index = this->ui->Species_list->indexOfTopLevelItem(modif_item);
        modif_item = this->ui->Species_list->takeTopLevelItem(index);
        QString item_ini_val;
        item_ini_val.setNum (initial_value);
        modif_item->setText(1,item_ini_val);
        this->ui->Species_list->addTopLevelItem(modif_item);

        QMessageBox::information(this,"Species modified","The species "+item_name+" has been modified successfully");
    }
    else{
        QMessageBox::warning(this, "Modifiing Error", "The species has not been modified");
    }
}


//*********************************************//
//                Reaction Part                //
//*********************************************//


void MainWindow::on_add_reactions_clicked()
{

    QStringList species_list;

    for(int i=0;i<this->ui->Species_list->topLevelItemCount();i++){
        species_list << this->ui->Species_list->topLevelItem(i)->text(0);
    }

    if(species_list.size()==0){
        QMessageBox::warning(this, "Reaction Error", "You need to define at least one specie to create a reaction.");
        return;
    }

    bool ok = false;
    QStringList reactions;
    QString chosen_reaction;
    reactions << "Complexation" << "Synthesis";
    chosen_reaction = QInputDialog::getItem(this, "Reaction choice", "Which reaction do you want to create ?", reactions,0,false,&ok);

    if(ok && species_list.size()!=0){
        if(chosen_reaction == "Complexation"){
            this->dia = new complexDialog(species_list);
            connect(this->dia,SIGNAL(addCplxRequestFromDia(QString,QStringList,QString)),this,SLOT(requestFromCplxDia(QString,QStringList,QString)));
            this->dia->exec();
        }

        if(chosen_reaction == "Synthesis"){
            this->dia = new synthDialog(species_list);
            connect(this->dia,SIGNAL(addSynthRequestFromDia(QString,QStringList,QString,QStringList,QList<float>)),this,SLOT(requestFromSynthDia(QString,QStringList,QString,QStringList,QList<float>)));
            this->dia->exec();
        }
    }
}

void MainWindow::on_remove_reactions_clicked()
{
    QTreeWidgetItem *del_item;
    del_item = this->ui->Reactions_list->currentItem();
    if(del_item!=NULL){
        string del_name = del_item->text(0).toStdString();
        emit removeReactionRequestFromUi(del_name);
    }
}

void MainWindow::requestFromCplxDia(QString name, QStringList species_to_complex, QString result, QList<float> parameters){
    emit addReactionRequestFromUi(name, CST_COMPLEXATION, species_to_complex, result,QStringList(), parameters);
}

void MainWindow::requestFromSynthDia(QString name, QStringList activators, QString result, QStringList repressors, QList<float> parameters){
    emit addReactionRequestFromUi(name, CST_SYNTHESIS, activators, result, repressors, parameters);
}

void MainWindow::reactionAddingResult(bool res, QString name, int type, QStringList speciesin, QString speciesout, QStringList speciesoptional){
    if(res){
        QTreeWidgetItem *item = new QTreeWidgetItem();
        item->setText(0,name);
        if(type == CST_COMPLEXATION){
            item->setText(1,"Complexation");
            item->setText(2,speciesin.join(" "));
        }
        else if(type == CST_SYNTHESIS){
            item->setText(1,"Synthesis");
            item->setText(2,"Act: " + speciesin.join(" ") + " Rep: " + speciesoptional.join(" "));
        }
        item->setText(3,speciesout);
        this->ui->Reactions_list->addTopLevelItem(item);
        QMessageBox::information(this,"Reaction added","The Reaction "+name+" has been added successfully");
    }
    else{
        QMessageBox::warning(this, "Adding Error", "The reaction has not been added");
    }
}

void MainWindow::reactionRemovingResult(bool res, string name){
    if(res){
        QTreeWidgetItem *del_item;
        del_item = this->ui->Reactions_list->currentItem();
        int index = this->ui->Reactions_list->indexOfTopLevelItem(del_item);
        this->ui->Reactions_list->takeTopLevelItem(index);
        QMessageBox::information(this,"Reaction removed","The reaction "+QString::fromStdString(name)+" has been removed successfully");
    }
    else{
        QMessageBox::warning(this, "Removing Error", "The reaction not has been removed");
    }
}


//*********************************************//
//                System Part                  //
//*********************************************//


void MainWindow::on_commandLinkButton_clicked()
{
    QList<QTreeWidgetItem*> react_list;
    for(int i=0;i<this->ui->Reactions_list->topLevelItemCount();i++){
        react_list << this->ui->Reactions_list->topLevelItem(i);
    }
    this->dia = new systemDialog(react_list);
    connect(this->dia,SIGNAL(createSystemRequestFromDia(QString,QStringList)),this,SLOT(requestFromSystemDia(QString,QStringList)));
    this->dia->exec();
}

void MainWindow::requestFromSystemDia(QString name, QStringList reactions){
    emit createSystemRequestFromUi(name,reactions);
}

void MainWindow::systemCreationResult(bool res, QString name){
    if(res){
        QMessageBox::information(this,"System creation","The system "+name+".vhd has been created successfully");
    }
    else{
        QMessageBox::warning(this, "Creation Error", "The system has not been created");
    }
}
