#ifndef LINAL_EINDOPDRACHT_SPACESHIP_H
#define LINAL_EINDOPDRACHT_SPACESHIP_H

#include "object.h"

namespace objects {
    class spaceship : public object {
    public:
        spaceship(view::view& view, const models::point3d& origin);
    };
}

#endif //LINAL_EINDOPDRACHT_SPACESHIP_H
