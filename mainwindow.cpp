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

    path = "Hello. Please choose folder or enter path by yourself.";
    ui->path_lineEdit->setText(path);

    extensionsList.append("*.rar");
    extensionsList.append("*.zip");
    ui->extenshion_comboBox->addItems(extensionsList);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::OnStringChange(QString* value)
{
    path = *value;
    ui->path_lineEdit->setText(path);
}

void MainWindow::on_browse_pushButton_clicked()
{
    new_ui = new Browse();
    new_ui->setModal(true);
    new_ui->show();
    new_ui->subscribe(this);
}

void MainWindow::on_process_buttonBox_clicked(QAbstractButton *button)
{
    if((QPushButton*) button == ui->process_buttonBox->button(QDialogButtonBox::Ok))
    {
        fileModel = new QFileSystemModel(this);
        fileModel->setFilter(QDir::NoDotAndDotDot | QDir::Files);
        fileModel->setRootPath(path);
        connect(fileModel, SIGNAL(directoryLoaded(QString)), this, SLOT(fill_path_list()));

        //JlCompress::compressFile("C:/test.zip", "C:/test.txt");
        archivingFiles();
    }
}

void MainWindow::fill_path_list()
{
    QModelIndex parentIndex = fileModel->index(path);
    int numRows = fileModel->rowCount(parentIndex);

    for (int row = 0; row < numRows; ++row) {
        QModelIndex childIndex = fileModel->index(row, 0, parentIndex);
        QString fileName = fileModel->data(childIndex).toString();
        // масив_токенів = стрічка.спліт(); масив_токенів.викинути_останній(); нова_стрічка = масив_токенів.склеяти();
        pathHash.insert(fileName.split('.').first(),fileName);
    }
}
int MainWindow::archivingFiles()
{

    QString archiveExtension;
    switch (ui->extenshion_comboBox->currentIndex())
    {
    case 1:
        archiveExtension.append(".rar");
        break;
    case 2:
        archiveExtension.append(".zip");
        break;
    }

    bool mode = (ui->crSubfolder_radioButton->isChecked())?1:0; // 0 - delete files, 1 - create subfolder

    auto it_pathHashEnd = pathHash.end();
    for(auto it_pathHash = pathHash.begin(); it_pathHash != it_pathHashEnd; ++it_pathHash)
    {

    }

    return 0;
}
