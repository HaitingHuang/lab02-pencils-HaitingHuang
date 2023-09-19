#pragma once

#include <QMainWindow>
#include "ui/supportcanvas2d.h"

class MainWindow : public QWidget
{
    Q_OBJECT

public:
    ~MainWindow();

    void canvasSetup(QStringList args);
    void displayCanvas();

private:
    SupportCanvas2D *m_supportcanvas;
};
