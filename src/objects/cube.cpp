#include "cube.h"

namespace objects {
    cube::cube(view::view& view, const models::point3d& origin)
        : object(view, origin)
    {
        //     H---------G
        //    /|        /|
        //   / |       / |
        //  E---------F  |
        //  |  D------|--C
        //  | /       | /
        //  |/        |/
        //  A---------B

        models::point3d a {-50,-50, 50};
        models::point3d b { 50,-50, 50};
        models::point3d c { 50,-50,-50};
        models::point3d d {-50,-50,-50};
        models::point3d e {-50, 50, 50};
        models::point3d f { 50, 50, 50};
        models::point3d g { 50, 50,-50};
        models::point3d h {-50, 50,-50};

        addLine({a,b});
        addLine({b,c});
        addLine({c,d});
        addLine({d,a});

        addLine({e,f});
        addLine({f,g});
        addLine({g,h});
        addLine({h,e});

        addLine({a,e});
        addLine({b,f});
        addLine({c,g});
        addLine({d,h});
    }
}