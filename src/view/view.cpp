#include "view.h"

#include <SDL_image.h>
#include <SDL_ttf.h>
#include <iostream>

namespace view {
    view::view(const std::string &title, int width, int height, const utils::colour &bgColour, const std::string& iconPath)
        :   title_{title},
            width_{width},
            height_{height},
            backgroundColour_{bgColour},
            window_{createWindow(title_, width_, height_)},
            renderer_{createRenderer(window_)}
    {
        // Set window icon
        SDL_Surface *icon {IMG_Load(std::string(SDL_GetBasePath()).append(iconPath).c_str())};
        SDL_SetWindowIcon(window_.get(), icon);
        SDL_FreeSurface(icon);
    }

    void view::init() {
        if (SDL_Init(SDL_INIT_EVERYTHING) != 0) {
            std::string msg { std::string("SDL_Init Error: ").append(SDL_GetError()) };
        }

        IMG_Init(IMG_INIT_JPG | IMG_INIT_PNG);
        TTF_Init();
    }

    void view::clear() {
        SDL_SetRenderDrawColor(
            renderer_.get(),
            backgroundColour_.r,
            backgroundColour_.g,
            backgroundColour_.b,
            backgroundColour_.a
        );
        SDL_RenderClear(renderer_.get());
    }

    void view::render() {
        SDL_RenderPresent(renderer_.get());
    }

    void view::close() {
        SDL_DestroyWindow(window_.get());
        SDL_Quit();
    }

    void view::debug(bool show)
    {
        debug_ = show;
    }

    window_ptr view::createWindow(const std::string& title, int width, int height) {
        init();

        // If no size is specified, fallback to 1080x720 (720p)
        if (width <= 0 || height <= 0) {
            width = 1080;
            height = 720;
        }

        return window_ptr(
            SDL_CreateWindow(
                title.c_str(),
                SDL_WINDOWPOS_CENTERED,
                SDL_WINDOWPOS_CENTERED,
                width, height,
                SDL_WINDOW_SHOWN
            ),
            SDL_DestroyWindow
        );
    }

    renderer_ptr view::createRenderer(const window_ptr& window) {
        return renderer_ptr(
            SDL_CreateRenderer(
                window.get(),
                -1,
                SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC
            ),
            SDL_DestroyRenderer
        );
    }

    void view::renderRectangle(double x, double y, double width, double height, const utils::colour& colour, bool fill) {
        setRenderColor(colour);

        SDL_FRect rect;
        rect.x = static_cast<float>(x);
        rect.y = static_cast<float>(y);
        rect.w = static_cast<float>(width);
        rect.h = static_cast<float>(height);

        if (fill) {
            SDL_RenderFillRectF(renderer_.get(), &rect);
        } else {
            SDL_RenderDrawRectF(renderer_.get(), &rect);
        }
    }

    void view::renderLine(double beginX, double beginY, double endX, double endY, const utils::colour &colour) {
        setRenderColor(colour);

        if (debug_) std::cout << "line [x" << beginX << ", y" << beginY << "] -> [x" << endX << ", y" << endY << "]" << std::endl;

        SDL_RenderDrawLineF(
            renderer_.get(),
            static_cast<float>(beginX),
            static_cast<float>(beginY),
            static_cast<float>(endX),
            static_cast<float>(endY)
        );
    }

    // This code is based of; https://gist.github.com/derofim/912cfc9161269336f722
    void view::renderCircle(double centerX, double centerY, double radius, const utils::colour &colour) {
        setRenderColor(colour);

        if (debug_) std::cout << "circle [x" << centerX << ", y" << centerY << "]" << std::endl;

        for (int dy {1}; dy <= radius; dy++)
        {
            double dx { floor(sqrt((2.0 * radius * dy) - (dy * dy))) };

            SDL_RenderDrawLineF(
                renderer_.get(),
                static_cast<float>(centerX - dx),
                static_cast<float>(centerY + dy - radius),
                static_cast<float>(centerX + dx),
                static_cast<float>(centerY + dy - radius)
            );
            SDL_RenderDrawLineF(
                renderer_.get(),
                static_cast<float>(centerX - dx),
                static_cast<float>(centerY - dy + radius),
                static_cast<float>(centerX + dx),
                static_cast<float>(centerY - dy + radius)
            );
        }
    }

    void view::renderText(const std::string& text, double x, double y, int size, const utils::colour &colour) {
        std::string fontPath { std::string(SDL_GetBasePath()).append("/assets/fonts/OpenSans-Regular.ttf") };
        TTF_Font *font { TTF_OpenFont(fontPath.c_str(), size) };
        SDL_Color textColor { colour.r, colour.g, colour.b, colour.a };

        SDL_Surface* surfaceMessage { TTF_RenderText_Blended(font, text.c_str(), textColor) };
        SDL_Texture* Message { SDL_CreateTextureFromSurface(renderer_.get(), surfaceMessage) };
        SDL_Rect Message_rect { static_cast<int>(x), static_cast<int>(y), surfaceMessage->w, surfaceMessage->h };
        SDL_RenderCopy(renderer_.get(), Message, nullptr, &Message_rect);

        SDL_FreeSurface(surfaceMessage);
        SDL_DestroyTexture(Message);
        TTF_CloseFont(font);
    }

    void view::setRenderColor(const utils::colour &colour) {
        SDL_SetRenderDrawColor(renderer_.get(), colour.r, colour.g, colour.b, colour.a);
    }
}