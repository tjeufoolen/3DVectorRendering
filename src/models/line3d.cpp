#include "line3d.h"

namespace models {
    line3d::line3d(const point3d &begin, const point3d &end)
        : begin_{begin}, end_{end} {}

    point3d & line3d::begin() {
        return begin_;
    }

    point3d & line3d::end() {
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

    void line3d::print() {
        begin_.print();
        end_.print();
    }
}