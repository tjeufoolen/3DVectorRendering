#include "app.h"

#include "cube.h"
#include "pyramid.h"
#include "config.h"
#include "spaceship.h"

app::app()
    :   view_{"CPP_3DVectorRendering",
            config::WINDOW_WIDTH, config::WINDOW_HEIGHT, utils::colours::black, "assets/images/icon.png"},
        world_{{0,0,0}},
        camera_{view_, world_, {100, 100, -100}, config::WINDOW_WIDTH / 2.0, config::WINDOW_HEIGHT / 2.0},
        keyHandler_{world_, camera_}
{

}

void app::run() {
    init();

    bool keepRunning { true };
    while (keepRunning) {
        SDL_Event e;

        while (SDL_PollEvent(&e) != 0) {
            if (e.type == SDL_KEYDOWN)
                keyHandler_.handle(e.key);
            if (e.type == SDL_QUIT)
                keepRunning = false;
        }

        view_.clear();
        draw();
        view_.render();
    }

    view_.close();
}

void app::init() {
    // add spaceship to world
    world_.spaceship(std::make_unique<objects::spaceship>(
            objects::spaceship{{0,0,-400}, world_}));

    // add basic object to display world coordinate system axis (placed directly on origin inside the world)
    world_.addObject(std::make_unique<objects::object>(models::point3d{0,0,0}, true, false));

    // add other objects
    world_.addObject(std::make_unique<objects::cube>(models::point3d{-300,0,400}));
    world_.addObject(std::make_unique<objects::pyramid>(models::point3d{0, 0, 200}));
    world_.addObject(std::make_unique<objects::cube>(models::point3d{300, 0, 400}));
}

void app::draw() {
    auto& objects { world_.objects() };

    // remove objects that are marked to be discard
    auto shouldDiscard { [](auto& obj){ return obj->discard(); } };
    objects.erase(std::remove_if(objects.begin(), objects.end(), shouldDiscard), objects.end());

    // draw objects to screen
    camera_.draw();
}