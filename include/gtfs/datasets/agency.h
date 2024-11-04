#pragma once

#include <string>

#include "gtfs/utils/datasets.h"
#include "gtfs/utils/types.h"

// From https://gtfs.org/documentation/schedule/reference/#agencytxt
class Agency : public Dataset {
public:
private:
  // Type: Unique ID, Conditionally Required
  std::string agency_id;

  // Type: Text, Required
  std::string agency_name;

  // Type: URL, Required
  URL agency_url;

  // Type: Timezone, Required
  std::string agency_timezone;

  // Type: Language Code, Optional
  std::string agency_language;

  // Type: Phone Number, Optional
  std::string agency_phone;

  // Type: URL, Optional
  URL agency_fare_url;

  // Type: Email, Optional
  std::string agency_email;
};