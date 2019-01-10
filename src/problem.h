#include <string>

class Problem {

 public:

  bool TestsPass() { return false; }
  void set_name(std::string name) { this->name = name; }
  void set_num(int number) {this->number = number; }
  void set_status(bool status) {this->status = status; }
  std::string get_name() { return this->name; }
  int get_num() { return this->number; }
  bool get_status() { return this->status; }

 private:

  std::string name;
  int number;
  bool status;

};
