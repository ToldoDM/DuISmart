#ifndef DEVICESETTINGS_H
#define DEVICESETTINGS_H


#include <QDialog>
#include <QDialogButtonBox>
#include <QWidget>

#include <QGridLayout>


class Settings: public QWidget
{
    Q_OBJECT

public:
    explicit Settings(QWidget *parent=nullptr);
    QGridLayout * gLayout;

public slots:
    virtual void accept();
    void cancel();


private:

    QDialogButtonBox * settingsBox;

};

#endif // SETTINGS_H
