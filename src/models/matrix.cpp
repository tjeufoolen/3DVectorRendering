#include "matrix.h"

namespace models {
    matrix_ptr matrix::multiply(Matrix &l, Matrix &r) {
        if (l[0].size() != r.size())
            return nullptr;

        Matrix m;

        for (int i = 0; i < l.size(); i++) {
            for (int j = 0; j < r.size(); j++) {
                m[i][j] = l[i][0] * r[0][j] + l[i][1] * r[1][j] + l[i][2] * r[2][j] + l[i][3] * r[3][j];
            }
        }

        return std::make_unique<Matrix>(m);
    }

    matrix_ptr matrix::translationMatrix(double tx, double ty, double tz) {
        Matrix m;

        m[0][0] = 1.0; m[0][1] = 0.0; m[0][2] = 0.0; m[0][3] = tx;
        m[1][0] = 0.0; m[1][1] = 1.0; m[1][2] = 0.0; m[1][3] = ty;
        m[2][0] = 0.0; m[2][1] = 0.0; m[2][2] = 1.0; m[2][3] = tz;
        m[3][0] = 0.0; m[3][1] = 0.0; m[3][2] = 0.0; m[3][3] = 1.0;

        return std::make_unique<Matrix>(m);
    }

    matrix_ptr matrix::rotateX(double degrees) {
        double a = degreesToRadial(degrees);

        Matrix m;

        m[0][0] = 1.0; m[0][1] = 0.0;    m[0][2] = 0.0;     m[0][3] = 0.0;
        m[1][0] = 0.0; m[1][1] = cos(a); m[1][2] = -sin(a); m[1][3] = 0.0;
        m[2][0] = 0.0; m[2][1] = sin(a); m[2][2] = cos(a);  m[2][3] = 0.0;
        m[3][0] = 0.0; m[3][1] = 0.0;    m[3][2] = 0.0;     m[3][3] = 1.0;

        return std::make_unique<Matrix>(m);
    }

    matrix_ptr matrix::rotateY(double degrees) {
        double a = degreesToRadial(degrees);

        Matrix m;

        m[0][0] = cos(a);  m[0][1] = 0.0; m[0][2] = sin(a); m[0][3] = 0.0;
        m[1][0] = 0.0;     m[1][1] = 1.0; m[1][2] = 0.0;    m[1][3] = 0.0;
        m[2][0] = -sin(a); m[2][1] = 0.0; m[2][2] = cos(a); m[2][3] = 0.0;
        m[3][0] = 0.0;     m[3][1] = 0.0; m[3][2] = 0.0;    m[3][3] = 1.0;

        return std::make_unique<Matrix>(m);
    }

    matrix_ptr matrix::rotateZ(double degrees) {
        double a = degreesToRadial(degrees);

        Matrix m;

        m[0][0] = cos(a); m[0][1] = -sin(a); m[0][2] = 0.0; m[0][3] = 0.0;
        m[1][0] = sin(a); m[1][1] = cos(a);  m[1][2] = 0.0; m[1][3] = 0.0;
        m[2][0] = 0.0;    m[2][1] = 0.0;     m[2][2] = 1.0; m[2][3] = 0.0;
        m[3][0] = 0.0;    m[3][1] = 0.0;     m[3][2] = 0.0; m[3][3] = 1.0;

        return std::make_unique<Matrix>(m);
    }

    matrix_ptr matrix::localSpaceScalingMatrix(double x, double y, double z, double sx, double sy, double sz) {
        auto t1{ *std::move(translationMatrix(-x, -y, -z)) };
        auto s { *std::move(worldSpaceScalingMatrix(sx, sy, sz)) };
        auto t2{ *std::move(translationMatrix(x, y, z)) };

        auto temp{ *std::move(models::matrix::multiply(t1, s)) };
        auto m   { *std::move(models::matrix::multiply(temp, t2)) };

        return std::make_unique<Matrix>(m);
    }

    matrix_ptr matrix::worldSpaceScalingMatrix(double sx, double sy, double sz) {
        Matrix m;

        m[0][0] = sx;  m[0][1] = 0.0; m[0][2] = 0.0; m[0][3] = 0.0;
        m[1][0] = 0.0; m[1][1] = sy;  m[1][2] = 0.0; m[1][3] = 0.0;
        m[2][0] = 0.0; m[2][1] = 0.0; m[2][2] = sz;  m[2][3] = 0.0;
        m[3][0] = 0.0; m[3][1] = 0.0; m[3][2] = 0.0; m[3][3] = 1.0;

        return std::make_unique<Matrix>(m);
    }

    double matrix::degreesToRadial(double degrees) {
        return degrees / 180.0 * PI;
    }
}