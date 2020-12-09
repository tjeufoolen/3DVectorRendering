#ifndef LINAL_EINDOPDRACHT_APP_H
#define LINAL_EINDOPDRACHT_APP_H

#include "view/view.h"

class app {
    view::view view_;
public:
    app();

    void run();
    void draw();
};


#endif //LINAL_EINDOPDRACHT_APP_H
