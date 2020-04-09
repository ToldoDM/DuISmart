#ifndef DUISMART_H
#define DUISMART_H

#include <QWidget>

namespace Ui {
class DuiSmart;
}

class DuiSmart : public QWidget
{
    Q_OBJECT

public:
    explicit DuiSmart(QWidget *parent = 0);
    ~DuiSmart();

private:
    Ui::DuiSmart *ui;
};

#endif // DUISMART_H
