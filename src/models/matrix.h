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

        static matrix_ptr multiply(Matrix &l, Matrix &r);

        // Matrices
        static matrix_ptr projectionMatrix(double fovy, double near, double far);
        static matrix_ptr translationMatrix(double tx, double ty, double tz);
        static matrix_ptr rotateX(double degrees);
        static matrix_ptr rotateY(double degrees);
        static matrix_ptr rotateZ(double degrees);
        static matrix_ptr localSpaceScalingMatrix(double x, double y, double z, double sx, double sy, double sz);
        static matrix_ptr worldSpaceScalingMatrix(double sx, double sy, double sz);

        // Helpers
        static double degreesToRadial(double degrees);
        static void print(const Matrix& m);
    private:
        static const int columns_;
        static const int rows_;
    };
}

#endif //LINAL_EINDOPDRACHT_MATRIX_H
