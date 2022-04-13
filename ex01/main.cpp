#include <iostream>
#include "MyInt.hpp"
#include "iter.hpp"
#include "util.hpp"

using std::cout;

void printConstInt(const int& value) {
  cout << value << ", ";
}

int main() {
  {
    test::header("Int");
    int array[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    iter(array, 10, printConstInt);
    cout << "\n";
    iter(array, 10, printAny<int>);
    cout << "\n";
    iter(array, 10, printAny<const int>);
    cout << "\n";
    test::header("Const Int");
    const int constArray[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    iter(constArray, 10, printConstInt);
    cout << "\n";
    iter(constArray, 10, printAny);
    cout << "\n";
    iter(constArray, 10, printAny<int>);
    cout << "\n";
    iter(constArray, 10, printAny<const int>);
    cout << "\n";
  }
  {
    test::header("Double");
    double array[] = {1.1, 2.2, 3.3, 4.4, 5.5, 6.6, 7.7, 8.8, 9.9, 10.0};
    iter(array, 10, printAny<double>);
    cout << "\n";
  }
  {
    test::header("String");
    string array[] = {"one", "two",   "three", "four", "five",
                      "six", "seven", "eight", "nine", "ten"};
    iter(array, 10, printAny);
    cout << "\n";
  }
  {
    test::header("Custom Object");
    MyInt array[5];
    iter(array, 5, printAny);
    cout << "\n";
  }
  return 0;
}
