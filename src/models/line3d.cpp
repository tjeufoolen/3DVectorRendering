#include "line3d.h"

#include <iostream>

namespace models {
    line3d::line3d(const point3d &begin, const point3d &end, const utils::colour& colour)
        : begin_{begin}, end_{end}, colour_{colour} {}

    point3d& line3d::begin() {
        return begin_;
    }

    point3d line3d::begin() const {
        return begin_;
    }

    point3d& line3d::end() {
        return end_;
    }

    point3d line3d::end() const {
        return end_;
    }

    line3d line3d::operator +(const line3d& obj) const {
        auto startX = begin_.x() + obj.begin_.x();
        auto startY = begin_.y() + obj.begin_.y();
        auto startZ = begin_.z() + obj.begin_.z();

        auto endX = end_.x() + obj.end_.x();
        auto endY = end_.y() + obj.end_.y();
        auto endZ = end_.z() + obj.end_.z();

        return line3d{point3d{startX, startY, startZ}, point3d{endX, endY, endZ}};
    }

    line3d line3d::operator -(const line3d& obj) const {
        auto startX = begin_.x() - obj.begin_.x();
        auto startY = begin_.y() - obj.begin_.y();
        auto startZ = begin_.z() - obj.begin_.z();

        auto endX = end_.x() - obj.end_.x();
        auto endY = end_.y() - obj.end_.y();
        auto endZ = end_.z() - obj.end_.z();

        return line3d{point3d{startX, startY, startZ}, point3d{endX, endY, endZ}};
    }

    utils::colour & line3d::colour() {
        return colour_;
    }

    void line3d::print() {
        std::cout << "line: [x" << begin().x() << ",y" << begin().y() << ",z" << begin().z() << "] -> [x" << end().x() << ",y" << end().y() << ",z" << end().z() << "]" << "\n";
    }
}