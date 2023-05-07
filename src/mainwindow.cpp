#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "encrypter.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::init()
{

}

void MainWindow::on_encryptButton_clicked()
{
    Encrypter* e = new Encrypter(ui->cypherText->toPlainText());
    e->setShifts(ui->spinBox->value());
    e->substitution();
    ui->plainText->clear();
    ui->plainText->append(e->cypherText());
}

