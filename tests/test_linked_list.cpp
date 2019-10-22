#define CATCH_CONFIG_MAIN

#import "../third_party/catch.h"
#import "../collections/linked_list.h"
#import <iostream>

TEST_CASE("linked list can be sized and append items", "[list]") {
    LinkedList<int> list = LinkedList<int>();
    list.append(1);
    list.append(2);

    REQUIRE(list.size() == 2);
    REQUIRE(!list.isEmpty());

    SECTION("Removing item changes size") {
        list.pop();
        REQUIRE(list.size() == 1);
    }

    SECTION("Removing item returns the value") {
        int value = list.pop();
        REQUIRE(value == 2);
    }

    SECTION("isEmpty() returns true") {
        list.pop();
        list.pop();
        REQUIRE(list.isEmpty());
    }

    SECTION("Removing item from empty list throws std::out_of_range") {
        list.pop();
        list.pop();
        REQUIRE_THROWS_AS(list.pop(), std::out_of_range);
        REQUIRE(list.size() == 0);
    }
}
