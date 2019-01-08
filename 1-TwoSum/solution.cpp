#include "solution.h"

namespace two_sum {

bool TwoSum::RunTests() {
  if (DriveTest({2, 7, 11, 15}, 9, {0, 1}) &&
      DriveTest({1, 2, 3, 8}, 10, {1, 3}) &&
      DriveTest({0, 10}, 10, {0, 1}) &&
      DriveTest({1, 5, 100, 20000, 4, 109090}, 9, {1, 4}))
    return true;
  else return false;
}

std::vector<int> TwoSum::ReturnIndices(std::vector<int>& nums, int target) {
  for (int i = 0; i < nums.size(); i++)
    for (int j = i + 1; j < nums.size(); j++)
      if (nums[i] + nums[j] == target)
        return {i, j};
}

bool TwoSum::DriveTest(std::vector<int> nums, int target, std::vector<int> indexes) {
  std::vector<int> result = ReturnIndices(nums, target);
  if (result.at(0) == indexes.at(0) && result.at(1) == indexes.at(1))
    return true;
  return false;
}

}
