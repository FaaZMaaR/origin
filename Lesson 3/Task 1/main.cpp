#include <catch2/catch_test_macros.hpp>

#include <my_list.h>

TEST_CASE("Test List", "[list]") {
    SECTION("Test Empty()") {
        List list{};
        REQUIRE(list.Empty() == true);
    }
    SECTION("Test Size()") {
        List list{};
        list.PushBack(3);
        list.PushBack(4);
        list.PushFront(2);
        list.PushFront(1);
        REQUIRE(list.Size() == 4);
    }
    SECTION("Test Clear()") {
        List list{};
        list.PushBack(3);
        list.PushBack(4);
        list.PushFront(2);
        list.PushFront(1);
        list.Clear();
        REQUIRE(list.Size() == 0);
        REQUIRE(list.Empty() == true);
    }
}