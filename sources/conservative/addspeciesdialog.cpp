#include "addspeciesdialog.h"
#include "ui_addspeciesdialog.h"
#include <QMessageBox>

using namespace std;

addSpeciesDialog::addSpeciesDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::addSpeciesDialog)
{
    ui->setupUi(this);
    this->ui->nameToAdd->setFocus();
}

addSpeciesDialog::~addSpeciesDialog()
{
    delete ui;
}

void addSpeciesDialog::on_addButton_clicked()
{
    string name = this->ui->nameToAdd->text().toStdString();
    float initial_value = this->ui->doubleSpinBox->value();

    if(name!=""){
        emit addSpeciesRequestFromDia(name,initial_value);
        this->close();
    }
    else{
        QMessageBox::warning(this, "Adding Error", "Please specify the name of the species.");
    }

}

void addSpeciesDialog::on_cancelButton_clicked()
{
    this->close();
}

