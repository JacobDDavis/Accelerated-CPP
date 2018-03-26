#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::vector;

int main() {
  vector<double> numbers;
  double x, sum, avg;

  while (cin >> x) {
    if (x == -1)
      break;
    numbers.push_back(x);
  }
  for (auto& num : numbers)
    sum += num;
  avg = sum / numbers.size();
  cout << "Average: " << avg << endl;

  return 0;
}
