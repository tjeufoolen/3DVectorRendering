#ifndef CPP_3DVECTORRENDERING_OBJECT_H
#define CPP_3DVECTORRENDERING_OBJECT_H

#include <vector>

#include "matrix.h"
#include "line3d.h"
#include "view.h"

namespace models {
    class world; // forward declare
}

namespace objects {
    class object {
        int id_;
        static int current_id;
    protected:
        std::vector<models::line3d> lines_;
        models::point3d origin_;
        bool discard_{false}; // update this if you want to remove the object from the world the next iteration
        models::point3d heading_;
        bool collidable_;
    public:
        object(const models::point3d& origin = {0, 0, 0}, bool showAxis = true, bool collidable = true);

        int id() const;

        virtual void transform(const models::Matrix& m);

        std::vector<models::line3d>& lines();

        void origin(double x, double y, double z);
        models::point3d origin() const;
        models::point3d& origin();

        const models::point3d& heading() const;

        models::point3d centrum() const;

        virtual void animate() {}; // runs every game loop
        bool discard();

        bool collidable() const;
        virtual void onCollision(const objects::object& other);
        bool collides(const objects::object& other) const;

        void print();
    protected:
        models::line3d& addLine(models::line3d line);
    };
}

#endif //CPP_3DVECTORRENDERING_OBJECT_H
