#ifndef LINAL_EINDOPDRACHT_VIEW_H
#define LINAL_EINDOPDRACHT_VIEW_H

#include <SDL.h>
#include <memory>
#include <string>

#include "utils/colour.h"

namespace view {
    using window_ptr = std::unique_ptr<SDL_Window, decltype(&SDL_DestroyWindow)>;
    using renderer_ptr = std::unique_ptr<SDL_Renderer, decltype(&SDL_DestroyRenderer)>;

    class view {
        const std::string& title_;
        int width_;
        int height_;
        const utils::colour& backgroundColour_;

        window_ptr window_;
        renderer_ptr renderer_;
    public:
        view(const std::string &title, int width, int height, const utils::colour& bgColour, const std::string& iconPath);

        void init();
        void clear();
        void render();
        void close();

        void renderRectangle(double x, double y, double width, double height, const utils::colour& colour, bool fill);
        void renderLine(double sx, double sy, double ex, double ey, const utils::colour& colour);
        void renderText(const std::string& text, double x, double y, int size, const utils::colour& colour);
    private:
        window_ptr createWindow(const std::string& title, int width, int height);
        renderer_ptr createRenderer(const window_ptr& window);

        void setRenderColor(const utils::colour& colour);
    };
}

#endif //LINAL_EINDOPDRACHT_VIEW_H
