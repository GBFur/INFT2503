#include <iostream>
#include <string.h>

int main()
{
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