#ifndef LINAL_EINDOPDRACHT_PLANET_H
#define LINAL_EINDOPDRACHT_PLANET_H

#include "object.h"

namespace objects {
    class planet : public object {
    public:
        planet(const models::point3d& origin);
    };
}

#endif //LINAL_EINDOPDRACHT_PLANET_H
