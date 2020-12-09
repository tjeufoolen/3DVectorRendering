#include "object.h"

namespace objects {
    object::object() = default;

    void object::transform(models::Matrix &m) {
        for (auto &line : lines_) {
            line.start().transform(m);
            line.end().transform(m);
        }
    }

    void object::addLine(models::line3d line) {
        lines_.emplace_back(line);

        points_.push_back(&line.start());
        points_.push_back(&line.end());
    }

    std::vector<models::line3d> & object::lines() {
        return lines_;
    }

    std::vector<models::point3d*>& object::points() {
        return points_;
    }

    models::point3d object::origin() {
        return origin_;
    }

    void object::origin(double x, double y, double z) {
        origin_.x(x);
        origin_.y(y);
        origin_.z(z);
    }
}