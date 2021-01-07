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

    models::point3d & camera::origin() {
        return origin_;
    }

    void camera::draw() {
        auto m { *std::move(translationMatrix()) };

        // create a copy of the object so that we can execute our draw operations on it
        objects::object spaceship { world_.spaceship() };

        spaceship.origin().print();

        spaceship.transform(m);

        // draw spaceship
        drawObject(spaceship);

        // draw objects
        for (auto& obj_ptr : world_.objects()) {
            obj_ptr->animate();

            // create a copy of the object so that we can execute our draw operations on it
            objects::object obj { *obj_ptr };
            obj.transform(m);

            drawObject(obj);
        }
    }

    void camera::drawObject(objects::object& obj) {
        const auto& origin { camera::origin() };
        const auto& objOrigin { obj.origin() };

        // calculate world and object origin
        double ox { origin.x() + objOrigin.x() };
        double oy { origin.y() + objOrigin.y() * -1 };

        // draw lines
        for (auto& line : obj.lines()) {
            // draw around origin
            double bx { ox + line.begin().x() };
            double by { oy + line.begin().y() * -1 };
            double ex { ox + line.end().x() };
            double ey { oy + line.end().y() * -1 };

            // add screen center
            bx += config::WINDOW_WIDTH  / 2.0;
            by += config::WINDOW_HEIGHT / 2.0;
            ex += config::WINDOW_WIDTH / 2.0;
            ey += config::WINDOW_HEIGHT / 2.0;

            view_.renderLine(bx, by, ex, ey, line.colour());
            view_.renderCircle(bx, by, config::POINT_DIAMETER, config::POINT_FILL_COLOUR);
            view_.renderCircle(ex, ey, config::POINT_DIAMETER, config::POINT_FILL_COLOUR);
        }
    }

    models::point3d camera::direction() const {
        const models::point3d eye { origin_ };
        const models::point3d lookAt { 0,0, 0 };

        return { eye - lookAt };
    }

    models::matrix_ptr camera::translationMatrix() {
        // 1. Calculate direction vector and normalize
        models::point3d direction { camera::direction() };
        direction.normalize();

        // 2. Calculate right vector with cross product from up- and direction-vector, normalize after
        models::point3d right { models::point3d{ 0,1,0,1 }.crossProduct(direction) };
        right.normalize();

        // 3. Calculate up vector with cross product from direction- and right- vector, normalize after
        models::point3d up = direction.crossProduct(right);
        up.normalize();

        // 4. Combine matrices and return
        auto translation { *std::move(models::matrix::inverseMatrix(right, up, direction)) };
        auto cameraToOrigin { *std::move(models::matrix::translationMatrix(-origin_.x(), -origin_.y(), -origin_.z())) };

        return std::move(models::matrix::multiply(translation, cameraToOrigin));
    }
}