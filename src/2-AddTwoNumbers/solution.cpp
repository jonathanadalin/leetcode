#include "solution.h"

namespace add_two_num {

bool AddTwoNum::TestsPass() {
  ListNode* l = new ListNode(1);
  return DriveTest(l, {1});
}

bool AddTwoNum::DriveTest(ListNode* l, std::vector<int> nums) {
  int vector_i = 0;
  while (l != NULL && vector_i < nums.size()) {
    if (l->val != nums[vector_i]) {
      return false;
    }
    vector_i++; 
  }
  if (vector_i == nums.size()) {
    return true;
  } else {
  return false;
  }
}

ListNode* addTwoNumbers(ListNode* l1, ListNode* l2, int last_carry) {
  return NULL;
}

}
