#ifndef LINAL_EINDOPDRACHT_OBJECT_H
#define LINAL_EINDOPDRACHT_OBJECT_H

#include <vector>

#include "models/matrix.h"
#include "models/line3d.h"

namespace objects {
    struct object {
        object();

        void transform(models::Matrix& m);

        std::vector<models::line3d>& lines();
        std::vector<models::point3d*>& points();

        models::point3d origin();
        void origin(double x, double y, double z);
    protected:
        void addLine(models::line3d line);
    private:
        std::vector<models::line3d> lines_;
        std::vector<models::point3d*> points_;

        models::point3d origin_ = {0,0,0};
    };
}

#endif //LINAL_EINDOPDRACHT_OBJECT_H
