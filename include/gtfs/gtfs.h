#pragma once

#include <filesystem>
#include <string>
#include <unordered_map>

#include "utils/types.h"

// From https://gtfs.org/documentation/schedule/reference/#agencytxt
class Agency {
public:
private:
  // Type: Unique ID, Conditionally Required
  std::string agency_id;

  // Type: Text, Required
  std::string agency_name;

  // Type: URL, Required
  std::string agency_url;

  // Type: Timezone, Required
  std::string agency_timezone;

  // Type: Language Code, Optional
  std::string agency_language;

  // Type: Phone Number, Optional
  std::string agency_phone;

  // Type: URL, Optional
  std::string agency_fare_url;

  // Type: Email, Optional
  std::string agency_email;
};

enum StatusCode {
  OK,
  ERROR,
};

enum ErrorCode {
  NOT_AVAILABLE,

  PATH_NOT_DIRECTORY,
  REQUIRED_FILE_MISSING
};

class Result {
public:
  explicit Result(const StatusCode code);
  explicit Result(const StatusCode code, const ErrorCode error);

  bool IsSuccess() { return code == StatusCode::OK; }

  ErrorCode GetErrorCode() { return error; }

private:
  StatusCode code;
  ErrorCode error;
};

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

  const Agency& get_agency(const std::string agency_id);

private:
  std::filesystem::path gtfs_path;

  std::unordered_map<std::string, Agency> agencies;
};