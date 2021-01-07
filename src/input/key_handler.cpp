#include "key_handler.h"

#include "config.h"
#include "matrix.h"

namespace input {
    key_handler::key_handler(models::world &world, view::camera& camera)
        :   world_{world}, camera_{camera} {}

    void key_handler::handle(const SDL_KeyboardEvent& key) {
        switch (key.keysym.sym) {
            case SDLK_SLASH:
                world_.print();
                break;

            // camera position
            case SDLK_RIGHT:
                camera_.origin().transform(*std::move(models::matrix::rotateY(-config::ROTATION_DEGREES_PER_KEY_PRESS)));
                break;
            case SDLK_LEFT:
                camera_.origin().transform(*std::move(models::matrix::rotateY(config::ROTATION_DEGREES_PER_KEY_PRESS)));
                break;
            case SDLK_UP:
                camera_.origin().transform(*std::move(models::matrix::rotateX(config::ROTATION_DEGREES_PER_KEY_PRESS)));
                break;
            case SDLK_DOWN:
                camera_.origin().transform(*std::move(models::matrix::rotateX(-config::ROTATION_DEGREES_PER_KEY_PRESS)));
                break;

            // world scaling // todo: keys should be replaced by zoom functionality (perspective)
            case SDLK_PAGEUP:
                world_.scale(config::UP_SCALE_STEPS_PER_KEY_PRESS);
                break;
            case SDLK_PAGEDOWN:
                world_.scale(config::DOWN_SCALE_STEPS_PER_KEY_PRESS);
                break;

            // spaceship
            case SDLK_q:
                world_.spaceship().transform(*std::move(models::matrix::rotateZ(
                        config::ROTATION_DEGREES_PER_KEY_PRESS)));
                break;
            case SDLK_e:
                world_.spaceship().transform(*std::move(models::matrix::rotateZ(
                        -config::ROTATION_DEGREES_PER_KEY_PRESS)));
                break;
            case SDLK_w:
                world_.spaceship().transform(*std::move(models::matrix::rotateX(
                        config::ROTATION_DEGREES_PER_KEY_PRESS)));
                break;
            case SDLK_s:
                world_.spaceship().transform(*std::move(models::matrix::rotateX(
                        -config::ROTATION_DEGREES_PER_KEY_PRESS)));
                break;
            case SDLK_d:
                world_.spaceship().transform(*std::move(models::matrix::rotateY(
                        config::ROTATION_DEGREES_PER_KEY_PRESS)));
                break;
            case SDLK_a:
                world_.spaceship().transform(*std::move(models::matrix::rotateY(
                        -config::ROTATION_DEGREES_PER_KEY_PRESS)));
                break;
        }
    }
}