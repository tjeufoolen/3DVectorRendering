#ifndef LINAL_EINDOPDRACHT_CAMERA_H
#define LINAL_EINDOPDRACHT_CAMERA_H

#include "view.h"
#include "world.h"

namespace view {
    class camera {
        view& view_;
        models::world& world_;
        models::point3d origin_;
        double xDrawOffset_;
        double yDrawOffset_;
    public:
        camera(view& view, models::world& world, const models::point3d& origin = {0,0,0}, double xDrawOffset=0, double yDrawOffset=0);

        void origin(double x, double y, double z);
        models::point3d& origin();

        void draw();
    private:
        void drawObject(objects::object& obj);

        models::point3d direction() const;
        models::matrix_ptr transformationMatrix();
    };
}

#endif //LINAL_EINDOPDRACHT_CAMERA_H
