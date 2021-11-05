#ifndef CPP_3DVECTORRENDERING_LINE3D_H
#define CPP_3DVECTORRENDERING_LINE3D_H

#include "point3d.h"
#include "colour.h"
#include "config.h"

namespace models {
    class line3d {
        point3d begin_;
        point3d end_;

        utils::colour colour_;
    public:
        line3d(const point3d& begin, const point3d& end, const utils::colour& colour = config::LINE_STROKE_COLOUR);

        point3d& begin();
        point3d begin() const;

        point3d& end();
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

        utils::colour& colour();

        void print();
    };
}

#endif //CPP_3DVECTORRENDERING_LINE3D_H
