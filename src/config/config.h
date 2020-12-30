#ifndef LINAL_EINDOPDRACHT_CONFIG_H
#define LINAL_EINDOPDRACHT_CONFIG_H

#include "colour.h"

namespace config {
    static double POINT_DIAMETER = 5;
    static utils::colour POINT_FILL_COLOUR = utils::colours::purple;
    static utils::colour LINE_STROKE_COLOUR = utils::colours::purple;

    static int WINDOW_WIDTH = 1080;
    static int WINDOW_HEIGHT = 720;

    static int ROTATION_DEGREES_PER_KEY_PRESS = 1;
    static int MOVE_STEPS_PER_KEY_PRESS = 1;
}

#endif //LINAL_EINDOPDRACHT_CONFIG_H
