#ifndef LINAL_EINDOPDRACHT_WORLD_H
#define LINAL_EINDOPDRACHT_WORLD_H

#include <map>
#include <vector>
#include <memory>

#include "view.h"
#include "object.h"
#include "point3d.h"

namespace models {
    class world {
        point3d origin_ = {0, 0, 0};
        std::vector<std::unique_ptr<objects::object>> objects_;
        view::view& view_;
    public:
        world(view::view& view);

        void addObject(std::unique_ptr<objects::object> obj);
        void transformObjects(const models::Matrix& m);

        point3d origin() const;
        void origin(double x, double y, double z);

        void draw();

        void print();
    };
}

#endif //LINAL_EINDOPDRACHT_WORLD_H
