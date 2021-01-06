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

    void camera::transform(models::Matrix& m) {
        origin_.transform(m);
    }

    void camera::draw() {
        auto m { *std::move(translationMatrix()) };

        // create a copy of the object so that we can execute our draw operations on it
        objects::object spaceship { world_.spaceship() };
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

        // draw yellow dot at world origin
        view_.renderCircle(world_.origin().x(), world_.origin().y(), 5, utils::colours::yellow);
//        view_.renderCircle(origin().x() + world_.origin().x(), origin().y() + world_.origin().y(), 5, utils::colours::yellow);
    }

    void camera::drawObject(objects::object& obj) {
        const auto& origin { world_.origin() };
//        const auto& origin { camera::origin() };
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

            view_.renderLine(bx, by, ex, ey, line.colour());
            view_.renderCircle(bx, by, config::POINT_DIAMETER, config::POINT_FILL_COLOUR);
            view_.renderCircle(ex, ey, config::POINT_DIAMETER, config::POINT_FILL_COLOUR);
        }

        // draw white dot at obj origin
        view_.renderCircle(ox, oy, 5, utils::colours::white);
    }

    models::point3d camera::direction() const {
        const models::point3d eye { origin_ };
        const models::point3d lookAt { 0,0, 0 };

        return { eye - lookAt };
    }

    models::matrix_ptr camera::translationMatrix() {
        // 1. Bepaal de direction-vector en normaliseer deze.
        models::point3d direction { camera::direction() };
        direction.normalize();

        // 2. Bepaal de right-vector met het uitproduct van de up- en direction-vector, normaliseer deze vector.
        models::point3d right { models::point3d{ 0,1,0,1 }.crossProduct(direction) };
        right.normalize();

        // 3. Bepaal de up-vector met het uitproduct van de direction- en de right-vector, normaliseer deze vector.
        models::point3d up = direction.crossProduct(right);
        up.normalize();

        // 4. Zet ze op de juiste manier in de transformatiematrix.
        auto translation { *std::move(models::matrix::inverseMatrix(right, up, direction)) };

        // Om het geheel compleet te maken moeten we de camera natuurlijk eerst naar de oorsprong transleren
        auto cameraToOrigin { *std::move(models::matrix::translationMatrix(-origin_.x(), -origin_.y(), -origin_.z())) };

        return std::move(models::matrix::multiply(translation, cameraToOrigin));
    }
}