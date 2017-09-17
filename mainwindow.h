#pragma once
#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <string>
#include "browse.h"

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

private:
    Ui::MainWindow *ui;
    Browse *new_ui;
    QString *path;
};

#endif // MAINWINDOW_H
