#include "solution.h"

namespace two_sum {

std::vector<int> TwoSum(std::vector<int>& nums, int target) {
  for (int i = 0; i < nums.size(); i++)
    for (int j = i + 1; j < nums.size(); j++)
      if (nums[i] + nums[j] == target)
        return {i, j};
}

bool RunTests() {
  std::vector<int> nums{2, 7, 11, 15};
  std::vector<int> result = TwoSum(nums, 9);
  if (result.at(0) == 0 && result.at(1) == 1)
    return true;
  return false;
}

};
