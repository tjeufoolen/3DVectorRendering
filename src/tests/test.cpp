#define CATCH_CONFIG_MAIN // This tells Catch to provide a main() - only do this in one cpp file
#include <catch2/catch.hpp>

#include "objects/object.h"
#include "objects/cube.h"
#include "objects/pyramid.h"
#include "objects/spaceship.h"

#include "models/point3d.h"
#include "models/line3d.h"
#include "models/world.h"
#include "models/matrix.h"

using namespace models;

// TEST TRANSLATION MATRICES
TEST_CASE( "Translation matrix", "[matrices]" ) {
    SECTION( "translation matrix correctly filled positive coordinates" ) {
        // Arrange
        double tx { 6 }, ty { 7 }, tz { 8 };

        Matrix exp;
        exp[0][0] = 1.0; exp[0][1] = 0.0; exp[0][2] = 0.0; exp[0][3] = tx;
        exp[1][0] = 0.0; exp[1][1] = 1.0; exp[1][2] = 0.0; exp[1][3] = ty;
        exp[2][0] = 0.0; exp[2][1] = 0.0; exp[2][2] = 1.0; exp[2][3] = tz;
        exp[3][0] = 0.0; exp[3][1] = 0.0; exp[3][2] = 0.0; exp[3][3] = 1.0;

        // Act
        Matrix actual { *std::move(matrix::translationMatrix(tx, ty, tz)) };

        // Assert
        REQUIRE(actual == exp);
    }

    SECTION( "translation matrix correctly filled negative coordinates" ) {
        // Arrange
        double tx { -9 }, ty { -8 }, tz { -7 };

        Matrix exp;
        exp[0][0] = 1.0; exp[0][1] = 0.0; exp[0][2] = 0.0; exp[0][3] = tx;
        exp[1][0] = 0.0; exp[1][1] = 1.0; exp[1][2] = 0.0; exp[1][3] = ty;
        exp[2][0] = 0.0; exp[2][1] = 0.0; exp[2][2] = 1.0; exp[2][3] = tz;
        exp[3][0] = 0.0; exp[3][1] = 0.0; exp[3][2] = 0.0; exp[3][3] = 1.0;

        // Act
        Matrix actual { *std::move(matrix::translationMatrix(tx, ty, tz)) };

        // Assert
        REQUIRE(actual == exp);
    }
}
// END TEST TRANSLATION MATRICES

// TEST RADIAL CONVERSION
TEST_CASE( "Radial converter", "[matrices]" ) {
    SECTION( "Convert 0 degrees to radial" ) {
        // Arrange
        double degrees { 0 };

        // Act
        double actual { matrix::degreesToRadial(degrees) };

        // Assert
        REQUIRE(actual == 0);
    }

    SECTION( "Convert 90 degrees to radial" ) {
        // Arrange
        double degrees { 90 };

        // Act
        double actual { matrix::degreesToRadial(degrees) };

        // Assert
        REQUIRE(actual == (degrees / (180 / matrix::PI)));
    }

    SECTION( "Convert 1 degrees to radial" ) {
        // Arrange
        double degrees { 1 };

        // Act
        double actual { matrix::degreesToRadial(degrees) };

        // Assert
        REQUIRE(actual == (degrees / (180 / matrix::PI)));
    }

    SECTION( "Convert 720 degrees to radial" ) {
        // Arrange
        double degrees { 720 };

        // Act
        double actual { matrix::degreesToRadial(degrees) };

        // Assert
        REQUIRE(actual == (degrees / (180 / matrix::PI)));
    }
}
// END TEST RADIAL CONVERSION

// TEST AXIS ROTATION MATRICES
TEST_CASE( "Axis Rotation matrices", "[matrices]" ) {
    // X AXIS
    SECTION( "Rotate X correctly filled" ) {
        // Arrange
        double degrees { 45 };
        double radial { matrix::degreesToRadial(degrees) };

        Matrix exp;
        exp[0][0] = 1.0; exp[0][1] = 0.0;         exp[0][2] = 0.0;          exp[0][3] = 0.0;
        exp[1][0] = 0.0; exp[1][1] = cos(radial); exp[1][2] = -sin(radial); exp[1][3] = 0.0;
        exp[2][0] = 0.0; exp[2][1] = sin(radial); exp[2][2] = cos(radial);  exp[2][3] = 0.0;
        exp[3][0] = 0.0; exp[3][1] = 0.0;         exp[3][2] = 0.0;          exp[3][3] = 1.0;

        // Act
        Matrix actual { *std::move(matrix::rotateX(degrees)) };

        // Assert
        REQUIRE(actual == exp);
    }
    // END X AXIS

    // Y AXIS
    SECTION( "Rotate Y correctly filled" ) {
        // Arrange
        double degrees { 45 };
        double radial { matrix::degreesToRadial(degrees) };

        Matrix exp;
        exp[0][0] = cos(radial);  exp[0][1] = 0.0; exp[0][2] = sin(radial); exp[0][3] = 0.0;
        exp[1][0] = 0.0;          exp[1][1] = 1.0; exp[1][2] = 0.0;         exp[1][3] = 0.0;
        exp[2][0] = -sin(radial); exp[2][1] = 0.0; exp[2][2] = cos(radial); exp[2][3] = 0.0;
        exp[3][0] = 0.0;          exp[3][1] = 0.0; exp[3][2] = 0.0;         exp[3][3] = 1.0;

        // Act
        Matrix actual { *std::move(matrix::rotateY(degrees)) };

        // Assert
        REQUIRE(actual == exp);
    }
    // END Y AXIS

    // Z AXIS
    SECTION( "Rotate Z correctly filled" ) {
        // Arrange
        double degrees { 45 };
        double radial { matrix::degreesToRadial(degrees) };

        Matrix exp;
        exp[0][0] = cos(radial); exp[0][1] = -sin(radial); exp[0][2] = 0.0; exp[0][3] = 0.0;
        exp[1][0] = sin(radial); exp[1][1] = cos(radial);  exp[1][2] = 0.0; exp[1][3] = 0.0;
        exp[2][0] = 0.0;         exp[2][1] = 0.0;          exp[2][2] = 1.0; exp[2][3] = 0.0;
        exp[3][0] = 0.0;         exp[3][1] = 0.0;          exp[3][2] = 0.0; exp[3][3] = 1.0;

        // Act
        Matrix actual { *std::move(matrix::rotateZ(degrees)) };

        // Assert
        REQUIRE(actual == exp);
    }
    // END Z AXIS
}
// END TEST AXIS ROTATION MATRICES

// TEST MATRIX MULTIPLICATION
TEST_CASE( "Matrix multiplication", "[matrices]" ) {
    SECTION( "Multiply positive matrices" ) {
        // Arrange
        Matrix l { *std::move(matrix::translationMatrix(5,5,5)) };
        Matrix r { *std::move(matrix::translationMatrix(2,2,2)) };

        // Act
        Matrix result { *std::move(matrix::multiply(l, r)) };

        // Assert
        Matrix m;

        m[0][0] = 1.0; m[0][1] = 0.0; m[0][2] = 0.0; m[0][3] = 7.0;
        m[1][0] = 0.0; m[1][1] = 1.0; m[1][2] = 0.0; m[1][3] = 7.0;
        m[2][0] = 0.0; m[2][1] = 0.0; m[2][2] = 1.0; m[2][3] = 7.0;
        m[3][0] = 0.0; m[3][1] = 0.0; m[3][2] = 0.0; m[3][3] = 1.0;

        REQUIRE(result == m);
    }

    SECTION( "Multiply negative matrices" ) {
        // Arrange
        Matrix l { *std::move(matrix::translationMatrix(5,5,5)) };
        Matrix r { *std::move(matrix::translationMatrix(-1,-1,-1)) };

        // Act
        Matrix result { *std::move(matrix::multiply(l, r)) };

        // Assert
        Matrix m;

        m[0][0] = 1.0; m[0][1] = 0.0; m[0][2] = 0.0; m[0][3] = 4.0;
        m[1][0] = 0.0; m[1][1] = 1.0; m[1][2] = 0.0; m[1][3] = 4.0;
        m[2][0] = 0.0; m[2][1] = 0.0; m[2][2] = 1.0; m[2][3] = 4.0;
        m[3][0] = 0.0; m[3][1] = 0.0; m[3][2] = 0.0; m[3][3] = 1.0;

        REQUIRE(result == m);
    }
}
// END TEST MATRIX MULTIPLICATION

// TEST MATRIX AND VECTOR MULTIPLICATION
TEST_CASE( "Matrix x Vector multiplication", "[vectors, matrices]" ) {
    SECTION( "Multiply positive" ) {
        // Arrange
        point3d p { 100, 50, 100, 1 };
        Matrix  r { *std::move(matrix::translationMatrix(1, 1, 1)) };

        // Act
        p.transform(r);

        // Assert
        REQUIRE(p == point3d{101,51,101,1});
    }

    SECTION( "Multiply negative" ) {
        // Arrange
        point3d p { 100, 50, 100, 1 };
        Matrix  r { *std::move(matrix::translationMatrix(-1, -1, -1)) };

        // Act
        p.transform(r);

        // Assert
        REQUIRE(p == point3d{ 99, 49, 99, 1 });
    }
}
// END TEST MATRIX AND VECTOR MULTIPLICATION

// TEST SCALING MATRICES
TEST_CASE( "Scaling matrices", "[matrices]" ) {
    SECTION( "World space scale matrix correctly filled" ) {
        // Arrange
        double sx {1.5}, sy {1.5}, sz {1.5};

        Matrix exp;
        exp[0][0] = sx;  exp[0][1] = 0.0; exp[0][2] = 0.0; exp[0][3] = 0.0;
        exp[1][0] = 0.0; exp[1][1] = sy;  exp[1][2] = 0.0; exp[1][3] = 0.0;
        exp[2][0] = 0.0; exp[2][1] = 0.0; exp[2][2] = sz;  exp[2][3] = 0.0;
        exp[3][0] = 0.0; exp[3][1] = 0.0; exp[3][2] = 0.0; exp[3][3] = 1.0;

        // Act
        Matrix actual { *models::matrix::worldSpaceScalingMatrix(sx, sy, sz).get() };

        // Assert
        REQUIRE(actual == exp);
    }

    SECTION( "World space upscale matrix x Vector multiplication" ) {
        // Arrange
        Matrix m  { *std::move(models::matrix::worldSpaceScalingMatrix(1.5, 1.5, 1.5)) };
        point3d p { 100, 50, 100, 1 };

        // Act
        p.transform(m);

        // Assert
        REQUIRE(p == point3d{ 150, 75, 150, 1 });
    }

    SECTION( "World space downscale matrix x Vector multiplication" ) {
        // Arrange
        Matrix m  { *std::move(models::matrix::worldSpaceScalingMatrix(.5, .5, .5)) };
        point3d p { 100, 50, 100, 1 };

        // Act
        p.transform(m);

        // Assert
        REQUIRE(p == point3d{ 50, 25, 50, 1 });
    }

    SECTION( "Local space upscale matrix x Vector multiplication" ) {
        // Arrange
        point3d p { 100, 50, 100, 1 };
        Matrix m  { *std::move(models::matrix::localSpaceScalingMatrix(
                p.x(), p.y(), p.z(),1.5, 1.5, 1.5)) };

        // Act
        p.transform(m);

        // Assert
        REQUIRE(p == point3d{ 200, 100, 200, 1 });
    }

    SECTION( "Local space downscale matrix x Vector multiplication" ) {
        // Arrange
        point3d p { 100, 50, 100, 1 };
        Matrix m  { *std::move(models::matrix::localSpaceScalingMatrix(
                p.x(), p.y(), p.z(),.5, .5, .5)) };

        // Act
        p.transform(m);

        // Assert
        REQUIRE(p == point3d{ 0, 0, 0, 1 });
    }
}
// END TEST OBJECT CENTER

// TEST DOT PRODUCT
TEST_CASE( "Dot product", "[vectors]" ) {
    SECTION( "Dot product correct multiplication result positive" ) {
        // Arrange
        point3d l {1,1,1,1};
        point3d r {2,2,2,1};

        // Act
        double actual { l.dotProduct(r) };

        // Assert
        REQUIRE(actual == 6);
    }

    SECTION( "Dot product correct multiplication result negative" ) {
        // Arrange
        point3d l {-1,-1,-1,1};
        point3d r {2,2,2,1};

        // Act
        double actual { l.dotProduct(r) };

        // Assert
        REQUIRE(actual == -6);
    }
}
// END TEST DOT PRODUCT

// TEST CROSS PRODUCT
TEST_CASE( "Cross product", "[vectors, matrices]" ) {
    SECTION( "Cross product correct multiplication result positive" ) {
        // Arrange
        point3d l { 1, 0, 0, 1 };
        point3d r { 0, 1, 0, 1 };

        // Act
        point3d actual { l.crossProduct(r) };

        // Assert
        REQUIRE(actual == point3d{ 0, 0, 1, 1 });
    }

    SECTION( "Cross product correct multiplication result negative" ) {
        // Arrange
        point3d l { -1, 0, 0, 1 };
        point3d r { 0, -1, 0, 1 };

        // Act
        point3d actual { l.crossProduct(r) };

        // Assert
        REQUIRE(actual == point3d{ 0, 0, 1, 1 });
    }
}
// END TEST CROSS PRODUCT

// TEST VECTOR NORMALIZATION
TEST_CASE( "Vector normalization", "[vectors]" ) {
    SECTION( "Vector normalization positive" ) {
        // Arrange
        point3d p { 100, 100, 100, 1 };

        // Act
        p.normalize();

        // Assert
        REQUIRE(sqrt(p.dotProduct(p)) == 1);
    }

    SECTION( "Vector normalization negative" ) {
        // Arrange
        point3d p { -100, -100, -100, 1 };

        // Act
        p.normalize();

        // Assert
        REQUIRE(sqrt(p.dotProduct(p)) == 1);
    }
}
// END TEST VECTOR NORMALIZATION

// TEST VECTOR ADDITION
TEST_CASE( "Vector addition", "[vectors]" ) {
    SECTION( "Vector addition positive" ) {
        // Arrange
        point3d l { 100, 100, 100, 1 };
        point3d r { 100, 100, 100, 1 };

        // Act
        point3d p = l + r;

        // Assert
        REQUIRE(p == point3d{ 200, 200, 200, 1 });
    }

    SECTION( "Vector addition negative" ) {
        // Arrange
        point3d l { 100, 100, 100, 1 };
        point3d r { -100, -100, -100, 1 };

        // Act
        point3d p = l + r;

        // Assert
        REQUIRE(p == point3d{ 0, 0, 0, 1 });
    }
}
// END TEST VECTOR ADDITION

// TEST VECTOR SUBTRACTION
TEST_CASE( "Vector subtraction", "[vectors]" ) {
    SECTION( "Vector subtraction positive" ) {
        // Arrange
        point3d l { 100, 100, 100, 1 };
        point3d r { 100, 100, 100, 1 };

        // Act
        point3d p = l - r;

        // Assert
        REQUIRE(p == point3d{ 0, 0, 0, 1 });
    }

    SECTION( "Vector subtraction negative" ) {
        // Arrange
        point3d l { 100, 100, 100, 1 };
        point3d r { -100, -100, -100, 1 };

        // Act
        point3d p = l - r;

        // Assert
        REQUIRE(p == point3d{ 200, 200, 200, 1 });
    }
}
// END TEST VECTOR SUBTRACTION