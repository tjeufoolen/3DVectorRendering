#include "world.h"

namespace models {
    std::vector<objects::object *> world::objects() {
        return objects_;
    }

    void world::addObject(objects::object &obj) {
        objects_.push_back(&obj);
    }

    point3d world::origin() {
        return origin_;
    }

    void world::origin(double x, double y, double z) {
        origin_.x(x);
        origin_.y(y);
        origin_.z(z);
    }
}