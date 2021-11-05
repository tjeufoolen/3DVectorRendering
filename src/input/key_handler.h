#ifndef CPP_3DVECTORRENDERING_KEY_HANDLER_H
#define CPP_3DVECTORRENDERING_KEY_HANDLER_H

#include "world.h"
#include "camera.h"
#include "SDL_events.h"

namespace input {
    class key_handler {
        models::world& world_;
        view::camera& camera_;
    public:
        key_handler(models::world& world, view::camera& camera);

        void handle(const SDL_KeyboardEvent& key);
    };
}


#endif //CPP_3DVECTORRENDERING_KEY_HANDLER_H
