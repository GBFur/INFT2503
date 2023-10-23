#include "Set.hpp"

int main() {
    Set set1 = {1, 4, 3};
    Set set2 = {4, 7};

    set1.print(); // Prints 1 4 3
    set2.print(); // Prints 4 7

    Set unionSet = set1 + set2;

    unionSet.print();

    set1 = set2; // Sets set1 1 4 3 to set2 4 7
    set1.print();

    set1.insert(5);
    set1.print(); // Prints 4 7 5

    set1.insert(8);
    set1.print(); // Prints 4 7 5 8
    
    return 0;
}
