#ifndef CPP_3DVECTORRENDERING_WORLD_H
#define CPP_3DVECTORRENDERING_WORLD_H

#include <map>
#include <vector>
#include <memory>

#include "view.h"
#include "object.h"
#include "point3d.h"
#include "spaceship.h"

namespace models {
    class world {
        point3d origin_;
        std::vector<std::unique_ptr<objects::object>> objects_;
        std::unique_ptr<objects::spaceship> spaceship_;
    public:
        world(const models::point3d& origin = {0,0,0,0});

        std::vector<std::unique_ptr<objects::object>>& objects();
        void addObject(std::unique_ptr<objects::object> obj);

        void scale(double scale);

        objects::spaceship& spaceship();
        void spaceship(std::unique_ptr<objects::spaceship> spaceship);

        point3d origin() const;
        void origin(double x, double y, double z);

        void print();
    };
}

#endif //CPP_3DVECTORRENDERING_WORLD_H
