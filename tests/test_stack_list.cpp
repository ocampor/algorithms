#import "../third_party/catch.h"
#import "../collections/stack.h"

TEST_CASE("stack can be sized and append items", "[stack]") {
    Stack<int> stack = Stack<int>();
    stack.push(1);
    stack.push(2);

    REQUIRE(stack.size() == 2);

    SECTION("Removing item returns the value") {
        int value = stack.pop();
        REQUIRE(value == 2);
    }

    SECTION("pop removes the last value") {
        int value = stack.pop();
        REQUIRE(stack.size() == 1);
        REQUIRE(value == 2);
    }

    SECTION("Removing item from empty list throws std::out_of_range") {
        stack.pop();
        stack.pop();
        REQUIRE_THROWS_AS(stack.pop(), std::out_of_range);
        REQUIRE(stack.size() == 0);
    }
}
