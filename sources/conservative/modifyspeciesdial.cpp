#include "modifyspeciesdial.h"
#include "ui_modifyspeciesdial.h"
#include <QMessageBox>
#include <QString>

modifySpeciesDial::modifySpeciesDial(QWidget *parent,QString name,QString value) :
    QDialog(parent),
    ui(new Ui::modifySpeciesDial)
{
    ui->setupUi(this);
    this->ui->nameToModify->setText(name);
    this->ui->doubleSpinBox->setValue(value.toFloat());
    this->ui->nameToModify->setFocus();
}

modifySpeciesDial::~modifySpeciesDial()
{
    delete ui;
}

void modifySpeciesDial::on_modifyButton_clicked()
{
    string name = this->ui->nameToModify->text().toStdString();
    float initial_value = this->ui->doubleSpinBox->value();

    if(name!=""){
        emit modifySpeciesRequestFromDia(name,initial_value);
        this->close();
    }
    else{
        QMessageBox::warning(this, "Adding Error", "Please specify the name of the species.");
    }

}

void modifySpeciesDial::on_cancelButton_clicked()
{
    this->close();
}
