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
  bool DriveTest(ListNode* l, std::vector<int> nums);
  
  // Returns a linked list of the sum of l1 and l2.
  ListNode* addTwoNumbers(ListNode* l1, ListNode* l2, int last_carry);

};

}

# endif  // ADD_TWO_NUM_H_
