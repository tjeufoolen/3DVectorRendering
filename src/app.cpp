#include "app.h"

#include "pyramid.h"
#include "config.h"

app::app()
    :   view_{"Eindopdracht Lineaire algebra - gemaakt door Stan Geitel en Tjeu Foolen.",
            config::WINDOW_WIDTH, config::WINDOW_HEIGHT, utils::colours::black, "assets/images/icon.png"},
        world_{{0,0,0}, objects::spaceship{{0,50,0}}},
        camera_{view_, world_, {0, 0, 100}},
        keyHandler_{world_, camera_}
{

}

void app::run() {
    bool keepRunning { true };

    init();

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

void app::init() {
    // basic object for world coordinates axis
    world_.addObject(std::make_unique<objects::object>(models::point3d{0,0,0}));

    // planets/asteroids
    world_.addObject(std::make_unique<objects::pyramid>(models::point3d{0, 50, -500}));
}

void app::draw() {
    camera_.draw();
}