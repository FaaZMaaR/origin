#include <catch2/catch_test_macros.hpp>

#include <my_list.h>

TEST_CASE("Test List", "[list]") {
    SECTION("Test PushFront()") {
        List list{};
        list.PushFront(10);
        REQUIRE(list.Size() == 1);
    }
    SECTION("Test PushBack()") {
        List list{};
        list.PushBack(20);
        REQUIRE(list.Size() == 1);
    }
    SECTION("Test PopFront()") {
        List list{};
        list.PushFront(1);
        list.PushBack(2);
        REQUIRE(list.PopFront() == 1);
    }
    SECTION("Test PopBack()") {
        List list{};
        list.PushFront(1);
        list.PushBack(2);
        REQUIRE(list.PopBack() == 2);
    }
    SECTION("Test PopFront() for empty List") {
        List list{};
        REQUIRE_THROWS(list.PopFront());
    }
    SECTION("Test PopBack() for empty List") {
        List list{};
        REQUIRE_THROWS(list.PopBack());
    }
    SECTION("Complex Test List") {
        List list{};
        REQUIRE(list.Empty() == true);
        list.PushBack(200);
        list.PushFront(100);
        REQUIRE(list.Size() == 2);
        REQUIRE(list.PopBack() == 200);
        REQUIRE(list.PopFront() == 100);
        REQUIRE_THROWS(list.PopBack());
        REQUIRE_THROWS(list.PopFront());
    }
}