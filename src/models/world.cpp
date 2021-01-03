#include "world.h"

#include <iostream>
#include <algorithm>

namespace models {
    world::world()
        :   origin_{0,0,0} {}

    std::vector<std::unique_ptr<objects::object>> & world::objects() {
        return objects_;
    }

    void world::addObject(std::unique_ptr<objects::object> obj) {
        objects_.emplace_back(std::move(obj));
    }

    void world::transformObjects(const models::Matrix &m) {
        for (auto& object : objects_) {
            object->transform(m);
        }
    }

    point3d world::origin() const {
        return origin_;
    }

    void world::origin(double x, double y, double z) {
        origin_.x(x);
        origin_.y(y);
        origin_.z(z);
    }

    void world::print() {
        std::cout << "====================== WORLD ======================" << "\n";
        std::for_each(objects_.begin(), objects_.end(), [](auto& obj){ obj->print(); });
        std::cout << "==================================================" << "\n";
    }
}