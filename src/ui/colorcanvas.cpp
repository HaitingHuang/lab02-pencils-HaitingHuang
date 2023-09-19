#include "colorcanvas.h"
#include "RGBA.h"

void ColorCanvas::initializeColorCanvas() {

    // Task 6: initialize a 10 x 10 colorful canvas where each pixel has an
    //         RGBA value of (0, 123, 123, 255)

    // Task 8: call the drawFlower() function to display the canvas with
    //         a couple of flowers

    // Task 7: uncomment this function
//    testPosToIndex();
}

void ColorCanvas::testPosToIndex() {
    // posToIndex() visual tester
    m_canvasData.at(posToIndex(0,0)) = RGBA{255, 0, 0};
    m_canvasData.at(posToIndex(0,5)) = RGBA{0, 255, 0};
    m_canvasData.at(posToIndex(3,5)) = RGBA{0, 0, 255};
}

int ColorCanvas::posToIndex(int x, int y) {
    // Task 7: debug this function so that it converts an (x, y) position
    //         into an index you can use to index into the array of canvas data.

    int index = x * 10 + y;
    return index;
}

void ColorCanvas::drawFlower(int x, int y) {
    // Task 8: draw flowers on your canvas. The inputs of this function are
    //         the x and y coordinates of the center of the flower
}

void ColorCanvas::mouseDown(int x, int y) {
    // Task 10: update the variable that keeps track of whether the LMB is being
    //          held down, then color the pixel corresponding to the input (x, y)
    //          coordinate, if within canvas bounds
}

void ColorCanvas::mouseMove(int x, int y) {
    // Task 9: color the pixel corresponding to the input (x, y) coordinate, if
    //         within canvas bounds

    // Task 10: update this function from the previous task so that the coloring
    //          of the canvas only happens if the LMB is being held down
}

void ColorCanvas::mouseUp(int x, int y) {
    // Task 10: update the variable that keeps track of whether the LMB is being
    //          held down
}
