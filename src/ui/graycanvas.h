#pragma once

#include <vector>
#include <stdint.h>

class GrayCanvas
{
public:
    void initializeGrayCanvas();
    void createHeart();

    std::vector<uint8_t> &getCanvasData() {return m_canvasData;}

private:
    std::vector<uint8_t> m_canvasData;
    uint8_t floatToInt(float intensity);
};
