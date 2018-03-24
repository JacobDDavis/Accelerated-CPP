#include <iostream>
#include <string>
#include <unordered_map>

using std::cin;
using std::cout;
using std::endl;
using std::streamsize;
using std::string;



int main()
{
  std::unordered_map<std::string, unsigned> dict;
  for (std::string word; std::cin >> word; ) {
    if(word == "-1") break;
    ++dict[word];
  }
  std::cout << "number of distinct words are: " << dict.size() << "\n";

  return 0;
}

