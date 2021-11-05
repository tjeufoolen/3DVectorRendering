#ifndef CPP_3DVECTORRENDERING_MATRIX_H
#define CPP_3DVECTORRENDERING_MATRIX_H

#include <memory>
#include <array>

namespace models {
    class point3d; // forward declare

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
        static matrix_ptr randomAxisRotationMatrixToXYSpace(double x, double z);
        static matrix_ptr randomAxisRotationMatrixToXAxis(double x, double y, double z);
        static matrix_ptr randomAxisRotationMatrixFromXAxis(double x, double y, double z);
        static matrix_ptr randomAxisRotationMatrixFromXYSpace(double x, double z);
        static matrix_ptr randomAxisRotationMatrix(double x, double y, double z, double a);
        static matrix_ptr localSpaceScalingMatrix(double x, double y, double z, double sx, double sy, double sz);
        static matrix_ptr worldSpaceScalingMatrix(double sx, double sy, double sz);
        static matrix_ptr inverseMatrix(const models::point3d& right, const models::point3d& up, const models::point3d& direction);

        // Helpers
        static double degreesToRadial(double degrees);
        static void print(const Matrix& m);
    private:
        static const int columns_;
        static const int rows_;
    };
}

#endif //CPP_3DVECTORRENDERING_MATRIX_H
