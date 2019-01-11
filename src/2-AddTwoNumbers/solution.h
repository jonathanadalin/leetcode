#ifndef ADD_TWO_NUM_H_
#define ADD_TWO_NUM_H_

#include "../problem.h"

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
  bool DriveTest(); 

};

}

# endif  // ADD_TWO_NUM_H_
