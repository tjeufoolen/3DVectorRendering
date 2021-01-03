#include "object.h"

#include <iostream>
#include <algorithm>

namespace objects {
    object::object(const models::point3d& origin)
        :   origin_{origin} {}

    void object::transform(const models::Matrix &m) {
        for (auto &line : lines_) {
            line.begin().transform(m);
            line.end().transform(m);
        }
    }

    void object::addLine(models::line3d line) {
        lines_.emplace_back(line);
    }

    std::vector<models::line3d> & object::lines() {
        return lines_;
    }

    models::point3d object::origin() {
        return origin_;
    }

    void object::origin(double x, double y, double z) {
        origin_.x(x);
        origin_.y(y);
        origin_.z(z);
    }

    void object::print() {
        std::for_each(lines_.begin(), lines_.end(), [](auto& line){ line.print(); });
    }
}