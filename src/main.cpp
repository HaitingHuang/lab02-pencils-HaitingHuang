#include <QApplication>
#include "mainwindow.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QCoreApplication::setApplicationName("lab02");
    QCoreApplication::setOrganizationName("BrownCSCI1230");
    QCoreApplication::setApplicationVersion(QT_VERSION_STR);

    MainWindow w;
    w.canvasSetup(QCoreApplication::arguments());
    w.displayCanvas();
    w.show();
    return a.exec();
}
