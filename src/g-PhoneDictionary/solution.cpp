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
  bool MappingExists(int num, char c) {
    auto it = map.find(num);
    if (it == map.end()) {
      return false;
    } 
    else {
      return ((*it).second.find(c) != (*it).second.end());
    }
  }
 private:
  std::map< int, std::unordered_set<char> > map;
};

std::vector<std::string> GetMatchingPermutations(
    const std::vector<int> &numbers, const std::vector<std::string> &words) {
  Cellphone cp;
  std::vector<std::string> matches(words);
  int i = 0;

  // We can eliminate words that don't match the input vector length.
  for (auto word_it = matches.begin(); word_it != matches.end(); ++word_it) {
    if ((*word_it).length() != numbers.size()) {
      word_it = matches.erase(word_it - 1);
    }
  }

  for (auto num : numbers) {
    for (auto word_it = matches.begin(); word_it != matches.end(); ++word_it) {
      if (i >= (*word_it).length()) {
        word_it = matches.erase(word_it) - 1;
      } else {
        if (!cp.MappingExists(num, (*word_it).at(i))) {
          word_it = matches.erase(word_it) - 1;
        }
      }
    }
    i++;
  }
  return matches;
}

bool TestSolutionPasses(const std::vector<int> &numbers,
                        const std::vector<std::string> &words,
                        const std::vector<std::string> &expected_matches) {
  std::vector<std::string> matches = GetMatchingPermutations(numbers, words);
  return matches == expected_matches;
}

main() {
  std::vector<int> numbers {2,3,2};
  std::vector<std::string> words {"AEC", "WUT", "BAD", "OK", "AAAA"};
  std::vector<std::string> expected_matches {"AEC"};
  if (TestSolutionPasses(numbers, words, expected_matches)) {
    std::cout << "PASS" << std::endl;
  } else {
    std::cout << "FAIL" << std::endl;
    std::cout << "Expected matches ";
    for (auto word : expected_matches) {
      std::cout << word << " ";
    }
    std::cout << std::endl << "Our matches      ";
    std::vector<std::string> our_matches = GetMatchingPermutations(numbers, words);
    for (auto word : our_matches) {
      std::cout << word << " ";
    }
    std::cout << std::endl;
  }
}