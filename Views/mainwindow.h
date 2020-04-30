#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QWidget>
#include <QPushButton>
#include <QTabBar>
#include <QSizePolicy>
#include <Models/mainviewmodel.h>

class MainWindow : public QWidget
{
    Q_OBJECT
public:
    explicit MainWindow(MainViewModel* model, QWidget *parent = nullptr);

signals:
    void notifyController();

public slots:
    void clieckedHandler();
    void refresh();

private:
    MainViewModel* model;

    QPushButton* button;
    QTabBar* tab;
};

#endif // MAINWINDOW_H
