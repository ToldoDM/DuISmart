#include "duismart.h"
#include "ui_duismart.h"

DuiSmart::DuiSmart(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::DuiSmart)
{
    ui->setupUi(this);
}

DuiSmart::~DuiSmart()
{
    delete ui;
}
