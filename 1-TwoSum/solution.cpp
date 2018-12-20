#include "solution.h"

namespace two_sum {

std::vector<int> TwoSum(std::vector<int>& nums, int target) {
  for (int i = 0; i < nums.size(); i++)
    for (int j = i + 1; j < nums.size(); j++)
      if (nums[i] + nums[j] == target)
        return {i, j};
}

bool RunTests() {
  return true;  // TODO
}

};
