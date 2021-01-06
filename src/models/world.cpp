#include "world.h"

#include <iostream>
#include <algorithm>

#include "pyramid.h"

namespace models {
    world::world()
        :   origin_{0,0,0}, spaceship_{{0,50,0}}
    {
        // Add objects
        addObject(std::make_unique<objects::pyramid>(point3d{0, 0, -500}));
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

    void world::scale(double scale) {
        spaceship_.transform(*std::move(models::matrix::localSpaceScalingMatrix(
            spaceship_.centrum().x(), spaceship_.centrum().y(), spaceship_.centrum().z(),
            scale, scale, scale
        )));

        for (auto& object : objects_) {
            object->transform(*std::move(models::matrix::localSpaceScalingMatrix(
                object->centrum().x(), object->centrum().y(), object->centrum().z(),
                scale, scale, scale
            )));
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