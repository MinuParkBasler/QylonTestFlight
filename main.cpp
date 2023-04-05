#include "mainwindow.h"

#include <QApplication>
#include <Qylon.h>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Qylon::Qylon qy;
    MainWindow w;

    auto obj = qy.addCamera();
//    obj->openCamera("Basler acA1300-60gm (24070434)");
    auto engine = qy.addQDC();

    engine->addSequence(Qylon::Sequence_Threshold);

    w.set(obj);

    QObject::connect(obj, SIGNAL(grabbed()), &w, SLOT(get()));

    w.show();
    return a.exec();
}
