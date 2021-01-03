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

            // camera
            case SDLK_UP:
                world_.transformObjects(*std::move(models::matrix::rotateX(
                        -config::ROTATION_DEGREES_PER_KEY_PRESS)));
                break;
            case SDLK_DOWN:
                world_.transformObjects(*std::move(models::matrix::rotateX(
                        config::ROTATION_DEGREES_PER_KEY_PRESS)));
                break;
            case SDLK_LEFT:
                world_.transformObjects(*std::move(models::matrix::rotateY(
                        -config::ROTATION_DEGREES_PER_KEY_PRESS)));
                break;
            case SDLK_RIGHT:
                world_.transformObjects(*std::move(models::matrix::rotateY(
                        config::ROTATION_DEGREES_PER_KEY_PRESS)));
                break;
            case SDLK_PAGEUP:
                world_.transformObjects(*std::move(models::matrix::worldSpaceScalingMatrix(
                        config::UP_SCALE_STEPS_PER_KEY_PRESS,
                        config::UP_SCALE_STEPS_PER_KEY_PRESS,
                        config::UP_SCALE_STEPS_PER_KEY_PRESS)));
                break;
            case SDLK_PAGEDOWN:
                world_.transformObjects(*std::move(models::matrix::worldSpaceScalingMatrix(
                        config::DOWN_SCALE_STEPS_PER_KEY_PRESS,
                        config::DOWN_SCALE_STEPS_PER_KEY_PRESS,
                        config::DOWN_SCALE_STEPS_PER_KEY_PRESS)));
                break;

            // move right-left-up-down
//            case SDLK_RIGHT:
//                world_.transformObjects(*std::move(models::matrix::translationMatrix(config::MOVE_STEPS_PER_KEY_PRESS,0,0)));
//                break;
//            case SDLK_LEFT:
//                world_.transformObjects(*std::move(models::matrix::translationMatrix(-config::MOVE_STEPS_PER_KEY_PRESS,0,0)));
//                break;
//            case SDLK_UP:
//                world_.transformObjects(*std::move(models::matrix::translationMatrix(0,config::MOVE_STEPS_PER_KEY_PRESS,0)));
//                break;
//            case SDLK_DOWN:
//                world_.transformObjects(*std::move(models::matrix::translationMatrix(0,-config::MOVE_STEPS_PER_KEY_PRESS,0)));
//                break;
        }
    }
}