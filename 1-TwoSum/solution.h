#include "../problem.h"
#include <vector>

namespace two_sum {

class TwoSum : Problem {

 public:
  
  // Returns true if all the tests have passed.
  bool RunTests();

 private:

  // Given an array of integers, return indices of the two numbers such that they
  // add up to a specific target. Assume one solution and no same element twice.
  std::vector<int> ReturnIndices(std::vector<int>& nums, int target);

  // Returns true if the indexes of nums are such that the values sum to target.
  bool DriveTest(std::vector<int> nums, int target, std::vector<int> indexes); 

};

} 
