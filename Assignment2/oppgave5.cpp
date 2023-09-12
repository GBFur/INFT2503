#include <iostream>

int main()
{
  double number;

  double *pointerNumber = &number;
  double &referenceNumber = number;

  number = 1;
  std::cout << "Method 1 of assigning number: " << number << std::endl;

  *pointerNumber = 2;
  std::cout << "Method 2 of assigning number: " << number << std::endl;

  referenceNumber = 3;
  std::cout << "Method 3 of assigning number: " << number << std::endl;

  return 0;
}