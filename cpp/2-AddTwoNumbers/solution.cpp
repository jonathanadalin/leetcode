#include "solution.h"

namespace add_two_num {

bool AddTwoNum::TestsPass() {
  ListNode* l1 = new ListNode(1);
  ListNode* l2 = new ListNode(2);
  return DriveTest(l1, l2, 3);
}

bool AddTwoNum::DriveTest(ListNode* l1, ListNode* l2, int target) {
  ListNode* result = AddTwoNumbers(l1, l2);
}

std::vector<int> AddTwoNum::ConvertToVector(int num) {
  return {};
}

bool AddTwoNum::CheckResult(ListNode* l, int target) {
  std::vector<int> vector = ConvertToVector(target);
  int vector_i = 0;
  while (l != NULL && vector_i < vector.size()) {
    if (l->val != vector[vector_i]) {
      return false;
    }
    vector_i++; 
  }
  if (vector_i == vector.size()) {
    return true;
  } else {
  return false;
  }
}

ListNode* AddTwoNum::AddTwoNumbers(ListNode* l1, ListNode* l2,
                                  int last_carry) {
  return NULL;
}

}
