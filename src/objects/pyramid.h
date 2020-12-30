#ifndef LINAL_EINDOPDRACHT_PYRAMID_H
#define LINAL_EINDOPDRACHT_PYRAMID_H

#include "object.h"

namespace objects {
    class pyramid : public object {
    public:
        pyramid(view::view& view, const models::point3d& origin);
    };
}

#endif //LINAL_EINDOPDRACHT_PYRAMID_H
