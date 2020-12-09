#ifndef LINAL_EINDOPDRACHT_MATRIX_H
#define LINAL_EINDOPDRACHT_MATRIX_H

#include <memory>
#include <array>

namespace models {
    using Matrix = std::array<std::array<double, 4>, 4>;
    using matrix_ptr = std::unique_ptr<Matrix>;

    struct matrix {
        constexpr static const double PI = 3.14159265358979323846;
        constexpr static double const EPSILON = 1.0E-09; // 1 after 9 zero's

        // Matrices
        static matrix_ptr translationMatrix(double tx, double ty, double tz);
        matrix_ptr localSpaceScalingMatrix(double x, double y, double z, double sx, double sy, double sz);
        matrix_ptr worldSpaceScalingMatrix(double sx, double sy, double sz);

        matrix_ptr multiply(Matrix &l, Matrix &r);
        static double radial(double degrees);
    private:
        static const int columns_;
        static const int rows_;
    };
}

#endif //LINAL_EINDOPDRACHT_MATRIX_H
