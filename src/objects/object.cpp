#include "object.h"

#include <iostream>

#include "config.h"

namespace objects {
    object::object(view::view& view, const models::point3d& origin)
        :   view_{view}, origin_{origin} {}

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

    void object::draw(const models::point3d& worldOrigin) {
        auto objOrigin = origin();

        // draw lines
        for (auto& line : lines_) {
            // calculate world and object origin
            double ox = worldOrigin.x() + objOrigin.x();
            double oy = worldOrigin.y() + (objOrigin.y() *-1); // (*-1) y should be flipped

            // draw around origin
            double bx = ox + line.begin().x();
            double by = oy + (line.begin().y() *-1); // (*-1) y should be flipped
            double ex = ox + line.end().x();
            double ey = oy + (line.end().y() *-1); // (*-1) y should be flipped

            view_.renderLine(bx, by, ex, ey, config::LINE_STROKE_COLOUR);
//            view_.renderCircle(bx, by, config::POINT_DIAMETER, config::POINT_FILL_COLOUR);
//            view_.renderCircle(ex, ey, config::POINT_DIAMETER, config::POINT_FILL_COLOUR);
        }
    }

    void object::print() {
        for (auto& line : lines_) {
            line.print();
        }
    }
}