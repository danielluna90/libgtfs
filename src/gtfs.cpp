#include "gtfs/gtfs.h"

#include <iostream>

GTFSFeed::GTFSFeed(const std::filesystem::path& path) : gtfs_path(path) {}

Result GTFSFeed::read_gtfs() {
  if (!std::filesystem::is_directory(gtfs_path))
    return Result(StatusCode::ERROR, ErrorCode::PATH_NOT_DIRECTORY);

  for (const std::filesystem::directory_entry& dir_entry :
       std::filesystem::directory_iterator(gtfs_path)) {
    std::cout << "Found file: " << dir_entry.path() << std::endl;
  }

  return Result(StatusCode::OK);
}