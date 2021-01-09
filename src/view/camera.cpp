#include "camera.h"

#include "config.h"

namespace view {
    camera::camera(view& view, models::world &world, const models::point3d& origin, double xDrawOffset, double yDrawOffset)
        :   view_{view}, world_{world}, origin_{origin}, xDrawOffset_{xDrawOffset}, yDrawOffset_{yDrawOffset} {}

    void camera::origin(double x, double y, double z) {
        origin_.x(x);
        origin_.y(y);
        origin_.z(z);
    }

    models::point3d & camera::origin() {
        return origin_;
    }

    void camera::draw() {
        if (world_.spaceship().isAlive()) {
            // create a copy of the object so that we can execute our draw operations on it
            objects::object spaceship { world_.spaceship() };

            // draw spaceship
            drawObject(spaceship);
        }

        // draw objects
        for (auto& obj_ptr : world_.objects()) {
            obj_ptr->animate();
            objects::object obj { *obj_ptr }; // create a copy, so that we can keep the actual values
            drawObject(obj);
        }

        // check if spaceship collides with any of the objects
        if (world_.spaceship().isAlive()) {
            for (auto& obj_ptr : world_.objects()) {
                if (world_.spaceship().collides(*obj_ptr)) {
                    world_.spaceship().onCollision(*obj_ptr);
                }
            }
        }

        // check if objects collide with each other
        for (auto& obj_ptr : world_.objects()) {
            for (auto& other_ptr : world_.objects()) {
                if (obj_ptr->id() == other_ptr->id()) continue;

                if (obj_ptr->collides(*other_ptr)) {
                    obj_ptr->onCollision(*other_ptr);
                }
            }
        }
    }

    void camera::drawObject(objects::object& obj) {
        auto cameraTransformationMatrix { *std::move(transformationMatrix()) };
        obj.origin().transform(cameraTransformationMatrix);
        obj.transform(cameraTransformationMatrix);

        // calculate base origin
        const auto origin { camera::origin() + world_.origin() + obj.origin() };

        // draw lines
        for (auto line : obj.lines()) {
            // draw around origin
            double bx { line.begin().x() };
            double by { line.begin().y() };
            double ex { line.end().x() };
            double ey { line.end().y() };

            // add origin
            bx += origin.x(), ex += origin.x();
            by += origin.y(), ey += origin.y();

            // flip y axis
            by *= -1, ey *= -1;

            // add screen offset (position to render on screen)
            bx += xDrawOffset_, ex += xDrawOffset_;
            by += yDrawOffset_, ey += yDrawOffset_;

            view_.renderLine(bx, by, ex, ey, line.colour());
            if (config::DRAW_POINTS) {
                view_.renderCircle(bx, by, config::POINT_DIAMETER, config::POINT_FILL_COLOUR);
                view_.renderCircle(ex, ey, config::POINT_DIAMETER, config::POINT_FILL_COLOUR);
            }
        }

        // draw origin dot (useful for debug purposes)
        view_.renderCircle(origin.x() + xDrawOffset_, origin.y() * -1 + yDrawOffset_, config::ORIGIN_POINT_DIAMETER, config::ORIGIN_POINT_FILL_COLOUR);
    }

    models::point3d camera::direction() const {
        const models::point3d eye { origin_ };
        const models::point3d lookAt { 0,0, 0 };

        return { eye - lookAt };
    }

    models::matrix_ptr camera::transformationMatrix() {
        // 1. Calculate direction vector and normalize
        models::point3d direction { camera::direction() };
        direction.normalize();

        // 2. Calculate right vector with cross product from up- and direction-vector, normalize after
        models::point3d right { models::point3d{ 0,1,0,1 }.crossProduct(direction) };
        right.normalize();

        // 3. Calculate up vector with cross product from direction- and right- vector, normalize after
        models::point3d up { direction.crossProduct(right) };
        up.normalize();

        // 4. Combine matrices and return
        auto translation { *std::move(models::matrix::inverseMatrix(right, up, direction)) };
        auto cameraToOrigin { *std::move(models::matrix::translationMatrix(-origin_.x(), -origin_.y(), -origin_.z())) };

        return std::move(models::matrix::multiply(translation, cameraToOrigin));
    }
}