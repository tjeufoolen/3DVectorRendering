#define CATCH_CONFIG_MAIN // This tells Catch to provide a main() - only do this in one cpp file
#include <catch2/catch.hpp>

#include "models/matrix.h"

constexpr static const double PI = 3.14159265358979323846;

// TEST TRANSLATION MATRICES
TEST_CASE( "Translation matrix", "[matrix]" ) {
    SECTION( "translation matrix correctly filled positive coordinates" ) {
        // Arrange
        double tx = 6, ty = 7, tz = 8;

        models::Matrix exp;
        exp[0][0] = 1.0; exp[0][1] = 0.0; exp[0][2] = 0.0; exp[0][3] = tx;
        exp[1][0] = 0.0; exp[1][1] = 1.0; exp[1][2] = 0.0; exp[1][3] = ty;
        exp[2][0] = 0.0; exp[2][1] = 0.0; exp[2][2] = 1.0; exp[2][3] = tz;
        exp[3][0] = 0.0; exp[3][1] = 0.0; exp[3][2] = 0.0; exp[3][3] = 1.0;

        // Act
        models::Matrix actual = {*models::matrix::translationMatrix(tx, ty, tz).get()};

        // Assert
        REQUIRE(actual == exp);
    }

    SECTION( "translation matrix correctly filled negative coordinates" ) {
        // Arrange
        double tx = -9, ty = -8, tz = -7;

        models::Matrix exp;
        exp[0][0] = 1.0; exp[0][1] = 0.0; exp[0][2] = 0.0; exp[0][3] = tx;
        exp[1][0] = 0.0; exp[1][1] = 1.0; exp[1][2] = 0.0; exp[1][3] = ty;
        exp[2][0] = 0.0; exp[2][1] = 0.0; exp[2][2] = 1.0; exp[2][3] = tz;
        exp[3][0] = 0.0; exp[3][1] = 0.0; exp[3][2] = 0.0; exp[3][3] = 1.0;

        // Act
        models::Matrix actual = {*models::matrix::translationMatrix(tx, ty, tz).get()};

        // Assert
        REQUIRE(actual == exp);
    }
}
// END TEST TRANSLATION MATRICES

// TEST RADIAL CONVERSION
TEST_CASE( "Radial converter", "[matrix]" ) {
    SECTION( "Convert 0 degrees to radial" ) {
        // Arrange
        double degrees = 0;
        double expected = 0;

        // Act
        double actual = models::matrix::degreesToRadial(degrees);

        // Assert
        REQUIRE(actual == expected);
    }

    SECTION( "Convert 90 degrees to radial" ) {
        // Arrange
        double degrees = 90;
        double expected = degrees / (180 / PI);

        // Act
        double actual = models::matrix::degreesToRadial(degrees);

        // Assert
        REQUIRE(actual == expected);
    }

    SECTION( "Convert 1 degrees to radial" ) {
        // Arrange
        double degrees = 1;
        double expected = degrees / (180 / PI);

        // Act
        double actual = models::matrix::degreesToRadial(degrees);

        // Assert
        REQUIRE(actual == expected);
    }

    SECTION( "Convert 720 degrees to radial" ) {
        // Arrange
        double degrees = 720;
        double expected = degrees / (180 / PI);

        // Act
        double actual = models::matrix::degreesToRadial(degrees);

        // Assert
        REQUIRE(actual == expected);
    }
}
// END TEST RADIAL CONVERSION

// TEST ROTATION MATRICES
TEST_CASE( "Rotation matrix", "[matrix]" ) {

    // X AXIS
    SECTION( "10 degree rotation around X axis" ) {
        // Arrange
        double degrees = 10;
        double radial = models::matrix::degreesToRadial(degrees);

        models::Matrix exp;
        exp[0][0] = 1.0; exp[0][1] = 0.0;         exp[0][2] = 0.0;          exp[0][3] = 0.0;
        exp[1][0] = 0.0; exp[1][1] = cos(radial); exp[1][2] = -sin(radial); exp[1][3] = 0.0;
        exp[2][0] = 0.0; exp[2][1] = sin(radial); exp[2][2] = cos(radial);  exp[2][3] = 0.0;
        exp[3][0] = 0.0; exp[3][1] = 0.0;         exp[3][2] = 0.0;          exp[3][3] = 1.0;

        // Act
        models::Matrix actual = {*models::matrix::rotateX(degrees).get()};

        // Assert
        REQUIRE(actual == exp);
    }
    SECTION( "90 degree rotation around X axis" ) {
        // Arrange
        double degrees = 90;
        double radial = models::matrix::degreesToRadial(degrees);

        models::Matrix exp;
        exp[0][0] = 1.0; exp[0][1] = 0.0;         exp[0][2] = 0.0;          exp[0][3] = 0.0;
        exp[1][0] = 0.0; exp[1][1] = cos(radial); exp[1][2] = -sin(radial); exp[1][3] = 0.0;
        exp[2][0] = 0.0; exp[2][1] = sin(radial); exp[2][2] = cos(radial);  exp[2][3] = 0.0;
        exp[3][0] = 0.0; exp[3][1] = 0.0;         exp[3][2] = 0.0;          exp[3][3] = 1.0;

        // Act
        models::Matrix actual = {*models::matrix::rotateX(degrees).get()};

        // Assert
        REQUIRE(actual == exp);
    }
    SECTION( "0 degree rotation around X axis" ) {
        // Arrange
        double degrees = 0;
        double radial = models::matrix::degreesToRadial(degrees);

        models::Matrix exp;
        exp[0][0] = 1.0; exp[0][1] = 0.0;         exp[0][2] = 0.0;          exp[0][3] = 0.0;
        exp[1][0] = 0.0; exp[1][1] = cos(radial); exp[1][2] = -sin(radial); exp[1][3] = 0.0;
        exp[2][0] = 0.0; exp[2][1] = sin(radial); exp[2][2] = cos(radial);  exp[2][3] = 0.0;
        exp[3][0] = 0.0; exp[3][1] = 0.0;         exp[3][2] = 0.0;          exp[3][3] = 1.0;

        // Act
        models::Matrix actual = {*models::matrix::rotateX(degrees).get()};

        // Assert
        REQUIRE(actual == exp);
    }
    // END X AXIS

    // Y AXIS
    SECTION( "10 degree rotation around Y axis" ) {
        // Arrange
        double degrees = 10;
        double radial = models::matrix::degreesToRadial(degrees);

        models::Matrix exp;
        exp[0][0] = cos(radial);  exp[0][1] = 0.0; exp[0][2] = sin(radial); exp[0][3] = 0.0;
        exp[1][0] = 0.0;          exp[1][1] = 1.0; exp[1][2] = 0.0;         exp[1][3] = 0.0;
        exp[2][0] = -sin(radial); exp[2][1] = 0.0; exp[2][2] = cos(radial); exp[2][3] = 0.0;
        exp[3][0] = 0.0;          exp[3][1] = 0.0; exp[3][2] = 0.0;         exp[3][3] = 1.0;

        // Act
        models::Matrix actual = {*models::matrix::rotateY(degrees).get()};

        // Assert
        REQUIRE(actual == exp);
    }
    SECTION( "90 degree rotation around Y axis" ) {
        // Arrange
        double degrees = 90;
        double radial = models::matrix::degreesToRadial(degrees);

        models::Matrix exp;
        exp[0][0] = cos(radial);  exp[0][1] = 0.0; exp[0][2] = sin(radial); exp[0][3] = 0.0;
        exp[1][0] = 0.0;          exp[1][1] = 1.0; exp[1][2] = 0.0;         exp[1][3] = 0.0;
        exp[2][0] = -sin(radial); exp[2][1] = 0.0; exp[2][2] = cos(radial); exp[2][3] = 0.0;
        exp[3][0] = 0.0;          exp[3][1] = 0.0; exp[3][2] = 0.0;         exp[3][3] = 1.0;

        // Act
        models::Matrix actual = {*models::matrix::rotateY(degrees).get()};

        // Assert
        REQUIRE(actual == exp);
    }
    SECTION( "0 degree rotation around Y axis" ) {
        // Arrange
        double degrees = 0;
        double radial = models::matrix::degreesToRadial(degrees);

        models::Matrix exp;
        exp[0][0] = cos(radial);  exp[0][1] = 0.0; exp[0][2] = sin(radial); exp[0][3] = 0.0;
        exp[1][0] = 0.0;          exp[1][1] = 1.0; exp[1][2] = 0.0;         exp[1][3] = 0.0;
        exp[2][0] = -sin(radial); exp[2][1] = 0.0; exp[2][2] = cos(radial); exp[2][3] = 0.0;
        exp[3][0] = 0.0;          exp[3][1] = 0.0; exp[3][2] = 0.0;         exp[3][3] = 1.0;

        // Act
        models::Matrix actual = {*models::matrix::rotateY(degrees).get()};

        // Assert
        REQUIRE(actual == exp);
    }
    // END Y AXIS

    // Z AXIS
    SECTION( "10 degree rotation around Z axis" ) {
        // Arrange
        double degrees = 10;
        double radial = models::matrix::degreesToRadial(degrees);

        models::Matrix exp;
        exp[0][0] = cos(radial); exp[0][1] = -sin(radial); exp[0][2] = 0.0; exp[0][3] = 0.0;
        exp[1][0] = sin(radial); exp[1][1] = cos(radial);  exp[1][2] = 0.0; exp[1][3] = 0.0;
        exp[2][0] = 0.0;         exp[2][1] = 0.0;          exp[2][2] = 1.0; exp[2][3] = 0.0;
        exp[3][0] = 0.0;         exp[3][1] = 0.0;          exp[3][2] = 0.0; exp[3][3] = 1.0;

        // Act
        models::Matrix actual = {*models::matrix::rotateZ(degrees).get()};

        // Assert
        REQUIRE(actual == exp);
    }
    SECTION( "90 degree rotation around Z axis" ) {
        // Arrange
        double degrees = 90;
        double radial = models::matrix::degreesToRadial(degrees);

        models::Matrix exp;
        exp[0][0] = cos(radial); exp[0][1] = -sin(radial); exp[0][2] = 0.0; exp[0][3] = 0.0;
        exp[1][0] = sin(radial); exp[1][1] = cos(radial);  exp[1][2] = 0.0; exp[1][3] = 0.0;
        exp[2][0] = 0.0;         exp[2][1] = 0.0;          exp[2][2] = 1.0; exp[2][3] = 0.0;
        exp[3][0] = 0.0;         exp[3][1] = 0.0;          exp[3][2] = 0.0; exp[3][3] = 1.0;

        // Act
        models::Matrix actual = {*models::matrix::rotateZ(degrees).get()};

        // Assert
        REQUIRE(actual == exp);
    }
    SECTION( "0 degree rotation around Z axis" ) {
        // Arrange
        double degrees = 0;
        double radial = models::matrix::degreesToRadial(degrees);

        models::Matrix exp;
        exp[0][0] = cos(radial); exp[0][1] = -sin(radial); exp[0][2] = 0.0; exp[0][3] = 0.0;
        exp[1][0] = sin(radial); exp[1][1] = cos(radial);  exp[1][2] = 0.0; exp[1][3] = 0.0;
        exp[2][0] = 0.0;         exp[2][1] = 0.0;          exp[2][2] = 1.0; exp[2][3] = 0.0;
        exp[3][0] = 0.0;         exp[3][1] = 0.0;          exp[3][2] = 0.0; exp[3][3] = 1.0;

        // Act
        models::Matrix actual = {*models::matrix::rotateZ(degrees).get()};

        // Assert
        REQUIRE(actual == exp);
    }
    // END Z AXIS
}
// END TEST ROTATION MATRICES