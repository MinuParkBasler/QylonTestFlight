#include "mainwindow.h"

#include <QApplication>
#include <Qylon.h>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Qylon::Qylon qy;
    MainWindow w;

//    auto obj = qy.addCamera();
//    obj->openCamera("Basler acA1300-60gm (24070434)");

//    auto grabber = qy.addGrabber();

//    grabber->loadApplet("Cleanc_AF_VCL_Mono8_V1.hap");
//    grabber->loadConfiguration("/home/minwoo/Projects/Qylon/Acquisition/Cleanc_AF_VCL_Mono8_V1.hap");
//    grabber->initialize();



//    engine->addSequence(Qylon::Sequence_Threshold);



//    w.set(obj);

//    QObject::connect(obj, SIGNAL(grabbed()), &w, SLOT(get()));

    w.show();
    return a.exec();
}
