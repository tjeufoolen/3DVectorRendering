#include "bullet.h"

#include "spaceship.h"

namespace objects {
    bullet::bullet(const models::point3d& origin, const objects::spaceship& spaceship)
        :   spaceship_{spaceship}, zOffset_{0}, object(origin, true)
    {
        double length { 20 };

        models::point3d begin { 0, 0, zOffset_ - (length/2), 0 };
        models::point3d end { 0, 0, zOffset_ + (length/2), 0 };
        addLine({begin, end, config::BULLET_COLOUR});

        // rotate origin
//        auto hx { spaceship.heading().x() };
//        auto hy { spaceship.heading().y() };
//        auto hz { spaceship.heading().z() };
//        auto a {*std::move(models::matrix::randomAxisRotationMatrixToXYSpace(hx, hz)) };
//        auto b {*std::move(models::matrix::randomAxisRotationMatrixToXAxis(hx, hy, hz)) };
//        auto m {*std::move(models::matrix::multiply(a, b))};
//        transform(m);
//        origin_.transform(m);
    }

    void bullet::animate()
    {
        if (!discard_) {
            // simple check if bullet is too far away, if it is safe memory space by removing it
            if (origin_.z() > 1000) {
                discard_ = true;
            } else {
                origin_.transform(*std::move(models::matrix::translationMatrix(0,0,config::BULLET_SPEED)));
            }
        }
    }
}