#ifndef CPP_3DVECTORRENDERING_APP_H
#define CPP_3DVECTORRENDERING_APP_H

#include "view.h"
#include "camera.h"
#include "world.h"
#include "key_handler.h"

class app {
    view::view view_;
    models::world world_;
    view::camera camera_;
    input::key_handler keyHandler_;
public:
    app();

    void run();
    void init();
    void draw();
};


#endif //CPP_3DVECTORRENDERING_APP_H
