#ifndef MODIFYSPECIESDIAL_H
#define MODIFYSPECIESDIAL_H

#include <QDialog>
#include <string>

using namespace std;

namespace Ui {
    class modifySpeciesDial;
}

class modifySpeciesDial : public QDialog
{
    Q_OBJECT

public:
    explicit modifySpeciesDial(QWidget *parent = 0,QString name = "",QString value = "");
    ~modifySpeciesDial();

private:
    Ui::modifySpeciesDial *ui;

private slots:
    void on_cancelButton_clicked();
    void on_modifyButton_clicked();

signals:
    void modifySpeciesRequestFromDia(string name,float initial_value);
};

#endif // MODIFYSPECIESDIAL_H
