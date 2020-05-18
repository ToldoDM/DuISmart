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

    /**
     * @brief MainVM: model della MainWindow
     */
    MainViewModel* MainVM;
    /**
     * @brief MainW: Finestra principale
     */
    MainWindow* MainW;

public:
    /**
     * @brief Controller	costruttore del controller
     * @param parent        widget genitore
     */
    Controller(QObject* parent = nullptr);

    /**
     * @brief ShowMainWindow: Comando che chiama show della mainWindow
     */
    void ShowMainWindow() const;
};

#endif
