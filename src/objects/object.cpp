#include "object.h"

#include <iostream>
#include <algorithm>

namespace objects {
    object::object(const models::point3d& origin, bool showAxis)
        :   origin_{origin},
            heading_{0,0,1}
    {
        if (showAxis) {
            addLine({models::point3d{0,0,0}, models::point3d{50,0,0}, config::X_AXIS_COLOUR});
            addLine({models::point3d{0,0,0}, models::point3d{0,50,0}, config::Y_AXIS_COLOUR});
            addLine({models::point3d{0,0,0}, models::point3d{0,0,50}, config::Z_AXIS_COLOUR});
        }
    }

    void object::transform(const models::Matrix &m) {
        for (auto &line : lines_) {
            line.begin().transform(m);
            line.end().transform(m);
        }

        heading_.transform(m);
    }

    models::line3d& object::addLine(models::line3d line) {
        return lines_.emplace_back(line);
    }

    std::vector<models::line3d>& object::lines() {
        return lines_;
    }

    void object::origin(double x, double y, double z) {
        origin_.x(x);
        origin_.y(y);
        origin_.z(z);
    }

    models::point3d object::origin() const {
        return origin_;
    }

    models::point3d& object::origin() {
        return origin_;
    }

    const models::point3d & object::heading() const {
        return heading_;
    }

    models::point3d object::centrum() const {
        double xTotal{0}, yTotal{0}, zTotal{0};
        auto points { lines_.size() * 2 }; // every line has 2 points

        for (auto& line : lines_) {
            auto begin { line.begin() };
            auto end   { line.end()   };

            xTotal += begin.x() + end.x();
            yTotal += begin.y() + end.y();
            zTotal += begin.z() + end.z();
        }

        return {
            xTotal / points,
            yTotal / points,
            zTotal / points
        };
    }

    bool object::discard() {
        return discard_;
    }

    void object::print() {
        std::for_each(lines_.begin(), lines_.end(), [](auto& line){ line.print(); });
    }
}