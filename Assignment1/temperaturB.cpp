#include <iostream>
#include <fstream>

void read_temperatures(double temperatures[], int length);

int main()
{

  const int length = 5;
  double temperatures[length];

  int temperatureUnder10 = 0;
  int temperatureBetween10And20 = 0;
  int temperatureOver20 = 0;

  read_temperatures(temperatures, length);

  for (int i = 0; i < length; i++)
  {
    if (temperatures[i] < 10)
    {
      temperatureUnder10++;
    }
    else if (temperatures[i] >= 10 && temperatures[i] <= 20)
    {
      temperatureBetween10And20++;
    }
    else
    {
      temperatureOver20++;
    }
  }

  std::cout << "Antall under 10 er: " << temperatureUnder10 << std::endl;
  std::cout << "Antall mellom 10 og 20 er: " << temperatureBetween10And20 << std::endl;
  std::cout << "Antall over 20 er: " << temperatureOver20 << std::endl;

  // signal that the code finished
  return 0;
}

void read_temperatures(double temperatures[], int length)
{
  const char filename[] = "temperatur.dat";
  std::ifstream file;
  file.open(filename);

  if (!file)
  {
    std::cout << "Feil ved åpning av innfil." << std::endl;
    std::exit(EXIT_FAILURE);
  }

  for (int i = 0; i < length; i++)
  {
    {
      file >> temperatures[i];
    }
  }
  file.close();
}