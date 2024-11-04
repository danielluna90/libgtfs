#include <gtfs/gtfs.h>

#include <catch2/catch_test_macros.hpp>
#include <iostream>

TEST_CASE("Test", "[Test 2]") {
  GTFSFeed feed("/");
  std::cout << feed.read_gtfs() << std::endl;
}