#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main()
{
  vector<double> numbers = {1.0, 2.0, 3.0, 4.0, 5.0};

  cout << numbers.back() << endl;
  cout << numbers.front() << endl;

  numbers.emplace(numbers.begin() + 1, 1.5);
  cout << numbers.front() << endl; // Still 1.0 since we inserted at index 1 and not 0

  double valueToFind = 3.0;
  auto it = find(numbers.begin(), numbers.end(), valueToFind);
  if (it != numbers.end())
  {
    cout << "Found " << valueToFind << " at index " << it - numbers.begin() << endl;
  }
  else
  {
    cout << "Could not find " << valueToFind << endl;
  }

  return 0;
}
