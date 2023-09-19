#pragma once

#include <QWidget>
#include <QLabel>
#include "RGBA.h"
#include "QtGui/qevent.h"
#include "graycanvas.h"
#include "colorcanvas.h"


class SupportCanvas2D : public QLabel {
    Q_OBJECT
public:
    ~SupportCanvas2D();

    void initializeCanvas(std::string canvasType);
    void colorCanvas();

    int getWidth() {return m_canvasW;}
    int getHeight() {return m_canvasH;}

    std::vector<uint8_t> *getData(){return &m_data;}
    QLabel *getImage() {return m_image;}

protected:
    virtual void mousePressEvent(QMouseEvent *event) override;
    virtual void mouseMoveEvent(QMouseEvent *event) override;
    virtual void mouseReleaseEvent(QMouseEvent *event) override;

private:
    std::vector<uint8_t> m_data;
    QLabel *m_image;
    GrayCanvas *m_grayCanvas;
    ColorCanvas *m_colorCanvas;

    int m_canvasW;
    int m_canvasH;
    std::string m_canvasType;

    // takes care of coloring and scaling canvas data
    void scaleCanvas();
    void scaleGray(int smallIndex, int bigIndex);
    void scaleColor(int smallIndex, int bigIndex);
};
