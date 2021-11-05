#ifndef CPP_3DVECTORRENDERING_PYRAMID_H
#define CPP_3DVECTORRENDERING_PYRAMID_H

#include "object.h"

namespace objects {
    class pyramid : public object {
        double scale_;
        double scaleFactor_;
        double maxScale_;
        double minScale_;
    public:
        pyramid(const models::point3d& origin);

        void animate() override;
    };
}

#endif //CPP_3DVECTORRENDERING_PYRAMID_H
