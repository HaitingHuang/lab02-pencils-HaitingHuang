#include <iostream>
#include "supportcanvas2d.h"

void SupportCanvas2D::initializeCanvas(std::string canvasType) {
    // Allows for leaky pencil to work
    setMouseTracking(true);

    m_canvasType = canvasType;
    m_canvasW = 500;
    m_canvasH = 500;

    // Initializes a black canvas
    for (int i = 0; i < 250000; i++) {
        m_data.push_back(0);
        m_data.push_back(0);
        m_data.push_back(0);
        m_data.push_back(255);
    }

    m_image = new QLabel();

    if (canvasType == "grayscale") {
        m_grayCanvas = new GrayCanvas();
        m_grayCanvas->initializeGrayCanvas();
    } else if (canvasType == "color") {
        m_colorCanvas = new ColorCanvas();
        m_colorCanvas->initializeColorCanvas();
    }
}

void SupportCanvas2D::colorCanvas() {
    // Scales to 500 x 500 canvas to be a 10 x 10 canvas
    scaleCanvas();

    std::vector<uint8_t> *buf;
    buf = this->getData();

    QByteArray* arr = new QByteArray(reinterpret_cast<const char*>(buf->data()), buf->size());

    QImage img = QImage((const uchar*) arr->data(), this->getWidth(), this->getHeight(), QImage::Format_RGBX8888);

    this->setPixmap(QPixmap::fromImage(img));
    this->show();
}

// This function scales the 500 x 500 pixel canvas to be a 10 x 10 canvas (allows for
// easier visualization
void SupportCanvas2D::scaleCanvas() {
    // For each pixel in the 10x10 canvas
    for (int i = 0; i < 100; i++) {
        // Calculates the (x and y) start and end indices in a 500x500 canvas
        int xStart = (i % 10) * 50;
        int xEnd = xStart + 50;
        int yStart = (i / 10) * 50;
        int yEnd = yStart + 50;

        for (int currY = yStart; currY < yEnd; currY++) {
            for (int currX = xStart; currX < xEnd; currX++) {
                // Calculates the index in m_image (2000 indices make up a row bc of the RGBA channels)
                int index = currY * 2000 + currX * 4;

                if (m_canvasType == "grayscale") {
                    scaleGray(index, i);
                } else if (m_canvasType == "color") {
                    scaleColor(index, i);
                }
            }
        }
    }
}

void SupportCanvas2D::scaleGray(int smallIndex, int bigIndex) {
    std::vector<uint8_t> &canvasData = m_grayCanvas->getCanvasData();
    if (canvasData.size() == 100) {
        m_data[smallIndex]     = canvasData[bigIndex];
        m_data[smallIndex + 1] = canvasData[bigIndex];
        m_data[smallIndex + 2] = canvasData[bigIndex];
        m_data[smallIndex + 3] = 255;
    }
}

void SupportCanvas2D::scaleColor(int smallIndex, int bigIndex) {
    std::vector<RGBA> &canvasData = m_colorCanvas->getCanvasData();
    if (canvasData.size() == 100) {
        m_data[smallIndex]     = canvasData[bigIndex].r;
        m_data[smallIndex + 1] = canvasData[bigIndex].g;
        m_data[smallIndex + 2] = canvasData[bigIndex].b;
        m_data[smallIndex + 3] = canvasData[bigIndex].a;
    }
}

void SupportCanvas2D::mousePressEvent(QMouseEvent *event) {
    if (m_canvasType == "grayscale") {
        std::cout << "Canvas must be color in order to use the pencil" << std::endl;
        return;
    }

    int x = event->pos().x() / 50;
    int y = event->pos().y() / 50;

    m_colorCanvas->mouseDown(x, y);
    colorCanvas();
}

void SupportCanvas2D::mouseMoveEvent(QMouseEvent *event) {
    if (m_canvasType == "grayscale") {
        std::cout << "Canvas must be color in order to use the pencil" << std::endl;
        return;
    }

    int x = event->pos().x() / 50;
    int y = event->pos().y() / 50;

    m_colorCanvas->mouseMove(x, y);
    colorCanvas();
}

void SupportCanvas2D::mouseReleaseEvent(QMouseEvent *event) {
    if (m_canvasType == "grayscale") {
        std::cout << "Canvas must be color in order to use the pencil" << std::endl;
        return;
    }

    int x = event->pos().x() / 50;
    int y = event->pos().y() / 50;

    m_colorCanvas->mouseUp(x, y);
    colorCanvas();
}

SupportCanvas2D::~SupportCanvas2D()
{
    delete m_image;
    delete m_grayCanvas;
    delete m_colorCanvas;
}
