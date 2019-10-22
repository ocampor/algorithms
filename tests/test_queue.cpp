#import "../third_party/catch.h"
#import "../collections/queue.h"

TEST_CASE("Queue can be sized and append items", "[Queue]") {
    Queue<int> queue = Queue<int>();
    queue.enqueue(1);
    queue.enqueue(2);

    REQUIRE(queue.size() == 2);

    SECTION("Removing item returns the value") {
        int value = queue.dequeue();
        REQUIRE(value == 1);
    }

    SECTION("removeLast removes the last value") {
        int value = queue.dequeue();
        REQUIRE(queue.size() == 1);
        REQUIRE(value == 1);
    }

    SECTION("Removing item from empty list throws std::out_of_range") {
        queue.dequeue();
        queue.dequeue();
        REQUIRE_THROWS_AS(queue.dequeue(), std::out_of_range);
        REQUIRE(queue.size() == 0);
    }
}
