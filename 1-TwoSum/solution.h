#include <vector>

namespace two_sum {

// Given an array of integers, return indices of the two numbers such that they
// add up to a specific target. Assume one solution and no same element twice.
std::vector<int> TwoSum(std::vector<int>& nums, int target);

// Returns true if all the tests have passed.
bool RunTests();

// Returns true if the indexes of nums are such that the values sum to target.
bool DriveTest(std::vector<int> nums, int target, std::vector<int> indexes); 

} 
