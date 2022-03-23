#include <Array.hpp>
#include <iostream>

using std::cout;

#define MAX_VAL 750
int main(int, char**) {
  Array<int> numbers(MAX_VAL);
  int* mirror = new int[MAX_VAL];
  srand(time(NULL));
  for (int i = 0; i < MAX_VAL; i++) {
    const int value = rand();
    numbers[i] = value;
    mirror[i] = value;
  }
  // SCOPE
  {
    Array<int> tmp = numbers;
    Array<int> test(tmp);
  }

  for (int i = 0; i < MAX_VAL; i++) {
    if (mirror[i] != numbers[i]) {
      std::cerr << "didn't save the same value!!" << std::endl;
      return 1;
    }
  }
  try {
    numbers[-2] = 0;
  } catch (const std::exception& e) {
    std::cerr << e.what() << '\n';
  }
  try {
    numbers[MAX_VAL] = 0;
  } catch (const std::exception& e) {
    std::cerr << e.what() << '\n';
  }

  for (int i = 0; i < MAX_VAL; i++) {
    numbers[i] = rand();
  }
  delete[] mirror;  //

  // Custom Tests
  {
    cout << "[printing out first 10 value of array]\n";
    for (int i = 0; i < 10; i++)
      cout << numbers[i] << ", ";
    cout << "...\n";
    cout << "[print size of array]\n";
    cout << numbers.size() << '\n';
  }
  {
    cout << "[setting value at index 0 to 0]\n";
    numbers[0] = 0;
  }
  {
    try {
      cout << "[printing out value at index -2]\n";
      cout << numbers[-2] << '\n';
    } catch (const std::exception& e) {
      std::cerr << e.what() << '\n';
    }
    try {
      cout << "[printing out value at index " << MAX_VAL << "]\n";
      cout << numbers[MAX_VAL] << '\n';
    } catch (const std::exception& e) {
      std::cerr << e.what() << '\n';
    }
    try {
      cout << "[assign value from index -2 to variable " << MAX_VAL << "]\n";
      int tmp = numbers[-2];
      (void)tmp;
    } catch (const std::exception& e) {
      std::cerr << e.what() << '\n';
    }
  }
  return 0;
}