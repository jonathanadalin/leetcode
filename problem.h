#include <string>

class Problem {

 public:

  bool RunTests() { return false; }
  void set_name(std::string name) { this->name = name; }
  void set_num(int number) {this->number = number; }
  std::string get_name() { return this->name; }
  int get_num() { return this->number; }

 private:

  std::string name;
  int number;

};
