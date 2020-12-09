#include "app.h"

#include "utils/logger.h"

app::app()
    : view_{"Eindopdracht Lineaire algebra - gemaakt door Stan Geitel en Tjeu Foolen.",
            1080, 720, utils::colours::black, "assets/images/icon.png"}
{

}

void app::run() {
    bool keepRunning = true;

    while (keepRunning) {
        SDL_Event e;

        while (SDL_PollEvent(&e) != 0) {
            if (e.type == SDL_KEYDOWN) {
                switch (e.key.keysym.sym) {
                    // temp: temporarily for debug purposes, remove after!
                    case SDLK_SPACE:
                    {
                        utils::logger::getInstance().debug("PRESSED SPACE!!!");
                    }
                }
            }

            if (e.type == SDL_QUIT) {
                keepRunning = false;
            }
        }

        view_.clear();
        draw();
        view_.render();
    }
}

void app::draw() {
    view_.renderRectangle(100, 100, 100, 100, utils::colours::red, true);
    view_.renderRectangle(100, 200, 100, 100, utils::colours::green, true);
    view_.renderRectangle(100, 300, 100, 100, utils::colours::blue, true);
    view_.renderRectangle(250, 100, 100, 100, utils::colours::red, false);
    view_.renderRectangle(250, 200, 100, 100, utils::colours::green, false);
    view_.renderRectangle(250, 300, 100, 100, utils::colours::blue, false);

    view_.renderLine(100, 500, 800, 500, utils::colours::purple);

    view_.renderText("Hello World!", 100, 600, 24, utils::colours::white);
}