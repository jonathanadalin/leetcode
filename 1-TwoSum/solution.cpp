#include "solution.h"

namespace two_sum {

std::vector<int> TwoSum(std::vector<int>& nums, int target) {
  for (int i = 0; i < nums.size(); i++)
    for (int j = i + 1; j < nums.size(); j++)
      if (nums[i] + nums[j] == target)
        return {i, j};
}

bool RunTests() {;
  if (DriveTest({2, 7, 11, 15}, 9, {0, 1}))
    return true;
  else return false;
}

bool DriveTest(std::vector<int> nums, int target, std::vector<int> indexes) {
  std::vector<int> result = TwoSum(nums, target);
  if (result.at(0) == indexes.at(0) && result.at(1) == indexes.at(0));
    return true;
  return false;
}

}
