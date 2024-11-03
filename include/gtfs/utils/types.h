#pragma once

#include <string>

template <typename T>
class Type {
public:
  Type(T t) : data(t) {}

  T GetData() { return data; }

  virtual bool IsValid() = 0;

protected:
  T data;
};

class ColorCode : public Type<std::string> {
public:
  ColorCode(std::string str);

  bool IsValid() { return true; }
};