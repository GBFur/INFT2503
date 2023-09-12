#include <iostream>
#include <fstream>
#include <cstdlib>

void read_temperatures(double temperatures[], int length);

int main()
{

  const int length = 5;
  int temperatureUnder10 = 0;
  int temperatureBetween10And20 = 0;
  int temperatureOver20 = 0;

  std::cout << "Du skal skrive inn " << length << " temperaturer.\n";

  for (size_t i = 1; i <= length; i++)
  {
    double temp;
    std::cout << "Temperatur nr " << i << ": ";
    std::cin >> temp;

    if (temp < 10)
    {
      ++temperatureUnder10;
    }
    else if (temp >= 10 && temp <= 20)
    {
      ++temperatureBetween10And20;
    }
    else
    {
      ++temperatureOver20;
    }
  }

  std::cout << "Antall under 10 er: " << temperatureUnder10 << "\n";
  std::cout << "Antall mellom 10 og 20 er: " << temperatureBetween10And20 << "\n";
  std::cout << "Antall over 20 er: " << temperatureOver20 << "\n";

  // signal that the code finished
  return 0;
}