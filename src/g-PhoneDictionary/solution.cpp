#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <unordered_set>

class Cellphone {
 public:
  Cellphone() {
    std::unordered_set<char> letters_for_2 {'A', 'B', 'C'};
    std::unordered_set<char> letters_for_3 {'D', 'E', 'F'};
    std::unordered_set<char> letters_for_4 {'G', 'H', 'I'};
    std::unordered_set<char> letters_for_5 {'J', 'K', 'L'};
    std::unordered_set<char> letters_for_6 {'M', 'N', 'O'};
    std::unordered_set<char> letters_for_7 {'P', 'Q', 'R', 'S'};
    std::unordered_set<char> letters_for_8 {'T', 'U', 'V'};
    std::unordered_set<char> letters_for_9 {'W', 'X', 'Y', 'Z'};
    map.insert(std::make_pair(2, letters_for_2));
    map.insert(std::make_pair(3, letters_for_3));
    map.insert(std::make_pair(4, letters_for_4));
    map.insert(std::make_pair(5, letters_for_5));
    map.insert(std::make_pair(6, letters_for_6));
    map.insert(std::make_pair(7, letters_for_7));
    map.insert(std::make_pair(8, letters_for_8));
    map.insert(std::make_pair(9, letters_for_9));
  }
 private:
  std::map< int, std::unordered_set<char> > map;
};

std::vector<std::string> getPermutations(const std::vector<int> &numbers,
                                         const std::vector<std::string> &words)
{
  Cellphone cp;
  return words;
}

main()
{
  std::cout << "Hello, world." << std::endl;
}