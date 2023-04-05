#include "mainwindow.h"

#include <QApplication>
#include <Qylon.h>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Qylon::Qylon qy;
    MainWindow w;





    auto obj = qy.addQylonCamera();
//    obj->openCamera("Basler acA1300-60gm (24070434)");

    w.set(obj);

    QObject::connect(obj, SIGNAL(grabbed()), &w, SLOT(get()));

    w.show();
    return a.exec();
}
