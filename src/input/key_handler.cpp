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
            case SDLK_PAGEUP:
                camera_.origin().transform(*std::move(models::matrix::rotateZ(-config::ROTATION_DEGREES_PER_KEY_PRESS)));
                break;
            case SDLK_PAGEDOWN:
                camera_.origin().transform(*std::move(models::matrix::rotateZ(config::ROTATION_DEGREES_PER_KEY_PRESS)));
                break;

            // world scaling
            case SDLK_HOME:
                world_.scale(config::UP_SCALE_STEPS_PER_KEY_PRESS);
                break;
            case SDLK_END:
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

            // move
            case SDLK_r:
                world_.spaceship().origin().transform(*std::move(models::matrix::translationMatrix(
                        world_.spaceship().heading().x() * -config::MOVE_STEPS_PER_KEY_PRESS,
                        world_.spaceship().heading().y() * -config::MOVE_STEPS_PER_KEY_PRESS,
                        world_.spaceship().heading().z() * -config::MOVE_STEPS_PER_KEY_PRESS)));
                break;
            case SDLK_f:
            case SDLK_LSHIFT:
                world_.spaceship().origin().transform(*std::move(models::matrix::translationMatrix(
                        world_.spaceship().heading().x() * config::MOVE_STEPS_PER_KEY_PRESS,
                        world_.spaceship().heading().y() * config::MOVE_STEPS_PER_KEY_PRESS,
                        world_.spaceship().heading().z() * config::MOVE_STEPS_PER_KEY_PRESS)));
                break;

            // shoot
            case SDLK_SPACE:
                world_.spaceship().shoot();
                break;
        }
    }
}