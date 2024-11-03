#include "gtfs/utils/types.h"

#include <iostream>

void test();

void test() {
  ColorCode cc = ColorCode("Hello");
  std::cout << cc.GetData() << std::endl;
  std::cout << cc.IsValid() << std::endl;
}

ColorCode::ColorCode(std::string str) : Type(str) {}