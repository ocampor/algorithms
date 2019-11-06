#define CATCH_CONFIG_MAIN

#import "../third_party/catch.h"
#import "../collections/linked_list.h"

TEST_CASE("linked list can be sized and append items", "[list]") {
    LinkedList<int> list{};
    list.append(1);
    list.append(2);

    REQUIRE(list.size() == 2);
    REQUIRE(!list.isEmpty());

    SECTION("Removing item changes size") {
        list.removeLast();
        REQUIRE(list.size() == 1);
    }

    SECTION("Removing item returns the value") {
        int value{list.removeLast()};
        REQUIRE(value == 2);
    }

    SECTION("Removing first item returns the first value") {
        int value{list.removeFirst()};
        REQUIRE(value == 1);
    }

    SECTION("isEmpty() returns true") {
        list.removeLast();
        list.removeLast();
        REQUIRE(list.isEmpty());
    }

    SECTION("getFirst returns the first item and does not remove it") {
        int value{list.getFirst()};
        REQUIRE(value == 1);
    }

    SECTION("getFirst returns the last item and does not remove it") {
        int value{list.getLast()};
        REQUIRE(value == 2);
    }

    SECTION("Removing item from empty list throws std::out_of_range") {
        list.removeLast();
        list.removeLast();
        REQUIRE_THROWS_AS(list.removeLast(), std::out_of_range);
        REQUIRE(list.size() == 0);
    }
}
