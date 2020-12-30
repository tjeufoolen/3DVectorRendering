#ifndef LINAL_EINDOPDRACHT_APP_H
#define LINAL_EINDOPDRACHT_APP_H

#include "view.h"
#include "world.h"
#include "key_handler.h"

class app {
    view::view view_;
    models::world world_;
    input::key_handler keyHandler_;
public:
    app();

    void run();
    void draw();
};


#endif //LINAL_EINDOPDRACHT_APP_H
