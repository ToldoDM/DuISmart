#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QPushButton>
#include <QLabel>
#include <QTabBar>
#include <QBoxLayout>
#include <QListWidget>
#include "Models/mainviewmodel.h"
#include "CustomItems/devicelistitem.h"

class MainWindow : public QWidget
{
    Q_OBJECT
public:
    explicit MainWindow(MainViewModel* model, QWidget *parent = nullptr);

signals:

public slots:
    void clieckedHandler();

private:
    MainViewModel* model;

    QPushButton *button;
    QTabBar *tab;
    QListWidget *listW;
};

#endif // MAINWINDOW_H
