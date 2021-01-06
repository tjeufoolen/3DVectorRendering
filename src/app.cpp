#include "app.h"

#include "config.h"

app::app()
    :   view_{"Eindopdracht Lineaire algebra - gemaakt door Stan Geitel en Tjeu Foolen.",
            config::WINDOW_WIDTH, config::WINDOW_HEIGHT, utils::colours::black, "assets/images/icon.png"},
        world_{},
        camera_{view_, world_},
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
    double WINDOW_CENTER_X { static_cast<double>(config::WINDOW_WIDTH)  / 2 };
    double WINDOW_CENTER_Y { static_cast<double>(config::WINDOW_HEIGHT) / 2 };

    // set world origin to center of window
    world_.origin(WINDOW_CENTER_X, WINDOW_CENTER_Y, 0);
//    world_.origin(0,0,0);

    // initialize bird's eye view perspective with camera
    camera_.origin(0, 0, 100);
//    camera_.origin(-100, -100, 100);
//    camera_.origin(WINDOW_CENTER_X, WINDOW_CENTER_Y, 100);
}

void app::draw() {
    camera_.draw();
}