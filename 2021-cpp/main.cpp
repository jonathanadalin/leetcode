#include <iostream>
#include "1-TwoSum/solution.h"
#include "2-AddTwoNumbers/solution.h"

int main() {
  std::vector<Problem*> problems;
  problems.push_back(new two_sum::TwoSum());
  problems.push_back(new add_two_num::AddTwoNum());
  for (Problem* problem : problems) {
    std::cout << "Problem # " << problem->get_num() << ": "
                              << problem->get_name() << " - ";
    if (problem->get_status())
      std::cout << "PASS" << std::endl;
    else
      std::cout << "FAIL" << std::endl;
  }
}
