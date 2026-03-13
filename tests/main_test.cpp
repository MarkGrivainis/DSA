/**
 * Copyright (c) 2024 Mark Grivainis
 * Test cases for LinkedList implementation
 *
 * This file uses the Catch2 testing framework to validate the functionality
 * of the LinkedList class defined in dsa/linked_list.hpp. It includes tests
 * for basic operations such as checking if the list is empty, pushing and
 * popping elements, and handling exceptions when popping from an empty list.
 *
 * To run these tests, ensure you have Catch2 installed and properly set up
 * in your development environment.
 */
#include <catch2/catch_test_macros.hpp>

#include "dsa/linked_list.hpp"

TEST_CASE("LinkedList basic operations", "[linked_list]") {
  dsa::LinkedList<int> list;

  SECTION("New list is empty") {
    REQUIRE(list.empty() == true);
    REQUIRE(list.size() == 0);
  }

  SECTION("Pushing elements increases size") {
    list.push_front(10);
    list.push_front(20);

    REQUIRE(list.size() == 2);
    // Last pushed is at the front
    REQUIRE(list.front() == 20);
  }

  SECTION("Popping elements decreases size") {
    list.push_front(10);
    list.pop_front();

    REQUIRE(list.empty() == true);
    REQUIRE(list.size() == 0);
  }

  SECTION("Popping from empty list throws exception") {
    REQUIRE_THROWS_AS(list.pop_front(), std::runtime_error);
  }
}
