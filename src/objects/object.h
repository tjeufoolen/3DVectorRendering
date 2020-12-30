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
        view::view& view_;
    public:
        object(view::view& view, const models::point3d& origin = {0, 0, 0});

        void transform(const models::Matrix& m);

        std::vector<models::line3d>& lines();

        models::point3d origin();
        void origin(double x, double y, double z);

        void draw(const models::point3d& worldOrigin);

        void print();
    protected:
        void addLine(models::line3d line);
    };
}

#endif //LINAL_EINDOPDRACHT_OBJECT_H
