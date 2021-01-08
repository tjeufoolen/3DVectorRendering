#include "bullet.h"

#include "spaceship.h"

namespace objects {
    bullet::bullet(const models::point3d& origin, const objects::spaceship& spaceship)
        :   spaceship_{spaceship},
            step_{spaceship.heading().x(), spaceship.heading().y(), spaceship.heading().z()},
            object{origin, false}
    {
        double length { 30 };

        models::point3d begin { 0, 0, 0, 0 };
        models::point3d end { begin.x(), begin.y(), begin.z(), 0 };

        // calculate bullet angle
        end.x(end.x() + length * step_.x());
        end.y(end.y() + length * step_.y());
        end.z(end.z() + length * step_.z());

        addLine({begin, end, config::BULLET_COLOUR});
    }

    void bullet::animate()
    {
        if (!discard_) {
            double maxBoundingBox { 1000 };

            // simple check if bullet is too far away.
            // if it is, safe memory space by removing the bullet from the world
            if (origin().x() < maxBoundingBox && origin().y() < maxBoundingBox && origin().z() < maxBoundingBox) {
                auto m { models::matrix::translationMatrix(step_.x() * 10, step_.y() * 10, step_.z() * 10) };
                origin().transform({*std::move(m)});
            } else {
                discard_ = true;
            }
        }
    }
}