#ifndef CPP_3DVECTORRENDERING_POINT3D_H
#define CPP_3DVECTORRENDERING_POINT3D_H

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

        void normalize();

        point3d operator+(const point3d& other) const;
        point3d operator-(const point3d& other) const;
        bool operator==(const point3d &rhs) const;

        void transform(const Matrix& m);

        void print() const;
    };
}

#endif //CPP_3DVECTORRENDERING_POINT3D_H
