#ifndef LINAL_EINDOPDRACHT_CONFIG_H
#define LINAL_EINDOPDRACHT_CONFIG_H

#include "colour.h"

namespace config {
    static double POINT_DIAMETER { 2 };
    static utils::colour POINT_FILL_COLOUR { utils::colours::grey };
    static utils::colour LINE_STROKE_COLOUR { utils::colours::grey };

    static int WINDOW_WIDTH { 1080 };
    static int WINDOW_HEIGHT { 720 };

    static int ROTATION_DEGREES_PER_KEY_PRESS { 2 };
    static int MOVE_STEPS_PER_KEY_PRESS { 5 };
    static double UP_SCALE_STEPS_PER_KEY_PRESS { 1.5 };
    static double DOWN_SCALE_STEPS_PER_KEY_PRESS { .5 };

    static utils::colour Y_AXIS_COLOUR { utils::colours::blue };
    static utils::colour X_AXIS_COLOUR { utils::colours::red };
    static utils::colour Z_AXIS_COLOUR { utils::colours::green };
}

#endif //LINAL_EINDOPDRACHT_CONFIG_H
