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

    view_.close();
}

void app::draw() {

}