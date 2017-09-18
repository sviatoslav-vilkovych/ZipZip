#pragma once
#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QString>
#include <QList>
#include "browse.h"
#include <QFileSystemModel>

class Browse;

namespace Ui {
    class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    void OnStringChange(QString* value);

private slots:
    void on_browse_pushButton_clicked();

    void on_process_buttonBox_clicked(QAbstractButton *button);
    void fill_path_list();
signals:
    //void directoryLoaded(QString);
private:
    int archivingFiles();

    Ui::MainWindow *ui;
    Browse *new_ui;
    QString path;
    QList<QString> extensionsList;
    QFileSystemModel *fileModel;
    QHash<QString,QString> pathHash;
};

#endif // MAINWINDOW_H
