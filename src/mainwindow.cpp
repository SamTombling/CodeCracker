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

void MainWindow::on_shiftLeft_clicked()
{
    Encrypter* encrypter = new Encrypter(ui->cypherText->toPlainText());
    encrypter->substitution(-1);
    ui->plainText->clear();
    ui->plainText->append(encrypter->cypherText());
    delete encrypter;
}

void MainWindow::on_shiftRight_clicked()
{
    Encrypter* encrypter = new Encrypter(ui->cypherText->toPlainText());
    encrypter->substitution(1);
    ui->plainText->clear();
    ui->plainText->append(encrypter->cypherText());
    delete encrypter;
}

