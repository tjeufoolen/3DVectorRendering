#ifndef LINAL_EINDOPDRACHT_KEY_HANDLER_H
#define LINAL_EINDOPDRACHT_KEY_HANDLER_H

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


#endif //LINAL_EINDOPDRACHT_KEY_HANDLER_H
