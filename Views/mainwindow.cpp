#include "mainwindow.h"

MainWindow::MainWindow(MainViewModel* model, QWidget *parent) : QWidget(parent)
{
    this->model = model;

    setWindowTitle ("DuISmartMainWindow");
    setFixedSize(640,480);


    // Here some first widget
    QWidget *wid1 = new QWidget(this);
    QHBoxLayout *wid1Lay = new QHBoxLayout(wid1);
    listW = new QListWidget(wid1);
    wid1Lay->addWidget(listW);

    QListWidgetItem *item = new QListWidgetItem(listW);
    listW->addItem(item);

    DeviceListItem *dli = new DeviceListItem();
    item->setSizeHint(dli->minimumSizeHint());

    listW->setItemWidget(item, dli);


    // Here some second widget
    QWidget *wid2 = new QWidget(this);
    QHBoxLayout *wid2Lay = new QHBoxLayout(wid2);
    wid2Lay->addWidget(new QLabel(tr("Widget2")));

    // Here some third widget
    QWidget *wid3 = new QWidget(this);
    QHBoxLayout *wid3Lay = new QHBoxLayout(wid3);
    wid3Lay->addWidget(new QLabel(tr("Widget3")));

    // Here your Tab bar with only bars
    tab = new QTabBar(this);
    tab->addTab("One");
    tab->addTab("Two");
    tab->addTab("Three");

    // Here some label (for example, current time) and button
    QLabel *lab = new QLabel(tr("Some text"), this);
    button = new QPushButton(tr("bottone prova"), this);

    // Main layouts
    QVBoxLayout *vLay = new QVBoxLayout(this);
    QHBoxLayout *hLay = new QHBoxLayout();

    vLay->addLayout(hLay);
    hLay->addWidget(tab);
    // Spacer for expanding left and right sides
    hLay->addItem(new QSpacerItem(0, 0, QSizePolicy::Expanding, QSizePolicy::Minimum));
    hLay->addWidget(lab);
    hLay->addWidget(button);

    vLay->addWidget(wid1);
    vLay->addWidget(wid2);
    vLay->addWidget(wid3);

    // Some simple connect with lambda for navigation
    connect(tab, &QTabBar::currentChanged, [=] (int index) {

        wid1->setVisible(false);
        wid2->setVisible(false);
        wid3->setVisible(false);

        switch(index) {
        case 0: wid1->setVisible(true);
            break;
        case 1: wid2->setVisible(true);
            break;
        case 2: wid3->setVisible(true);
            break;
        default:{}
        }

    });

    emit tab->currentChanged(0);

    /*tab = new QTabBar(this);
    tab->addTab("test");
    tab->addTab("test1");

    text1 = new QLabel("questa e' la label1");
    text2 = new QLabel("questa e' la label2");

    button = new QPushButton("bottone prova",this);

    layout = new QBoxLayout(QBoxLayout::TopToBottom, this);
    layout->addWidget(tab);
    layout->addWidget(button);*/


    connect(button,SIGNAL(clicked()),this,SLOT(clieckedHandler()));
}

void MainWindow::clieckedHandler(){
    tab->addTab("test4");
}

