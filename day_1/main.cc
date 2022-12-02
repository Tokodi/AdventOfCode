#include <algorithm>
#include <fstream>
#include <iostream>
#include <list>
#include <numeric>

int main(int argc, char *argv[]) {
  if (argc != 3){
    std::cout << "usage: day_1 <input_file> <#>" << std::endl;
    return 0;
  }

  std::ifstream input(argv[1]);
  if (!input.is_open()) {
    std::cout << "Could not open input file " << argv[1] << std::endl;
    return 0;
  }

  std::size_t number_of_packed_elves = std::stoul(argv[2]);

  std::list<std::uint32_t> high_calories(number_of_packed_elves);
  std::uint32_t cur_calories = 0;
  std::string line;
  while (std::getline(input, line)) {
    if (!line.empty()) {
      cur_calories += std::stoul(line); 
    } 
    
    if (line.empty() || input.peek() == std::ifstream::traits_type::eof()) {
      // Find the first element that is >= than cur_calories (if there is no such, it == high_calories.end())
      auto it = std::lower_bound(high_calories.begin(), high_calories.end(), cur_calories);
      if (it != high_calories.begin()) {
        high_calories.emplace(it, cur_calories);
        high_calories.pop_front();
      }
      cur_calories = 0;
    }
  }

  std::cout << "Sum calories of top " << number_of_packed_elves
            << " elves: " << std::reduce(high_calories.begin(), high_calories.end()) << std::endl;

  return 0;
}
