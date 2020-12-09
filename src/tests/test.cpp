#define CATCH_CONFIG_MAIN // This tells Catch to provide a main() - only do this in one cpp file
#include <catch2/catch.hpp>

// Matrices
#include "models/matrix.h"

TEST_CASE( "Translation matrix", "[matrix]" ) {
    SECTION( "translation matrix correctly filled positive coordinates" ) {
        // Arrange
        double tx = 6, ty = 7, tz = 8;

        models::Matrix expected;
        expected[0][0] = 1.0; expected[0][1] = 0.0; expected[0][2] = 0.0; expected[0][3] = tx;
        expected[1][0] = 0.0; expected[1][1] = 1.0; expected[1][2] = 0.0; expected[1][3] = ty;
        expected[2][0] = 0.0; expected[2][1] = 0.0; expected[2][2] = 1.0; expected[2][3] = tz;
        expected[3][0] = 0.0; expected[3][1] = 0.0; expected[3][2] = 0.0; expected[3][3] = 1.0;

        // Act
        models::Matrix actual = { *models::matrix::translationMatrix(tx,ty,tz).get() };

        // Assert
        REQUIRE(actual == expected);
    }

    SECTION( "translation matrix correctly filled negative coordinates" ) {
        // Arrange
        double tx = -9, ty = -8, tz = -7;

        models::Matrix expected;
        expected[0][0] = 1.0; expected[0][1] = 0.0; expected[0][2] = 0.0; expected[0][3] = tx;
        expected[1][0] = 0.0; expected[1][1] = 1.0; expected[1][2] = 0.0; expected[1][3] = ty;
        expected[2][0] = 0.0; expected[2][1] = 0.0; expected[2][2] = 1.0; expected[2][3] = tz;
        expected[3][0] = 0.0; expected[3][1] = 0.0; expected[3][2] = 0.0; expected[3][3] = 1.0;

        // Act
        models::Matrix actual = { *models::matrix::translationMatrix(tx,ty,tz).get() };

        // Assert
        REQUIRE(actual == expected);
    }
}
// End matrices