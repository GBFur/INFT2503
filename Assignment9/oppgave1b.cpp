#include <vector>
#include <algorithm>
#include <iostream>
#include <cmath>

using namespace std;

bool isApproximatelyEqual(int a, int b)
{
  return abs(a - b) <= 2;
}

int main()
{
  vector<int> v1 = {3, 3, 12, 14, 17, 25, 30};
  vector<int> v2 = {2, 3, 12, 14, 24};

  // Compare the first 5 elements of v1 with the first 5 elements of v2
  bool are_approx_equal_5 = equal(v1.begin(), v1.begin() + 5, v2.begin(), isApproximatelyEqual);

  cout << "First 5 elements of v1 and v2 are 'approximately equal'? : " << boolalpha << are_approx_equal_5 << endl;

  // Compare the first 4 elements of v1 with the first 4 elements of v2
  bool are_approx_equal_4 = equal(v1.begin(), v1.begin() + 4, v2.begin(), isApproximatelyEqual);

  cout << "First 4 elements of v1 and v2 are 'approximately equal'? : " << boolalpha << are_approx_equal_4 << endl;

  return 0;
}
