#include "line3d.h"

namespace models {
    line3d::line3d(const point3d &start, const point3d &end)
        :   start_{start}, end_{end} {}

    point3d & line3d::start() {
        return start_;
    }

    point3d & line3d::end() {
        return end_;
    }

    line3d line3d::operator +(const line3d& obj) const {
        auto startX = start_.x() + obj.start_.x();
        auto startY = start_.y() + obj.start_.y();
        auto startZ = start_.z() + obj.start_.z();

        auto endX = end_.x() + obj.end_.x();
        auto endY = end_.y() + obj.end_.y();
        auto endZ = end_.z() + obj.end_.z();

        return line3d{point3d{startX, startY, startZ}, point3d{endX, endY, endZ}};
    }

    line3d line3d::operator -(const line3d& obj) const {
        auto startX = start_.x() - obj.start_.x();
        auto startY = start_.y() - obj.start_.y();
        auto startZ = start_.z() - obj.start_.z();

        auto endX = end_.x() - obj.end_.x();
        auto endY = end_.y() - obj.end_.y();
        auto endZ = end_.z() - obj.end_.z();

        return line3d{point3d{startX, startY, startZ}, point3d{endX, endY, endZ}};
    }

    void line3d::print() {
        start_.print();
        end_.print();
    }
}