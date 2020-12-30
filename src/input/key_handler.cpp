#include "key_handler.h"

#include "config.h"
#include "matrix.h"

namespace input {
    key_handler::key_handler(models::world &world)
        :   world_{world} {}

    void key_handler::handle(const SDL_KeyboardEvent& key) {
        switch (key.keysym.sym) {
            case SDLK_SLASH:
                world_.print();
                break;

            // rotate x
            case SDLK_q:
                world_.transformObjects(*std::move(models::matrix::rotateX(-config::ROTATION_DEGREES_PER_KEY_PRESS)));
                break;
            case SDLK_a:
                world_.transformObjects(*std::move(models::matrix::rotateX(config::ROTATION_DEGREES_PER_KEY_PRESS)));
                break;

            // rotate y
            case SDLK_w:
                world_.transformObjects(*std::move(models::matrix::rotateY(-config::ROTATION_DEGREES_PER_KEY_PRESS)));
                break;
            case SDLK_s:
                world_.transformObjects(*std::move(models::matrix::rotateY(config::ROTATION_DEGREES_PER_KEY_PRESS)));
                break;

            // rotate z
            case SDLK_e:
                world_.transformObjects(*std::move(models::matrix::rotateZ(-config::ROTATION_DEGREES_PER_KEY_PRESS)));
                break;
            case SDLK_d:
                world_.transformObjects(*std::move(models::matrix::rotateZ(config::ROTATION_DEGREES_PER_KEY_PRESS)));
                break;

            // move right-left-up-down
            case SDLK_RIGHT:
                world_.transformObjects(*std::move(models::matrix::translationMatrix(config::MOVE_STEPS_PER_KEY_PRESS,0,0)));
                break;
            case SDLK_LEFT:
                world_.transformObjects(*std::move(models::matrix::translationMatrix(-config::MOVE_STEPS_PER_KEY_PRESS,0,0)));
                break;
            case SDLK_UP:
                world_.transformObjects(*std::move(models::matrix::translationMatrix(0,config::MOVE_STEPS_PER_KEY_PRESS,0)));
                break;
            case SDLK_DOWN:
                world_.transformObjects(*std::move(models::matrix::translationMatrix(0,-config::MOVE_STEPS_PER_KEY_PRESS,0)));
                break;
        }
    }
}