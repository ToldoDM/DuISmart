#ifndef DEVICESETTINGS_H
#define DEVICESETTINGS_H


#include <QDialog>
#include <QDialogButtonBox>
#include <QGridLayout>


class Settings: public QDialog
{
    Q_OBJECT

public:
    explicit Settings(QDialog *parent=nullptr);
    QGridLayout * gLayout;

public slots:
    virtual void accept();
    void cancel();

private:

    QDialogButtonBox * settingsBox;

};

#endif // SETTINGS_H
