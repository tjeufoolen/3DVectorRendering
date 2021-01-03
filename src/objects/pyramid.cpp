#include "pyramid.h"

namespace objects {
    pyramid::pyramid(const models::point3d& origin)
        : object(origin)
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
}