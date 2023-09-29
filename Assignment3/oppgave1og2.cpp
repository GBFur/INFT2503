#include <iostream>
#include <string>

const double pi = 3.141592;

class Circle
{
public:
  Circle(double radius_); // circle -> Circle
  int get_area() const;
  double get_circumference() const;
  // private double radius; -> Private doesn't work here, moved this down

private:
  double radius;
}; // semicolon

// ==> Implementasjon av klassen Circle

Circle::Circle(double radius_) : radius(radius_) // radius_ to radius and radius to radius_
{
}

int Circle::get_area() const // const
{
  return pi * radius * radius;
}

double Circle::get_circumference() const // add double as declared in constructor
{
  double circumference = 2.0 * pi * radius;
  return circumference;

  //could also just return directly
  //return 2.0 * pi * radius;
}

// OPPGAVE 2 ---

#include <iostream>

using namespace std;

int main()
{
  Circle circle(5);

  double area = circle.get_area();
  cout << "Arealet er lik " << area << endl;

  double circumference = circle.get_circumference();
  cout << "Omkretsen er lik " << circumference << endl;
}