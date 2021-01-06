#include "camera.h"

#include "config.h"

namespace view {
    camera::camera(view& view, models::world &world, const models::point3d& origin)
        :   view_{view}, world_{world}, origin_{origin} {}

    void camera::origin(double x, double y, double z) {
        origin_.x(x);
        origin_.y(y);
        origin_.z(z);
    }

    void camera::draw() {
        drawObject(world_.spaceship());

        for (auto& obj : world_.objects()) {
            drawObject(*obj);
        }

        // draw yellow dot at world origin
        view_.renderCircle(world_.origin().x(), world_.origin().y(), 5,utils::colours::yellow);
    }

    void camera::drawObject(objects::object& obj) {
        const auto& worldOrigin { world_.origin() };
        const auto& objOrigin { obj.origin() };

        // calculate world and object origin
        double ox { worldOrigin.x() + objOrigin.x() };
        double oy { worldOrigin.y() + objOrigin.y() * -1 };

        // draw lines
        for (auto& line : obj.lines()) {
            // draw around origin
            double bx { ox + line.begin().x() };
            double by { oy + line.begin().y() * -1 };
            double ex { ox + line.end().x() };
            double ey { oy + line.end().y() * -1 };

            view_.renderLine(bx, by, ex, ey, config::LINE_STROKE_COLOUR);
            view_.renderCircle(bx, by, config::POINT_DIAMETER, config::POINT_FILL_COLOUR);
            view_.renderCircle(ex, ey, config::POINT_DIAMETER, config::POINT_FILL_COLOUR);
        }

        // draw white dot at obj origin
        view_.renderCircle(ox, oy, 5,utils::colours::white);
    }
}