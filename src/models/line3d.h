#ifndef LINAL_EINDOPDRACHT_LINE3D_H
#define LINAL_EINDOPDRACHT_LINE3D_H

#include "point3d.h"

namespace models {
    class line3d {
        point3d start_;
        point3d end_;
    public:
        line3d(const point3d& start, const point3d& end);

        point3d& start();
        point3d& end();

        template<typename T>
        void multiply(T scalar) {
            start_.x(start_.x() * scalar);
            start_.y(start_.y() * scalar);

            end_.x(end_.x() * scalar);
            end_.y(end_.y() * scalar);
        }

        line3d operator +(const line3d& obj) const;
        line3d operator -(const line3d& obj) const;

        void print();
    };
}

#endif //LINAL_EINDOPDRACHT_LINE3D_H
