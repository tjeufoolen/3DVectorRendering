#ifndef LINAL_EINDOPDRACHT_LINE3D_H
#define LINAL_EINDOPDRACHT_LINE3D_H

#include "point3d.h"

namespace models {
    class line3d {
        point3d begin_;
        point3d end_;
    public:
        line3d(const point3d& begin, const point3d& end);

        point3d& begin();
        point3d& end();

        point3d begin() const;
        point3d end() const;

        template<typename T>
        void multiply(T scalar) {
            begin_.x(begin_.x() * scalar);
            begin_.y(begin_.y() * scalar);

            end_.x(end_.x() * scalar);
            end_.y(end_.y() * scalar);
        }

        line3d operator +(const line3d& obj) const;
        line3d operator -(const line3d& obj) const;

        void print();
    };
}

#endif //LINAL_EINDOPDRACHT_LINE3D_H
