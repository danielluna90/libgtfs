#pragma once

#include <string>

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