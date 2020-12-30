#ifndef LINAL_EINDOPDRACHT_KEY_HANDLER_H
#define LINAL_EINDOPDRACHT_KEY_HANDLER_H

#include "world.h"
#include "SDL_events.h"

namespace input {
    class key_handler {
        models::world& world_;
    public:
        key_handler(models::world& world);

        void handle(const SDL_KeyboardEvent& key);
    };
}


#endif //LINAL_EINDOPDRACHT_KEY_HANDLER_H
