#ifndef LINAL_EINDOPDRACHT_COLOUR_H
#define LINAL_EINDOPDRACHT_COLOUR_H

#include <cstdint>

namespace utils {
    struct colour
    {
        uint8_t r;
        uint8_t g;
        uint8_t b;
        uint8_t a;

        bool const operator==(colour const& other) const
        {
            return r == other.r && g == other.g && b == other.b && a == other.a;
        }
        bool const operator!=(colour const& other) const
        {
            return r != other.r && g != other.g && b != other.b && a != other.a;
        }
    };

    namespace colours {
        colour const black = { 0, 0, 0, 255 };
        colour const white = { 255, 255, 255, 255 };
        colour const red = { 255, 0, 0, 255 };
        colour const green = { 0, 255, 0, 255 };
        colour const blue = { 0, 0, 255, 255 };
        colour const yellow = { 255, 255, 0, 255 };
        colour const orange = { 255, 128, 0, 255 };
        colour const purple = { 127, 0, 255, 255 };
        colour const pink = { 255, 0, 127, 255 };
        colour const cyan = { 0, 255, 255, 255 };
    }
}

#endif //LINAL_EINDOPDRACHT_COLOUR_H
