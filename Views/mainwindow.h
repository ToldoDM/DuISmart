#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QWidget>
#include <QPushButton>
#include <Models/mainviewmodel.h>

class MainWindow : public QWidget
{
    Q_OBJECT
public:
    explicit MainWindow(MainViewModel* model, QWidget *parent = nullptr);

signals:

public slots:

private:
    MainViewModel* model;
    QPushButton* button;
};

#endif // MAINWINDOW_H
