#include "bullet.h"

#include <iostream>

namespace objects {
    bullet::bullet(const models::point3d& origin, const objects::spaceship& spaceship)
        :   spaceship_{spaceship}, zOffset_{225}, object(origin, false)
    {
        double length { 20 };

        models::point3d a { 0, 0, zOffset_ - (length/2), 0 };
        models::point3d b { 0, 0, zOffset_ + (length/2), 0 };

        addLine({a, b, config::BULLET_COLOUR});
    }

    void bullet::animate()
    {
        if (!discard_) {
            // simple check if bullet is too far away, if it is safe memory space by removing it
            if (origin().z() > 1000) {
                discard_ = true;
            } else {
                origin().transform(*std::move(models::matrix::translationMatrix(0,0,config::BULLET_SPEED)));
            }
        }
    }
}