#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QTimer>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->graphicsView->setScene(&scene);
    scene.addItem(&item);

    connect(ui->pushButton_conf, &QPushButton::clicked, this, [=](){
        this->qylon->getWidget()->show();
    });
    connect(ui->pushButton, &QPushButton::clicked,  this, [=](){
        this->qylon->continuousGrab();
    });
    connect(ui->pushButton_grab, &QPushButton::clicked,  this, [=](){
        this->qylon->singleGrab();
    });
    connect(ui->pushButton_2, &QPushButton::clicked,  this, [=](){
        this->qylon->stopGrab();
    });

    timer.start(1000);
    connect(&timer, &QTimer::timeout, [this](){

        this->ui->statusbar->showMessage("FPS : " + QString::number(cnt));
        cnt = 0;
    });

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::get()
{
    qylon->drawLock();
    item.setPixmap(QPixmap::fromImage(qylon->getImage()));
    cnt++;
}

