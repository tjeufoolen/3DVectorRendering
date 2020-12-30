#include "world.h"

#include <iostream>

namespace models {
    world::world(view::view& view)
        :   origin_{0,0,0}, view_{view} {}

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

    void world::draw() {
        for (auto& obj : objects_) {
            obj->draw(origin_);
        }
    }

    void world::print() {
        std::cout << "==================================================" << std::endl;
        for (auto& obj : objects_) {
            obj->print();
        }
        std::cout << "==================================================" << std::endl;
    }
}