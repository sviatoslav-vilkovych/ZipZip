#include "browse.h"
#include "ui_browse.h"

Browse::Browse(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Browse)
{
    ui->setupUi(this);

    QString sPath = "C:/";

    dirModel = new QFileSystemModel(this);
    dirModel->setFilter(QDir::NoDotAndDotDot | QDir::AllDirs);
    dirModel->setRootPath(sPath);

    ui->browse_treeView->setModel(dirModel);
    ui->path_label->setText(sPath);
}

Browse::~Browse()
{

    delete ui;

}

void Browse::on_browse_treeView_clicked(const QModelIndex &index)
{
    fileLabel = new QString(dirModel->fileInfo(index).absoluteFilePath());
    ui->path_label->setText(*fileLabel);

    observer->OnStringChange(fileLabel);
}

void Browse::subscribe(MainWindow *obj)
{
    this->observer = obj;
}

void Browse::on_browse_buttonBox_clicked(QAbstractButton *button)
{
    if((QPushButton*) button == ui->browse_buttonBox->button(QDialogButtonBox::Cancel))
    {
        this->close();

    }
    if((QPushButton*) button == ui->browse_buttonBox->button(QDialogButtonBox::Ok))
    {
        // send fileLabel to mainWindow

        this->close();
    }
}
