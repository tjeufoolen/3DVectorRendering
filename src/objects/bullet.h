#ifndef LINAL_EINDOPDRACHT_BULLET_H
#define LINAL_EINDOPDRACHT_BULLET_H

#include "object.h"

namespace objects {
    class spaceship; // forward declare

    class bullet : public object {
        const objects::spaceship& spaceship_;

        models::point3d step_;
    public:
        bullet(const models::point3d& origin, const objects::spaceship& spaceship);

        void onCollision(const objects::object &other) override;

        void animate() override;
    };
}

#endif //LINAL_EINDOPDRACHT_BULLET_H
