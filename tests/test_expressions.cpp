#define CATCH_CONFIG_MAIN

#import "../third_party/catch.h"
#import "../expressions/arithmetic.h"

TEST_CASE("Arithmetic expression is correctly solved", "[evaluate]") {
    SECTION("Correctly evaluate ((2*5)+(5/2)+3+4)") {
        REQUIRE(evaluate("((2*5)+(5/2)+3+4)") == 19.5);
    }

    SECTION("Correctly evaluate 2+3*2/5+8") {
        REQUIRE(evaluate("2+3*2/5+8") == 11.2);
    }

    SECTION("Correctly evaluate (((3+4*2)+3)*5)") {
        REQUIRE(evaluate("(((3+4*2)+3)*5)") == 70);
    }
}