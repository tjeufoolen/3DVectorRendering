#include "pyramid.h"

namespace objects {
    pyramid::pyramid(const models::point3d& origin)
        :   object(origin),
            scale_{1}, scaleFactor_{1.01}, maxScale_{2}, minScale_{1}
    {
        //       E
        //      / \
        //     /D--\-----C
        //    /     \   /
        //   /       \ /
        //  A---------B

        models::point3d a {-50,-50, 50};
        models::point3d b { 50,-50, 50};
        models::point3d c { 50,-50,-50};
        models::point3d d {-50,-50,-50};
        models::point3d e {  0, 50,  0};

        addLine({a,b});
        addLine({b,c});
        addLine({c,d});
        addLine({d,a});

        addLine({a,e});
        addLine({b,e});
        addLine({c,e});
        addLine({d,e});
    }

    void pyramid::animate()
    {
        scale_ *= scaleFactor_;

        if (scale_ >= maxScale_) {
            scaleFactor_ = 0.99;
        } else if ( scale_ <= minScale_) {
            scaleFactor_ = 1.01;
        }

        transform(*std::move(models::matrix::worldSpaceScalingMatrix(
            scaleFactor_, scaleFactor_, scaleFactor_
        )));
    }
}