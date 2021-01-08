#ifndef LINAL_EINDOPDRACHT_SPACESHIP_H
#define LINAL_EINDOPDRACHT_SPACESHIP_H

#include "object.h"

namespace models {
    class world; // forward declare
}

namespace objects {
    class spaceship : public object {
        models::world& world_;
    public:
        spaceship(const models::point3d& origin, models::world& world);

        void shoot();
    };
}

#endif //LINAL_EINDOPDRACHT_SPACESHIP_H
