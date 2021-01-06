#include "world.h"

#include <iostream>
#include <algorithm>

#include "cube.h"
#include "pyramid.h"

namespace models {
    world::world()
        :   origin_{0,0,0}, spaceship_{{0,100,0}}
    {
        // Add objects
//        addObject(std::make_unique<objects::cube>(point3d{0, 100, -300}));
        addObject(std::make_unique<objects::pyramid>(point3d{0, 0, 0}));
    }

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

    objects::spaceship& world::spaceship() {
        return spaceship_;
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