#pragma once

#include <string>

/**
 * @brief Generic form of a <a
 * href="https://gtfs.org/documentation/schedule/reference/#field-types">GTFS
 * Field Type</a>.
 *
 * @tparam T - Type of the raw data which should be held and verified.
 */
template <typename T>
class Type {
public:
  Type(T t) : data(t) {}

  T GetData() { return data; }

  virtual bool IsValid() = 0;

protected:
  T data;
};

/**
 * @brief Represents a GTFS Color Field Type.
 *
 */
class ColorCode : public Type<std::string> {
public:
  ColorCode(std::string str);

  bool IsValid();
};

/**
 * @brief
 *
 */
class Date : public Type<std::string> {
public:
  Date(std::string str);

  bool IsValid();
};

/**
 * @brief
 *
 */
class Latitude : public Type<float> {
public:
  Latitude(float f);

  bool IsValid();
};

/**
 * @brief
 *
 */
class Longitude : public Type<float> {
public:
  Longitude(float f);

  bool IsValid();
};

/**
 * @brief
 *
 */
class URL : public Type<std::string> {
public:
  URL(std::string str);

  bool IsValid();
};