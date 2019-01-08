#include <iostream>
#include "1-TwoSum/solution.h"

int main() {
  std::vector<Problem*> problems;
  // TODO Fix slicing
  problems.push_back(new two_sum::TwoSum());
  for (Problem* problem : problems) {
    std::cout << "Problem # " << problem->get_num() << ": "
                              << problem->get_name() << " - ";
    if (problem->get_status())
      std::cout << "PASS" << std::endl;
    else
      std::cout << "FAIL" << std::endl;
  }
}
