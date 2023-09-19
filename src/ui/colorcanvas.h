#pragma once

#include <vector>
#include "RGBA.h"

class ColorCanvas
{
public:
    void initializeColorCanvas();

    std::vector<RGBA> &getCanvasData() {return m_canvasData;}

    void mouseDown(int x, int y);
    void mouseMove(int x, int y);
    void mouseUp(int x, int y);

private:
    std::vector<RGBA> m_canvasData;
    bool m_isDown;

    // sets the color of the pencil
    RGBA m_pencilColor = RGBA{128, 147, 123, 255};

    void testPosToIndex();
    void drawFlower(int x, int y);
    int posToIndex(int x, int y);
};
