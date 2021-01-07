#ifndef LINAL_EINDOPDRACHT_OBJECT_H
#define LINAL_EINDOPDRACHT_OBJECT_H

#include <vector>

#include "matrix.h"
#include "line3d.h"
#include "view.h"

namespace models {
    class world; // forward declare
}

namespace objects {
    class object {
        std::vector<models::line3d> lines_;
        models::point3d origin_;
    public:
        object(const models::point3d& origin = {0, 0, 0});

        void transform(const models::Matrix& m);

        std::vector<models::line3d>& lines();

        void origin(double x, double y, double z);
        models::point3d origin() const;
        models::point3d& origin();

        models::point3d centrum() const;

        virtual void animate() {}; // runs every game loop

        void print();
    protected:
        void addLine(models::line3d line);
    };
}

#endif //LINAL_EINDOPDRACHT_OBJECT_H
