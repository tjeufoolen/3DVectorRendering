#ifndef CPP_3DVECTORRENDERING_CUBE_H
#define CPP_3DVECTORRENDERING_CUBE_H

#include "object.h"

namespace objects {
    class cube : public object {
    public:
        cube(const models::point3d& origin);
    };
}

#endif //CPP_3DVECTORRENDERING_CUBE_H
