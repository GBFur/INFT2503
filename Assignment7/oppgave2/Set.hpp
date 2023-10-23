#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Set
{
private:
  std::vector<int> data;

public:
  // Constructor to create an empty set
  Set() {}

  // Constructor to initialize set with another set
  Set(const Set &other) : data(other.data) {}

  // Constructor to initialize set with a list of values
  Set(std::initializer_list<int> list) : data(list)
  {
    data.erase(std::unique(data.begin(), data.end()), data.end()); // Remove duplicates
  }

  // Check what the union is of two sets
  Set operator+(const Set &other) const
  {
    Set result = *this;
    for (int value : other.data)
    {
      result.insert(value);
    }
    return result;
  }

  // Insert a value into the set
  // If the value already exists, do nothing
  void insert(int value)
  {
    if (std::find(data.begin(), data.end(), value) == data.end())
    {
      data.push_back(value);
    }
  }

  // Set a set equal to another set
  Set &operator=(const Set &other)
  {
    data = other.data;
    return *this;
  }

  // Print the set
  void print()
  {
    cout << "";
    for (int value : data)
    {
      cout << value << " ";
    }
    cout << "" << endl;
  }
};
