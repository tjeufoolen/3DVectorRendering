#include "point3d.h"

#include <iostream>

namespace models {
    point3d::point3d(double x, double y, double z, double w)
        : x_{x}, y_{y}, z_{z}, w_{w} {}

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

    double point3d::w() const {
        return w_;
    }

    void point3d::w(double v) {
        w_ = v;
    }

    double point3d::dotProduct(const point3d &other) const {
        return x_ * other.x() + y_ * other.y() + z_ * other.z();
    }

    point3d point3d::crossProduct(const point3d &other) const {
        double x = y_ * other.z() - z_ * other.y();
        double y = z_ * other.x() - x_ * other.z();
        double z = x_ * other.y() - y_ * other.x();

        return point3d{x, y, z};
    }

    void point3d::normalize() {
        double length = sqrt(x_*x_ + y_*y_ + z_*z_);

        x(x_ / length);
        y(y_ / length);
        z(z_ / length);
    }

    point3d point3d::operator+(const point3d& other) const {
        return {
            x_ + other.x(),
            y_ + other.y(),
            z_ + other.z(),
            w_ + other.w()
        };
    }

    point3d point3d::operator-(const point3d& other) const {
        return {
            x_ - other.x(),
            y_ - other.y(),
            z_ - other.z(),
            w_ - other.w()
        };
    }

    void point3d::transform(const Matrix &m) {
        // important: safe a copy of the actual values to do multiplications on
        double x = x_, y = y_, z = z_, w = w_;

        x_ = m[0][0] * x + m[0][1] * y + m[0][2] * z + m[0][3] * w;
        y_ = m[1][0] * x + m[1][1] * y + m[1][2] * z + m[1][3] * w;
        z_ = m[2][0] * x + m[2][1] * y + m[2][2] * z + m[2][3] * w;
        w_ = m[3][0] * x + m[3][1] * y + m[3][2] * z + m[3][3] * w;
    }

    std::unique_ptr<point3d> point3d::getPerspectiveCoordinate(const models::Matrix& m) const {
        point3d point{x_, y_, z_};
        point.transform(m);
        return std::make_unique<point3d>(point);
    }

    void point3d::print() const {
        std::cout << "[point]: x" << x_ << ", y" << y_ << ", z" << z_ << ", w" << w_ << "\n";
    }
}