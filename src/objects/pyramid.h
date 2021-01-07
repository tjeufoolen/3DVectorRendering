#ifndef LINAL_EINDOPDRACHT_PYRAMID_H
#define LINAL_EINDOPDRACHT_PYRAMID_H

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

#endif //LINAL_EINDOPDRACHT_PYRAMID_H
