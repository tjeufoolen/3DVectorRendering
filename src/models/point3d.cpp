#include "point3d.h"

#include <iostream>

namespace models {
    point3d::point3d(double x, double y, double z)
        : x_{x}, y_{y}, z_{z} {}

    double point3d::x() const {
        return x_;
    }

    void point3d::x(double v) {
        x_ = v;
    }

    double point3d::y() const {
        return y_;
    }

    void point3d::y(double v) {
        y_ = v;
    }

    double point3d::z() const {
        return z_;
    }

    void point3d::z(double v) {
        z_ = v;
    }

    void point3d::transform(Matrix &m) {
        x_ = m[0][0] * x_ + m[0][1] * y_ + m[0][2] * z_ + m[0][3] * w_;
        y_ = m[1][0] * x_ + m[1][1] * y_ + m[1][2] * z_ + m[1][3] * w_;
        z_ = m[2][0] * x_ + m[2][1] * y_ + m[2][2] * z_ + m[2][3] * w_;
        w_ = m[3][0] * x_ + m[3][1] * y_ + m[3][2] * z_ + m[3][3] * w_;
    }

    void point3d::print() const {
        std::cout << "[point]: x" << x_ << ", y" << y_ << ", z" << z_ << "\n";
    }
}