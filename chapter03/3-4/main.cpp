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
    typedef string::size_type str_sz;
    string longest;
    str_sz longest_length = 0;
    string shortest;
    str_sz shortest_length = 0;
    
    cout << "Enter words :";
    std::unordered_map<std::string, unsigned> dict;
    for (std::string word; std::cin >> word; ) {
        if(word == "-1") break;
        ++dict[word];
        if (longest_length == 0 || word.size() > longest_length) {
            longest = word;
            longest_length = word.size();
        }
        
        if (shortest_length == 0 || word.size() < shortest_length) {
            shortest = word;
            shortest_length = word.size();
        }
    }
    std::cout << "Longest word: " << longest << "\n";
    std::cout << "Shortest word: " << shortest << "\n";
    
    return 0;
}

