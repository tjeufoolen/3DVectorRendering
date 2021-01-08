#ifndef LINAL_EINDOPDRACHT_BULLET_H
#define LINAL_EINDOPDRACHT_BULLET_H

#include "object.h"

namespace objects {
    class spaceship; // forward declare

    class bullet : public object {
        const objects::spaceship& spaceship_;

        double zOffset_;
    public:
        bullet(const models::point3d& origin, const objects::spaceship& spaceship);

        void animate() override;
    };
}

#endif //LINAL_EINDOPDRACHT_BULLET_H
