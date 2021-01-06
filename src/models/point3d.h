#ifndef LINAL_EINDOPDRACHT_POINT3D_H
#define LINAL_EINDOPDRACHT_POINT3D_H

#include "matrix.h"

namespace models {
    class point3d {
        double x_;
        double y_;
        double z_;
        double w_;
    public:
        point3d(double x=0, double y=0, double z=0, double w=1);

        void x(double v);
        double x() const;
        void y(double v);
        double y() const;
        void z(double v);
        double z() const;
        void w(double w);
        double w() const;

        double dotProduct(const point3d& other) const;
        point3d crossProduct(const point3d& other) const;

        point3d operator+(const point3d& other) const;

        void transform(const Matrix& m);
        std::unique_ptr<point3d> getPerspectiveCoordinate(const models::Matrix& m) const;

        void print() const;
    };
}

#endif //LINAL_EINDOPDRACHT_POINT3D_H
