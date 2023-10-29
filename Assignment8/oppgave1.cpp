#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

template <typename Type>
bool equal(Type a, Type b)
{
  cout << "Using template function." << endl;
  return a == b;
}

// returns true if they are equal within a small tolerance
bool equal(double a, double b)
{
  cout << "Using special function" << endl;
  return (a - b) < 0.000001;
}

int main()
{
  int x = 4, y = 4;
  if (equal(x, y))
  {
    cout << x << " and " << y << " are equal." << endl;
  }
  else
  {
    cout << x << " and " << y << " are not equal." << endl;
  }

  double a = 3.154, b = 3.154;
  if (equal(a, b))
  {
    // setprecision(15) is used to print 15 digits after the decimal point.
    cout << setprecision(15) << a << " and " << b << " are equal." << endl;
  }
  else
  {
    cout << setprecision(15) << a << " and " << b << " are not equal." << endl;
  }

  return 0;
}
