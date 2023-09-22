#include <iostream>
#include <string>

using namespace std;

const double sales_tax = 1.25;

class Commodity
{
public:
  Commodity(const string &name_, int id_, double price_);
  const string &get_name() const;
  int get_id() const;
  double get_price() const;
  double get_price(double quantity) const;
  double get_price_with_sales_tax(double quantity) const;
  void set_price(double price_);

private:
  string name;
  int id;
  double price;
};

Commodity::Commodity(const string &name_, int id_, double price_) : name(name_), id(id_), price(price_) {}

const string &Commodity::get_name() const
{
  return name;
}

int Commodity::get_id() const
{
  return id;
}

double Commodity::get_price() const
{
  return price;
}

double Commodity::get_price(double quantity) const
{
  return price * quantity;
}

double Commodity::get_price_with_sales_tax(double quantity) const
{
  return price * sales_tax * quantity;
}

void Commodity::set_price(double price_)
{
  price = price_;
}

int main()
{
  const double quantity = 2.5;
  Commodity commodity("Norvegia", 123, 73.50);

  cout << "Varenavn: " << commodity.get_name() << ", varenr: " << commodity.get_id()
       << " Pris pr enhet: " << commodity.get_price() << endl;

  cout << "Kilopris: " << commodity.get_price() << endl;
  cout << "Prisen for " << quantity << " kg er " << commodity.get_price(quantity)
       << " uten moms" << endl;
  cout << "Prisen for " << quantity << " kg er " << commodity.get_price_with_sales_tax(quantity)
       << " med moms" << endl;

  commodity.set_price(79.60);
  cout << "Ny kilopris: " << commodity.get_price() << endl;
  cout << "Prisen for " << quantity << " kg er " << commodity.get_price(quantity)
       << " uten moms" << endl;
  cout << "Prisen for " << quantity << " kg er " << commodity.get_price_with_sales_tax(quantity)
       << " med moms" << endl;
}

/* Utskrift:
Varenavn: Norvegia, varenr: 123 Pris pr enhet: 73.5
Kilopris: 73.5
Prisen for 2.5 kg er 183.75 uten moms
Prisen for 2.5 kg er 229.688 med moms
Ny kilopris: 79.6
Prisen for 2.5 kg er 199 uten moms
Prisen for 2.5 kg er 248.75 med moms
*/
