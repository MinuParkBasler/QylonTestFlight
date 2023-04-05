#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "qtimer.h"
#include <QMainWindow>
#include <QGraphicsScene>
#include <QGraphicsPixmapItem>

#include <Acquisition/Camera.h>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    void set(Qylon::Camera *obj){
        qylon = obj;
//        qylon->getWidget()->setParent(this);


    }

public slots:
    void get();

private:
    Ui::MainWindow *ui;
    Qylon::Camera *qylon;
    QGraphicsScene scene;
    QGraphicsPixmapItem item;
    QTimer timer;
    unsigned int cnt=0;
};
#endif // MAINWINDOW_H
