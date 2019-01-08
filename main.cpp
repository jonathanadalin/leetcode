#include <iostream>
#include "1-TwoSum/solution.h"

int main() {
  two_sum::TwoSum* test = new two_sum::TwoSum();
  if (test->RunTests())
    std::cout << "Success" << std::endl;
  else
    std::cout << "Hello, world." << std::endl;
}
