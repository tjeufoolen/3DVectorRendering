#ifndef LINAL_EINDOPDRACHT_SPACESHIP_H
#define LINAL_EINDOPDRACHT_SPACESHIP_H

#include <vector>

#include "object.h"

namespace models {
    class world; // forward declare
}

namespace objects {
    class spaceship : public object {
        models::world& world_;
        bool alive_;
        std::vector<int> bulletIds_;
    public:
        spaceship(const models::point3d& origin, models::world& world);

        void transform(const models::Matrix &m) override;

        bool isAlive() const;
        void onCollision(const objects::object &other) override;

        void shoot();
    };
}

#endif //LINAL_EINDOPDRACHT_SPACESHIP_H
