#ifndef LINAL_EINDOPDRACHT_CUBE_H
#define LINAL_EINDOPDRACHT_CUBE_H

#include "object.h"

namespace objects {
    class cube : public object {
    public:
        cube(const models::point3d& origin);
    };
}

#endif //LINAL_EINDOPDRACHT_CUBE_H
