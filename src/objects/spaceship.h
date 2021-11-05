#ifndef CPP_3DVECTORRENDERING_SPACESHIP_H
#define CPP_3DVECTORRENDERING_SPACESHIP_H

#include <vector>

#include "object.h"

namespace models {
    class world; // forward declare
}

namespace objects {
    class spaceship : public object {
        models::world& world_;
        bool alive_ = true;
        std::vector<int> bulletIds_;
    public:
        spaceship(const models::point3d& origin, models::world& world);

        void transform(const models::Matrix &m) override;

        bool isAlive() const;
        void onCollision(const objects::object &other) override;

        void shoot();
    };
}

#endif //CPP_3DVECTORRENDERING_SPACESHIP_H
