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
        for (auto& obj : world_.objects()) {
            auto worldOrigin { world_.origin() };
            auto origin { obj->origin() };

            // draw lines
            for (auto& line : obj->lines()) {
                // calculate world and object origin
                double ox { worldOrigin.x() + origin.x() };
                double oy { worldOrigin.y() + (origin.y() *-1) }; // (*-1) y should be flipped

                // draw around origin
                double bx { ox + line.begin().x() };
                double by { oy + (line.begin().y() *-1) }; // (*-1) y should be flipped
                double ex { ox + line.end().x() };
                double ey { oy + (line.end().y() *-1) }; // (*-1) y should be flipped

                view_.renderLine(bx, by, ex, ey, config::LINE_STROKE_COLOUR);
                view_.renderCircle(bx, by, config::POINT_DIAMETER, config::POINT_FILL_COLOUR);
                view_.renderCircle(ex, ey, config::POINT_DIAMETER, config::POINT_FILL_COLOUR);
            }
        }
    }
}