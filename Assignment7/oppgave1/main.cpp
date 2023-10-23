//
// fraction/main.cpp
//
#include "fraction.hpp"
#include <iostream>
#include <string>

using namespace std;

void print(const string &text, const Fraction &broek)
{
  cout << text << broek.numerator << " / " << broek.denominator << endl;
}

int main()
{
  Fraction a(10, 20);
  Fraction b(3, 4);
  Fraction c;
  c.set(5);
  Fraction d = a / b;

  print("a = ", a);
  print("b = ", b);
  print("c = ", c);
  print("d = ", d);

  b += a;
  ++c;
  d *= d;

  print("b = ", b);
  print("c = ", c);
  print("d = ", d);

  c = a + b - d * a;
  c = -c;

  print("c = ", c);

  if (a + b != c + d)
    cout << "a + b != c + d" << endl;
  else
    cout << " a + b == c + d" << endl;
  while (b > a)
    b -= a;
  print("b = ", b);

  Fraction fraction(3, 4);
  Fraction e = fraction - 5;
  Fraction f = 5 - fraction;

  print("e = ", e); // e = -17 / 4
  print("f = ", f); // f = 17 / 4

  Fraction fraction1(1, 2); // 1/2
  Fraction fraction2(2, 3); // 2/3

  /**
   * Teori: Forklar hvordan 5 - 3 - fraction1 - 7 - fraction2 blir tolket. Hvilke versjoner av operatoren - blir brukt?

  first will be 5 - 3 where the built in substraction will be used.
  Since we now have 2 - fraction1 the int - Fraction overload operator for substraction will be used.
  now we have (2 - fraction1) - 7 then the Fraction - int overload operator for substraction will be used.
  Now we have 2 - fraction1 - 7) - fraction2, we have Fraction - Fraction the operator for that will be used.

  1 normal substraction
  both the Fraction overloads I made in a) was used
  and Fraction - Fraction was used.
  */
  Fraction result = 5 - 3 - fraction1 - 7 - fraction2;
  print("Result: ", result);
}

// Utskrift:
// a = 1 / 2
// b = 3 / 4
// c = 5 / 1
// d = 2 / 3
// b = 5 / 4
// c = 6 / 1
// d = 4 / 9
// c = -55 / 36
// a + b != c + d
// b = 1 / 4