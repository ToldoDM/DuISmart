#ifndef CONTROLLER_H
#define CONTROLLER_H

#include<QObject>
#include<Models/mainviewmodel.h>
#include<Views/mainwindow.h>

class Controller : public QObject {
    Q_OBJECT


signals:

public slots:

private:

    //Main Window
    MainViewModel* MainVM;
    MainWindow* MainW;

public:
    /**
     * @brief Controller	costruttore del controller
     * @param parent        widget genitore
     */
    Controller(QObject* parent = nullptr);

    /**
     * @brief ShowMainWindow	Comando che rende visibile la mainWindow
     */
    void ShowMainWindow() const;
};

#endif
