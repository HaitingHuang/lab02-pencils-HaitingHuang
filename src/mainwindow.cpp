#include <QHBoxLayout>
#include "mainwindow.h"

void MainWindow::canvasSetup(QStringList args) {
    // parses the command line arguments
    std::string canvasType;
    if (args.count() > 1) {
        canvasType = args.at(1).toStdString();
    } else {
        canvasType = "black";
    }

    setWindowTitle(QStringLiteral("Lab 2 Pencils"));

    QHBoxLayout *hLayout = new QHBoxLayout();
    this->setLayout(hLayout);

    m_supportcanvas = new SupportCanvas2D();
    m_supportcanvas->setEnabled(true);
    m_supportcanvas->initializeCanvas(canvasType);
    hLayout->addWidget(m_supportcanvas, 0, Qt::AlignCenter);
}

void MainWindow::displayCanvas() {
    m_supportcanvas->colorCanvas();
}

MainWindow::~MainWindow()
{
    delete m_supportcanvas;
}
