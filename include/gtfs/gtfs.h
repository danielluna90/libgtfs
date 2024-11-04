#pragma once

#include <filesystem>
#include <string>
#include <unordered_map>

#include "datasets/agency.h"
#include "utils/results.h"
#include "utils/types.h"

class GTFSFeed {
public:
  /**
   * @brief Construct a new GTFSFeed object.
   *
   * @param path - Sets the path for the directory containing the GTFS data.
   */
  explicit GTFSFeed(const std::filesystem::path& path);

  /**
   * @brief Reads GTFS files from directory provided.
   *
   * @return Result - Contains information about the result of reading GTFS
   * data.
   */
  Result read_gtfs();

  const Agency& get_agency(const std::string agency_id) const;

private:
  std::filesystem::path gtfs_path;

  std::unordered_map<std::string, Agency> agencies;
};