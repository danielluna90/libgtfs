#include <gtfs/gtfs.h>

#include <catch2/catch_test_macros.hpp>

TEST_CASE("Test", "[Test 2]") {
  GTFSFeed feed("/");
  feed.read_gtfs();
}