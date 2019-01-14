#ifndef ADD_TWO_NUM_H_
#define ADD_TWO_NUM_H_

#include "../problem.h"
#include "list_node.h"
#include <vector>

namespace add_two_num {

class AddTwoNum : public Problem {

 public:
  
  AddTwoNum() {
    this->set_name("Add Two Numbers");
    this->set_num(2);
    this->set_status(TestsPass());
  }

  // Returns true if all the tests have passed.
  bool TestsPass();

 private:

  // Drives a single instance of the test.
  bool DriveTest(ListNode* l1, ListNode* l2, int target);

  // Converts an integer to a vector of integers ie. 123 -> {1,2,3}
  std::vector<int> ConvertToVector(int num);

  // Verifies if the ListNode is equivalent to the target integer.
  bool CheckResult(ListNode* l, int target);
  
  // Returns a linked list of the sum of l1 and l2.
  ListNode* AddTwoNumbers(ListNode* l1, ListNode* l2, int last_carry = 0);

};

}

# endif  // ADD_TWO_NUM_H_
