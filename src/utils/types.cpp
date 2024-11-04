#include "gtfs/utils/types.h"

ColorCode::ColorCode(std::string str) : Type(str) {}

bool ColorCode::IsValid() { return true; }

Latitude::Latitude(float f) : Type(f) {}

/**
 * @brief Checks if Latitude is valid.
 *
 * @return true - -90.0 <= Latitude <= 90.0
 * @return false - Otherwise
 */
bool Latitude::IsValid() { return -90.0f <= data && data <= 90.0f; }

Longitude::Longitude(float f) : Type(f) {}

/**
 * @brief Checks if Longitude is valid.
 *
 * @return true - -180.0 <= Longitude <= 180.0
 * @return false - Otherwise
 */
bool Longitude::IsValid() { return -180.0f <= data && data <= 180.0f; }

URL::URL(std::string str) : Type(str) {}

/**
 * @brief Checks if URL is valid.
 *
 * @return true - If URL follows format:
 * @return false - Otherwise
 */
bool URL::IsValid() { return true; }