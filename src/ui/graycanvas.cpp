#include <cmath>
#include "graycanvas.h"


uint8_t GrayCanvas::floatToInt(float intensity) {
    // Task 3: convert a float into a uint8_t
    int int_intensity = static_cast<int8_t>(std::round(intensity * 255));
    uint8_t uint_intensity = static_cast<uint8_t>(int_intensity);
    return uint_intensity;
}

void GrayCanvas::initializeGrayCanvas() {
    // Task 4: initialize a 10 x 10 gray canvas where each pixel has an
    //         intensity of 0.123
    m_canvasData.assign(10 * 10, floatToInt(0.123));
    std::fill(m_canvasData.begin(), m_canvasData.end(), floatToInt(0.123));

    // Task 5: call the createHeart() function to display the canvas with
    //         the white heart
    createHeart();

}

int change_2_to_1_index(int row, int col) {
    // Task 5: create a heart on the canvas by turning certain pixels white
    //         so it matches the canvas in the handout
    int oneD_index = (row - 1) * 10 + (col - 1);
    return oneD_index;


}

void GrayCanvas::createHeart() {
    // Task 5: create a heart on the canvas by turning certain pixels white
    //         so it matches the canvas in the handout

    m_canvasData[(change_2_to_1_index(3,4))] = floatToInt(1.0);
    m_canvasData[(change_2_to_1_index(3,5))] = floatToInt(1.0);
    m_canvasData[(change_2_to_1_index(3,7))] = floatToInt(1.0);
    m_canvasData[(change_2_to_1_index(3,8))] = floatToInt(1.0);

    m_canvasData[(change_2_to_1_index(4,3))] = floatToInt(1.0);
    m_canvasData[(change_2_to_1_index(4,6))] = floatToInt(1.0);
    m_canvasData[(change_2_to_1_index(4,9))] = floatToInt(1.0);

    m_canvasData[(change_2_to_1_index(5,3))] = floatToInt(1.0);
    m_canvasData[(change_2_to_1_index(5,9))] = floatToInt(1.0);

    m_canvasData[(change_2_to_1_index(6,4))] = floatToInt(1.0);
    m_canvasData[(change_2_to_1_index(6,8))] = floatToInt(1.0);

    m_canvasData[(change_2_to_1_index(7,5))] = floatToInt(1.0);
    m_canvasData[(change_2_to_1_index(7,7))] = floatToInt(1.0);

    m_canvasData[(change_2_to_1_index(8,6))] = floatToInt(1.0);

}
