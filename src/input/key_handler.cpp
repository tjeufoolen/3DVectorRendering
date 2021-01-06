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

            // camera
            case SDLK_RIGHT:
                camera_.transform(*std::move(models::matrix::rotateY(-config::ROTATION_DEGREES_PER_KEY_PRESS)));
                break;

            case SDLK_LEFT:
                camera_.transform(*std::move(models::matrix::rotateY(config::ROTATION_DEGREES_PER_KEY_PRESS)));
                break;

            case SDLK_UP:
                camera_.transform(*std::move(models::matrix::rotateX(config::ROTATION_DEGREES_PER_KEY_PRESS)));
                break;

            case SDLK_DOWN:
                camera_.transform(*std::move(models::matrix::rotateX(-config::ROTATION_DEGREES_PER_KEY_PRESS)));
                break;


//            case SDLK_UP:
//                world_.transformObjects(*std::move(models::matrix::rotateX(
//                        -config::ROTATION_DEGREES_PER_KEY_PRESS)));
//                world_.spaceship().transform(*std::move(models::matrix::rotateX(
//                        -config::ROTATION_DEGREES_PER_KEY_PRESS)));
//                break;
//            case SDLK_DOWN:
//                world_.transformObjects(*std::move(models::matrix::rotateX(
//                        config::ROTATION_DEGREES_PER_KEY_PRESS)));
//                world_.spaceship().transform(*std::move(models::matrix::rotateX(
//                        config::ROTATION_DEGREES_PER_KEY_PRESS)));
//                break;
//            case SDLK_LEFT:
//                world_.transformObjects(*std::move(models::matrix::rotateY(
//                        -config::ROTATION_DEGREES_PER_KEY_PRESS)));
//                world_.spaceship().transform(*std::move(models::matrix::rotateY(
//                        -config::ROTATION_DEGREES_PER_KEY_PRESS)));
//                break;
//            case SDLK_RIGHT:
//                world_.transformObjects(*std::move(models::matrix::rotateY(
//                        config::ROTATION_DEGREES_PER_KEY_PRESS)));
//                world_.spaceship().transform(*std::move(models::matrix::rotateY(
//                        config::ROTATION_DEGREES_PER_KEY_PRESS)));
//                break;
//            case SDLK_PAGEUP:
//                world_.transformObjects(*std::move(models::matrix::worldSpaceScalingMatrix(
//                        config::UP_SCALE_STEPS_PER_KEY_PRESS,
//                        config::UP_SCALE_STEPS_PER_KEY_PRESS,
//                        config::UP_SCALE_STEPS_PER_KEY_PRESS)));
//                world_.spaceship().transform(*std::move(models::matrix::worldSpaceScalingMatrix(
//                        config::UP_SCALE_STEPS_PER_KEY_PRESS,
//                        config::UP_SCALE_STEPS_PER_KEY_PRESS,
//                        config::UP_SCALE_STEPS_PER_KEY_PRESS)));
//                break;
//            case SDLK_PAGEDOWN:
//                world_.transformObjects(*std::move(models::matrix::worldSpaceScalingMatrix(
//                        config::DOWN_SCALE_STEPS_PER_KEY_PRESS,
//                        config::DOWN_SCALE_STEPS_PER_KEY_PRESS,
//                        config::DOWN_SCALE_STEPS_PER_KEY_PRESS)));
//                world_.spaceship().transform(*std::move(models::matrix::worldSpaceScalingMatrix(
//                        config::DOWN_SCALE_STEPS_PER_KEY_PRESS,
//                        config::DOWN_SCALE_STEPS_PER_KEY_PRESS,
//                        config::DOWN_SCALE_STEPS_PER_KEY_PRESS)));
//                break;

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
            case SDLK_a:
                world_.spaceship().transform(*std::move(models::matrix::rotateY(
                        config::ROTATION_DEGREES_PER_KEY_PRESS)));
                break;
            case SDLK_d:
                world_.spaceship().transform(*std::move(models::matrix::rotateY(
                        -config::ROTATION_DEGREES_PER_KEY_PRESS)));
                break;
        }
    }
}