#include <iostream>
#include <string.h>

int main()
{
  int i = 3;
  int j = 5;
  int *p = &i;
  int *q = &j;

  std::cout << "Address of i: " << &i << " Value of i: " << i << std::endl;
  std::cout << "Address of j: " << &j << " Value of j: " << j << std::endl;
  std::cout << "Address of p: " << &p << " Value of p: " << p << " Pointer points to: " << *p << std::endl;
  std::cout << "Address of q: " << &q << " Value of q: " << q << " Pointer points to: " << *q << std::endl;

  *p = 7;
  *q += 4;     // *q + 4 -> 5 + 4 -> 9
  *q = *p + 1; // *p = 7 + 1 -> 8
  p = q;       // replaces the value of p with q which is 8

  //*p and *q should point to 8 and 8

  std::cout << *p << " " << *q << std::endl;

  // Oppgave 2----
  /**
   * This will get "Segmentation fault" because we're trying to copy data into
   * a pointer that's null (it points to nowhere in the memory). So the strcpy function
   * expects a valid memory location, which is not provided with line.
   */
  // char *line = nullptr; // eller char *line = 0;
  // strcpy(line, "Dette er en tekst");

  //----

  // Oppgave 3----
  /**
   * This code has several issues.
   * First of all, if a user doesn't provide a string with an "e" there's no break out of the loop
   * and it will loop forever. It needs a condition.
   *
   * The pointer could also go out of bounds of the text array since we're not stopping at the length of the array.
   * at *pointer = search_for; it's replacing the text with "e" until it finds an "e" in text.
   * So it's not "searching"
   */
  // char text[5];
  // char *pointer = text;
  // char search_for = 'e';
  // std::cin >> text;
  // while (*pointer != search_for)
  // {
  //   *pointer = search_for;
  //   std::cout << *pointer << std::endl;
  //   pointer++;
  // }

  //----

  // Oppgave 4 ----
  //  int a = 5;
  //  int &b; // not initialized
  //  int *c;
  //  c = &b; //can't assign c to the address of b if the address of b is not initialized
  //  *a = *b + *c; // a is not a pointer, it's a variable. same for *b which is &b also not a pointer
  //  &b = 2;       // can't assign a value to the address of b

  int a = 5;
  int &b = a;
  int *c;
  c = &b;
  a = b + *c;
  // a should be a + a -> 5+5 = 10
  std::cout << a << std::endl;
  b = 2;
  // since b is refering to a, this means a is b which is 2
  std::cout << a << std::endl;

  //----

  return 0;
}