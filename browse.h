#pragma once
#ifndef BROWSE_H
#define BROWSE_H

#include <QDialog>
#include <QFileSystemModel>
#include <QtGui>
#include <QtCore>
#include <QAbstractButton>
#include "mainwindow.h"

class MainWindow;

namespace Ui {
    class Browse;
}

class Browse : public QDialog
{
    Q_OBJECT

public:
    explicit Browse(QWidget *parent = 0);
    ~Browse();

    void subscribe(MainWindow*);
    MainWindow* observer;

private:
    Ui::Browse *ui;
    QFileSystemModel *dirModel;
    QString *fileLabel;

private slots:
    void on_browse_treeView_clicked(const QModelIndex &index);

    void on_browse_buttonBox_clicked(QAbstractButton *button);
};

#endif // BROWSE_H
