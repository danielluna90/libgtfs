#pragma once

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

enum ErrorCode {
  OK,
  ERROR,
};

class Result {
public:
  Result();

  bool IsSuccess();

  ErrorCode GetErrorCode();

private:
};

class GTFSFeed {
public:
  GTFSFeed(std::string directory);

  /**
   * @brief Reads GTFS files from directory provided.
   *
   * @return Result - Contains information about the result of reading GTFS
   * data.
   */
  Result read_gtfs();

  const Agency& get_agency(const std::string agency_id);

private:
  std::unordered_map<std::string, Agency> agencies;
};