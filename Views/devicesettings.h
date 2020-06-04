#ifndef DEVICESETTINGS_H
#define DEVICESETTINGS_H


#include <QDialog>
#include <QVBoxLayout>
#include <QDialogButtonBox>
#include <QWidget>

class Settings: public QWidget
{
    Q_OBJECT
public:
    Settings(QWidget *parent=nullptr);

public slots:
    void accept();
    void cancel();


private:
    QVBoxLayout * vLayout;
    QDialogButtonBox * settingsBox;
};

#endif // SETTINGS_H
