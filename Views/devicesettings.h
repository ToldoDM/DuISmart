#ifndef DEVICESETTINGS_H
#define DEVICESETTINGS_H


#include <QDialog>
#include <QDialogButtonBox>
#include <QGridLayout>


class DeviceSettings: public QDialog
{
    Q_OBJECT

public:
    /**
     * @brief Settings: Costruttore di default
     */
    explicit DeviceSettings();

    /**
     * @brief ~DeviceSettings: Distruttore
     */
    virtual ~DeviceSettings();

protected slots:

    virtual void accept();

    void cancel();

protected:

    /**
     * @brief idDevice: Id device a cui e' associato
     */
    int idDevice;

    /**
     * @brief gLayout: Layout principale finestra setting
     */
    QGridLayout * gLayout;

private:

    /**
     * @brief settingsBox: Bottoni dialog
     */
    QDialogButtonBox * settingsBox;

};

#endif // SETTINGS_H
