#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::sort;
using std::streamsize;
using std::string;
using std::vector;
using std::istream;


istream& read_words(istream& in, vector<string>& words)
{
  if (in) {
    //get rid of previous contents
    words.clear();

    //read words
    string s;
    while (in >> s) {
      if (s == "-1")
        break;
      words.push_back(s);
    }

    //clear the stream so that input will work for the next time
    in.clear();
  }
  return in;
}

int main()
{
  vector<string> words;
  read_words(cin, words);

  cout << "Number of words: " << words.size() << endl;

  sort(words.begin(), words.end());
  int count = 0;
  string lastWord = "";

  for(vector<string>::size_type i = 0; i < words.size(); ++i)
  {
    if(words[i] != lastWord)
    {
      if(lastWord != "")
        cout << lastWord << ": " << count << endl;
      lastWord = words[i];
      count = 1;
    }
    else
      count++;

  }
  cout << lastWord << ": " << count << endl;


}
