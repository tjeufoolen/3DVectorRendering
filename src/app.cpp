#include "app.h"

#include "logger.h"
#include "cube.h"
#include "pyramid.h"
#include "config.h"

app::app()
    :   view_{"Eindopdracht Lineaire algebra - gemaakt door Stan Geitel en Tjeu Foolen.",
            config::WINDOW_WIDTH, config::WINDOW_HEIGHT, utils::colours::black, "assets/images/icon.png"},
        world_{view_},
        keyHandler_{world_}
{
//    std::unique_ptr<objects::object> cube { std::make_unique<objects::cube>(view_, models::point3d{100,100,0}) };
//    world_.addObject(std::move(cube));
    std::unique_ptr<objects::object> pyramid { std::make_unique<objects::pyramid>(view_, models::point3d{100,0,-100}) };
    world_.addObject(std::move(pyramid));


    // temp: temporarily for debug purposes, remove after!
    // set world origin to center of window
    world_.origin(static_cast<double>(config::WINDOW_WIDTH) / 2, static_cast<double>(config::WINDOW_HEIGHT) / 2, 0);
}

void app::run() {
    bool keepRunning { true };

    while (keepRunning) {
        SDL_Event e;

        while (SDL_PollEvent(&e) != 0) {
            if (e.type == SDL_KEYDOWN) {
                keyHandler_.handle(e.key);
            }

            if (e.type == SDL_QUIT) {
                keepRunning = false;
            }
        }

        view_.clear();
        draw();
        view_.render();
    }

    view_.close();
}

void app::draw() {
    world_.draw();
}