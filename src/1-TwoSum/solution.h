#ifndef TWO_SUM_H_
#define TWO_SUM_H_

#include "../problem.h"
#include <vector>

namespace two_sum {

class TwoSum : public Problem {

 public:
  
  TwoSum() {
    this->set_name("Two Sum");
    this->set_num(1);
    this->set_status(TestsPass());
  }

  // Returns true if all the tests have passed.
  bool TestsPass();

 private:

  // Given an array of integers, return indices of the two numbers such that they
  // add up to a specific target. Assume one solution and no same element twice.
  std::vector<int> ReturnIndices(std::vector<int>& nums, int target);

  // Returns true if the indexes of nums are such that the values sum to target.
  bool DriveTest(std::vector<int> nums, int target, std::vector<int> indexes); 

};

}

#endif  // TWO_SUM_H_ 
