#define CATCH_CONFIG_MAIN

#import "../third_party/catch.h"
#import "../expressions/arithmetic.h"

TEST_CASE("Arithmetic expression is correctly solved", "[evaluate]") {
    SECTION("Correctly evaluate ((2*5)+(5/2)+3+4)") {
        float expected{19.5};
        REQUIRE(evaluate("((2*5)+(5/2)+3+4)") == expected);
    }

    SECTION("Correctly evaluate 2+3*2/5+8") {
        float expected{11.2};
        REQUIRE(evaluate("2+3*2/5+8") == expected);
    }

    SECTION("Correctly evaluate (((3+4*2)+3)*5)") {
        float expected{70};
        REQUIRE(evaluate("(((3+4*2)+3)*5)") == expected);
    }

    SECTION("Correctly evaluates expressions with a single literal") {
        REQUIRE(evaluate("5") == 5.0);
    }
}