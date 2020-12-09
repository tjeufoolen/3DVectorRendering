#ifndef LINAL_EINDOPDRACHT_WORLD_H
#define LINAL_EINDOPDRACHT_WORLD_H

#include <vector>

#include "point3d.h"
#include "objects/object.h"

namespace models {
    class world {
        std::vector<objects::object*> objects();
        void addObject(objects::object& obj);

        point3d origin();
        void origin(double x, double y, double z);
    private:
        point3d origin_ = {0,0,0};
        std::vector<objects::object*> objects_;
    };
}

#endif //LINAL_EINDOPDRACHT_WORLD_H
