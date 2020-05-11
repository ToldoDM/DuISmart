#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QWidget>
#include <QPushButton>
#include <QLabel>
#include <QTabBar>
#include <QBoxLayout>
#include <QListWidget>
#include <Models/mainviewmodel.h>

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
    QBoxLayout *layout;
    QListWidget *listW;
};

#endif // MAINWINDOW_H
