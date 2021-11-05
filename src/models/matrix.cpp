#include "matrix.h"

#include <string>
#include <iostream>
#include <cmath>

#include "point3d.h"

namespace models {
    matrix_ptr matrix::multiply(Matrix &l, Matrix &r) {
        if (l[0].size() != r.size())
            return nullptr;

        Matrix m;

        for (int i {0}; i < l.size(); i++) {
            for (int j {0}; j < r.size(); j++) {
                m[i][j] = l[i][0] * r[0][j] + l[i][1] * r[1][j] + l[i][2] * r[2][j] + l[i][3] * r[3][j];
            }
        }

        return std::make_unique<Matrix>(m);
    }

    matrix_ptr matrix::projectionMatrix(double fovy, double near, double far) {
        Matrix m;

        double scale = near*tan(fovy*0.5);
        double a = (-far)/(far-near);
        double b = (-far*near)/(far-near);

        m[0][0] = scale; m[0][1] =   0.0; m[0][2] = 0.0; m[0][3] =  0.0;
        m[1][0] =   0.0; m[1][1] = scale; m[1][2] = 0.0; m[1][3] =  0.0;
        m[2][0] =   0.0; m[2][1] =   0.0; m[2][2] =   a; m[2][3] = -1.0;
        m[3][0] =   0.0; m[3][1] =   0.0; m[3][2] =   b; m[3][3] =  0.0;

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
        double a { degreesToRadial(degrees) };

        Matrix m;

        m[0][0] = 1.0; m[0][1] = 0.0;    m[0][2] = 0.0;     m[0][3] = 0.0;
        m[1][0] = 0.0; m[1][1] = cos(a); m[1][2] = -sin(a); m[1][3] = 0.0;
        m[2][0] = 0.0; m[2][1] = sin(a); m[2][2] = cos(a);  m[2][3] = 0.0;
        m[3][0] = 0.0; m[3][1] = 0.0;    m[3][2] = 0.0;     m[3][3] = 1.0;

        return std::make_unique<Matrix>(m);
    }

    matrix_ptr matrix::rotateY(double degrees) {
        double a { degreesToRadial(degrees) };

        Matrix m;

        m[0][0] = cos(a);  m[0][1] = 0.0; m[0][2] = sin(a); m[0][3] = 0.0;
        m[1][0] = 0.0;     m[1][1] = 1.0; m[1][2] = 0.0;    m[1][3] = 0.0;
        m[2][0] = -sin(a); m[2][1] = 0.0; m[2][2] = cos(a); m[2][3] = 0.0;
        m[3][0] = 0.0;     m[3][1] = 0.0; m[3][2] = 0.0;    m[3][3] = 1.0;

        return std::make_unique<Matrix>(m);
    }

    matrix_ptr matrix::rotateZ(double degrees) {
        double a { degreesToRadial(degrees) };

        Matrix m;

        m[0][0] = cos(a); m[0][1] = -sin(a); m[0][2] = 0.0; m[0][3] = 0.0;
        m[1][0] = sin(a); m[1][1] = cos(a);  m[1][2] = 0.0; m[1][3] = 0.0;
        m[2][0] = 0.0;    m[2][1] = 0.0;     m[2][2] = 1.0; m[2][3] = 0.0;
        m[3][0] = 0.0;    m[3][1] = 0.0;     m[3][2] = 0.0; m[3][3] = 1.0;

        return std::make_unique<Matrix>(m);
    }

    matrix_ptr matrix::randomAxisRotationMatrix(double x, double y, double z, double a) {
        Matrix t1 { *std::move(translationMatrix(-x, -y, -z)) };
        Matrix m1 { *std::move(randomAxisRotationMatrixToXYSpace(x, z)) };
        Matrix m2 { *std::move(randomAxisRotationMatrixToXAxis(x, y, z)) };
        Matrix m3 { *std::move(rotateX(-a)) };
        Matrix m4 { *std::move(randomAxisRotationMatrixFromXAxis(x, y, z)) };
        Matrix m5 { *std::move(randomAxisRotationMatrixFromXYSpace(x, z)) };
        Matrix t2 { *std::move(translationMatrix(x, y, z)) };

        auto tmp1 { *std::move(multiply(t1, m1)) };
        auto tmp2 { *std::move(multiply(tmp1, m2)) };
        auto tmp3 { *std::move(multiply(tmp2, m3)) };
        auto tmp4 { *std::move(multiply(tmp3, m4)) };
        auto tmp5 { *std::move(multiply(tmp4, m5)) };
        auto m { *std::move(multiply(tmp5, t2)) };

        return std::make_unique<Matrix>(m);
    }

    matrix_ptr matrix::randomAxisRotationMatrixToXYSpace(double x, double z) {
        Matrix m;

        auto xz = sqrt(pow(x,2)+pow(z,2));

        if (abs(xz) < EPSILON) {
            m[0][0] = 1.0; m[0][1] = 0.0; m[0][2] = 0.0; m[0][3] = 0.0;
            m[1][0] = 0.0; m[1][1] = 1.0; m[1][2] = 0.0; m[1][3] = 0.0;
            m[2][0] = 0.0; m[2][1] = 0.0; m[2][2] = 1.0; m[2][3] = 0.0;
            m[3][0] = 0.0; m[3][1] = 0.0; m[3][2] = 0.0; m[3][3] = 1.0;
        }
        else {
            m[0][0] = x/xz;  m[0][1] = 0.0; m[0][2] = z/xz; m[0][3] = 0.0;
            m[1][0] = 0.0;   m[1][1] = 1.0; m[1][2] = 0.0;  m[1][3] = 0.0;
            m[2][0] = -z/xz; m[2][1] = 0.0; m[2][2] = x/xz; m[2][3] = 0.0;
            m[3][0] = 0.0;   m[3][1] = 0.0; m[3][2] = 0.0;  m[3][3] = 1.0;
        }

        return std::make_unique<Matrix>(m);
    }

    matrix_ptr matrix::randomAxisRotationMatrixToXAxis(double x, double y, double z) {
        Matrix m;

        auto xz = sqrt(pow(x,2)+pow(z,2));
        auto xyz = sqrt(pow(x,2)+pow(y, 2)+pow(z,2));

        m[0][0] = xz/xyz; m[0][1] = y/xyz;  m[0][2] = 0.0; m[0][3] = 0.0;
        m[1][0] = -y/xyz; m[1][1] = xz/xyz; m[1][2] = 0.0; m[1][3] = 0.0;
        m[2][0] = 0.0;    m[2][1] = 0.0;    m[2][2] = 1.0; m[2][3] = 0.0;
        m[3][0] = 0.0;    m[3][1] = 0.0;    m[3][2] = 0.0; m[3][3] = 1.0;

        return std::make_unique<Matrix>(m);
    }

    matrix_ptr matrix::randomAxisRotationMatrixFromXAxis(double x, double y, double z) {
        Matrix m;

        auto xz = sqrt(pow(x,2)+pow(z,2));
        auto xyz = sqrt(pow(x,2)+pow(y, 2)+pow(z,2));

        m[0][0] = xz/xyz; m[0][1] = -y/xyz;  m[0][2] = 0.0; m[0][3] = 0.0;
        m[1][0] = y/xyz; m[1][1] = xz/xyz; m[1][2] = 0.0; m[1][3] = 0.0;
        m[2][0] = 0.0;    m[2][1] = 0.0;    m[2][2] = 1.0; m[2][3] = 0.0;
        m[3][0] = 0.0;    m[3][1] = 0.0;    m[3][2] = 0.0; m[3][3] = 1.0;

        return std::make_unique<Matrix>(m);
    }

    matrix_ptr matrix::randomAxisRotationMatrixFromXYSpace(double x, double z) {
        Matrix m;

        auto xz = sqrt(pow(x,2)+pow(z,2));

        if (abs(xz) < EPSILON) {
            m[0][0] = 1.0; m[0][1] = 0.0; m[0][2] = 0.0; m[0][3] = 0.0;
            m[1][0] = 0.0; m[1][1] = 1.0; m[1][2] = 0.0; m[1][3] = 0.0;
            m[2][0] = 0.0; m[2][1] = 0.0; m[2][2] = 1.0; m[2][3] = 0.0;
            m[3][0] = 0.0; m[3][1] = 0.0; m[3][2] = 0.0; m[3][3] = 1.0;
        }
        else {
            m[0][0] = x/xz; m[0][1] = 0.0; m[0][2] = -z/xz; m[0][3] = 0.0;
            m[1][0] = 0.0;  m[1][1] = 1.0; m[1][2] = 0.0;   m[1][3] = 0.0;
            m[2][0] = z/xz; m[2][1] = 0.0; m[2][2] = x/xz;  m[2][3] = 0.0;
            m[3][0] = 0.0;  m[3][1] = 0.0; m[3][2] = 0.0;   m[3][3] = 1.0;
        }

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

    matrix_ptr matrix::inverseMatrix(const models::point3d &right, const models::point3d &up,
                                     const models::point3d &direction) {
        Matrix m;

        const models::point3d& r { right }, u {up}, d {direction};

        m[0][0] = r.x(); m[0][1] = r.y(); m[0][2] = r.z(); m[0][3] = 0.0;
        m[1][0] = u.x(); m[1][1] = u.y(); m[1][2] = u.z(); m[1][3] = 0.0;
        m[2][0] = d.x(); m[2][1] = d.y(); m[2][2] = d.z(); m[2][3] = 0.0;
        m[3][0] = 0.0;   m[3][1] = 0.0;   m[3][2] = 0.0;   m[3][3] = 1.0;

        return std::make_unique<Matrix>(m);
    }

    double matrix::degreesToRadial(double degrees) {
        return degrees / 180.0 * PI;
    }

    void matrix::print(const Matrix &m) {
        auto rows = m.size();
        auto cols = m[0].size();

        std::cout << "--------------------------------------------\n";
        for (int r{0}; r<rows; r++) {
            std::string line;

            for (int c{0}; c<cols; c++) {
                line.append(" ");
                line.append(std::to_string(m[r][c]));
            }

            line.erase(0, 1);
            std::cout << line << "\n";
        }
        std::cout << "--------------------------------------------\n";
    }
}