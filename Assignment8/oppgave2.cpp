#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

template <typename Type1, typename Type2>
class Pair
{
public:
  Type1 element1;
  Type2 element2;

  Pair(Type1 element1, Type2 element2) : element1(element1), element2(element2) {}

  Pair<Type1, Type2> operator+(const Pair<Type1, Type2> &other) const
  {
    return Pair<Type1, Type2>(element1 + other.element1, element2 + other.element2);
  }

  bool operator>(const Pair<Type1, Type2> &other) const
  {
    return (element1 + element2) > (other.element1 + other.element2);
  }
};

int main()
{
  Pair<double, int> p1(3.5, 14);
  Pair<double, int> p2(2.1, 7);
  cout << "p1: " << p1.element1 << ", " << p1.element2 << endl;
  cout << "p2: " << p2.element1 << ", " << p2.element2 << endl;

  if (p1 > p2)
    cout << "p1 er størst" << endl;
  else
    cout << "p2 er størst" << endl;

  auto sum = p1 + p2;
  cout << "Sum: " << sum.element1 << ", " << sum.element2 << endl;
}