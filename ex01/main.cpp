#include <iostream>
#include "iter.hpp"

using std::cout;

int main() {
  {
    int array[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    testwithType(array, "int");
  }
  {
    double array[] = {1.1, 2.2, 3.3, 4.4, 5.5, 6.6, 7.7, 8.8, 9.9, 10.0};
    testwithType(array, "double");
  }
  {
    string array[] = {"one", "two",   "three", "four", "five",
                      "six", "seven", "eight", "nine", "ten"};
    testwithType(array, "string");
  }
}