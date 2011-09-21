#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDir>
#include <QProcess>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setFixedSize(QSize::QSize(515,280));
    ui->behButton->setStyleSheet("background-image: url(ressources/beh.png);");
    ui->consButton->setStyleSheet("background-image: url(ressources/cons.png);");
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_behButton_clicked()
{
    QString prog=QDir::toNativeSeparators(QDir::currentPath())+"\\bin2launch\\BCG.exe";
    QProcess::startDetached("\""+prog+"\"",QStringList(),QDir::toNativeSeparators(QDir::currentPath())+"\\bin2launch");
}

void MainWindow::on_consButton_clicked()
{
    QString prog=QDir::toNativeSeparators(QDir::currentPath())+"\\bin2launch\\CCG.exe";
    QProcess::startDetached("\""+prog+"\"",QStringList(),QDir::toNativeSeparators(QDir::currentPath())+"\\bin2launch");
}
