#ifndef CPP_3DVECTORRENDERING_CONFIG_H
#define CPP_3DVECTORRENDERING_CONFIG_H

#include "colour.h"

namespace config {
    static bool DRAW_POINTS { false };

    static double POINT_DIAMETER { 2 };
    static double ORIGIN_POINT_DIAMETER { 5 };
    static utils::colour ORIGIN_POINT_FILL_COLOUR { utils::colours::yellow };
    static utils::colour POINT_FILL_COLOUR { utils::colours::grey };
    static utils::colour LINE_STROKE_COLOUR { utils::colours::grey };
    static utils::colour BULLET_COLOUR { utils::colours::yellow };

    static int WINDOW_WIDTH { 1080 };
    static int WINDOW_HEIGHT { 720 };

    static int ROTATION_DEGREES_PER_KEY_PRESS { 5 };
    static int MOVE_STEPS_PER_KEY_PRESS { 10 };
    static double UP_SCALE_STEPS_PER_KEY_PRESS { 1.5 };
    static double DOWN_SCALE_STEPS_PER_KEY_PRESS { .5 };
    static double BULLET_SPEED { 50 };

    static utils::colour Y_AXIS_COLOUR { utils::colours::blue };
    static utils::colour X_AXIS_COLOUR { utils::colours::red };
    static utils::colour Z_AXIS_COLOUR { utils::colours::green };
}

#endif //CPP_3DVECTORRENDERING_CONFIG_H
