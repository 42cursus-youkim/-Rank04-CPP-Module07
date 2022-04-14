#include <Array.hpp>
#include <iostream>
#include "util.hpp"

using std::cout;

#define MAX_VAL 750

void test_mandatory() {
  test::header("Mandatory");
  Array<int> numbers(MAX_VAL);
  int* mirror = new int[MAX_VAL];
  srand(time(NULL));
  for (int i = 0; i < MAX_VAL; i++) {
    const int value = rand();
    numbers[i] = value;
    mirror[i] = value;
  }
  {
    test::subject("Scope");
    Array<int> tmp = numbers;
    Array<int> test(tmp);
  }

  test::subject("Values are copied");
  for (int i = 0; i < MAX_VAL; i++)
    assert(mirror[i] == numbers[i]);
  try {
    test::subject("Accessing invalid index -2");
    numbers[-2] = 0;
  } catch (const std::exception& e) {
    std::cerr << RED << e.what() << '\n';
  }
  try {
    test::subject("Assigning invalid index MAX_VAL=750");
    numbers[MAX_VAL] = 0;
  } catch (const std::exception& e) {
    std::cerr << RED << e.what() << '\n';
  }

  for (int i = 0; i < MAX_VAL; i++)
    numbers[i] = rand();

  delete[] mirror;  //
}

void test_int() {
  test::header("Int");
  {
    test::subject("Accessing invalid index 0 @ Empty Array");
    Array<int> a;
    try {
      cout << a[0] << ", ";
    } catch (std::out_of_range& e) {
      cout << RED "Exception: " << e.what() << "\n";
    }
  }
  {
    test::subject("Constructor with size 10");
    Array<int> a(10);
    TEST_EXPECT(a.size() == 10);
    try {
      test::subject("Accessing invalid index 10");
      for (int i = 0; i <= 10; i++)
        cout << a[i] << ", ";
    } catch (std::exception& e) {
      cout << RED "Exception: " << e.what() << "\n";
    }
  }
  {
    test::subject("Copy Constructor");
    Array<int> a(10);
    for (int i = 0; i < 10; i++)
      a[i] = i;

    Array<int> copied(a);
    TEST_EXPECT(a.size() == copied.size());
    for (int i = 0; i < 10; i++)
      assert(a[i] == copied[i]);
    test::subject("Deep Copied");
    for (int i = 0; i < 10; i++)
      a[i] = i + 10;
    for (int i = 0; i < 10; i++)
      assert(a[i] != copied[i]);
  }
  {
    test::subject("Assignment Operator");
    Array<int> a(10);
    for (int i = 0; i < 10; i++)
      a[i] = i;

    Array<int> assigned(100);
    assigned = a;
    TEST_EXPECT(a.size() == assigned.size());
    for (int i = 0; i < 10; i++)
      assert(a[i] == assigned[i]);
    for (int i = 0; i < 10; i++)
      a[i] = i + 10;
    test::subject("Deep Copied");
    for (int i = 0; i < 10; i++)
      assert(a[i] != assigned[i]);
  }
}

void test_string() {
  test::header("String");
  Array<string> arr(10);
  for (int i = 0; i < 10; i++)
    arr[i] = string(i, '=');
  for (int i = 0; i < 10; i++)
    cout << arr[i] << ", ";
  test::subject("Deep Copied");
  Array<string> copied(arr);
  for (int i = 0; i < 10; i++)
    arr[i] += "(modified)";
  for (int i = 0; i < 10; i++)
    assert(arr[i] != copied[i]);
}

int main(int, char**) {
  test_int();
  test_string();
  test_mandatory();
  cout << END "\n";
  // #include <cstdlib>
  // system("leaks prog.out");
  return 0;
}
