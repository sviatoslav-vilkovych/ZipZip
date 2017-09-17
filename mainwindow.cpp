#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <zlib.h>
#include <JlCompress.h>

#include <iostream>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    path = new QString("Hello. Please choose folder.");
    ui->path_lineEdit->setText(*path);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::OnStringChange(QString* value)
{
    delete[] path;
    path = new QString(*value);
    ui->path_lineEdit->setText(*path);
}

void MainWindow::on_browse_pushButton_clicked()
{
    new_ui = new Browse();
    new_ui->setModal(true);
    new_ui->show();
    new_ui->subscribe(this);
    ui->path_lineEdit->setText("Windows closed!");
}
