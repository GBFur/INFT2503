#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

bool isOdd(int value)
{
    return ((value % 2) == 1);
}

int main()
{
    vector<int> v1 = {3, 3, 12, 14, 17, 25, 30};
    vector<int> v1_replaced(v1.size()); // Create a vector of the same size as v1

    replace_copy_if(
        v1.begin(), v1.end(), v1_replaced.begin(), isOdd,
        100);

    cout << "v1: ";
    for (int n : v1)
    {
        cout << n << " ";
    }

    cout << endl;
    cout << "v1 with odd numbers replaced by 100: " << endl;
    for (int n : v1_replaced)
    {
        cout << n << " ";
    }
    cout << endl;

    return 0;
}
