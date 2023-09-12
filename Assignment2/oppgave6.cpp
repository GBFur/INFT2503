#include <iostream>

/**
 * points to the first element of an array,
 * the length specifices the number of elements to sum.
 * 
 */
int find_sum(const int *table, int length)
{
  int sum = 0;
  for (int i = 0; i < length; i++)
  {
    sum += table[i];
  }
  return sum;
}

int main()
{
  // Create and fill the table with 1, 2, 3 ... 18, 19, 20
  int array[20];
  for (int i = 0; i < 20; i++)
  {
    array[i] = i + 1;
  }

  std::cout << "Sum of the first 10 numbers: " << find_sum(array, 10) << std::endl;

  std::cout << "Sum of the next 5 numbers: " << find_sum(array + 10, 5) << std::endl;

  std::cout << "Sum of the last 5 numbers: " << find_sum(array + 15, 5) << std::endl;
}