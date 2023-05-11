#include "Processing/Sequence.h"
#include "mainwindow.h"

#include <QApplication>
#include <Qylon.h>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Qylon::Qylon qy;
    MainWindow w;


    /// Frame grabber
    if(false){
        auto grabber = qy.addGrabber();
        grabber->loadApplet("/home/minwoo/Projects/Qylon/Acquisition/Cleanc_AF_VCL_Mono8_V1_Linux_AMD64.hap");
        grabber->loadConfiguration("/home/minwoo/Projects/Qylon/Acquisition/Cleanc_AF_VCL_mono8_V1.mcf");
        grabber->initialize();

        grabber->continuousGrab();
        QObject::connect(grabber, SIGNAL(sendImage_original(QImage)), &w, SLOT(get(QImage)));
    }

    /// QDC
    if(false){
        // QDC Example
        auto engine = qy.addQDC();
        auto soft = engine->addSequence(Qylon::QDC::SequenceType::Sequence_SoftwareTrigger);
        auto thresh = engine->addSequence(Qylon::QDC::SequenceType::Sequence_Threshold);
        auto yo = dynamic_cast<Qylon::QDC::Threshold*>(thresh);

        // sequence list

        yo->setImage(&soft->container);
        soft->setNext(thresh);

        engine->run(soft);
    }


    // Pylon Example
    if(true){
        auto obj = qy.addCamera();
        w.set(obj);
        QObject::connect(obj, SIGNAL(grabbed()), &w, SLOT(get()));
    }






    w.show();
    return a.exec();
}
