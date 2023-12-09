#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

bool isFifteen(int value)
{
  return value > 15;
}

int main()
{
  vector<int> v1 = {3, 3, 12, 14, 17, 25, 30};

  // Store the first element greater than 15 in a variable
  vector<int>::iterator it = find_if(v1.begin(), v1.end(), isFifteen);

  if (it != v1.end()) // If we don't reach the end, we found an element greater than 15
  {
    cout << "First element greater than 15 is: " << *it << endl;
  }
  else
  {
    cout << "No element greater than 15 found." << endl;
  }

  return 0;
}
