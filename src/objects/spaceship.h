#ifndef LINAL_EINDOPDRACHT_SPACESHIP_H
#define LINAL_EINDOPDRACHT_SPACESHIP_H

#include "object.h"

namespace models {
    class world; // forward declare
}

namespace objects {
    class spaceship : public object {
        models::world& world_;
        models::point3d heading_;
    public:
        spaceship(const models::point3d& origin, models::world& world);

        void transform(const models::Matrix &m) override;
        const models::point3d& heading() const;

        void shoot();
    };
}

#endif //LINAL_EINDOPDRACHT_SPACESHIP_H
