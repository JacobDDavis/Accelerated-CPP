#include <ios>
#include <iostream>
#include <string>
#include <unordered_map>

using std::cin;
using std::cout;
using std::endl;
using std::sort;
using std::streamsize;
using std::string;
using std::unordered_map;


int main()
{
  unordered_map<string, unsigned> dict;
  for (std::string word; std::cin >> word; ) {
    if(word == "-1") break;
    ++dict[word];
  }
  std::cout << "number of distinct words are: " << dict.size() << "\n";

  return 0;
}
