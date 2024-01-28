#include <iomanip>
#include <ios>
#include <iostream>
#include <sys/resource.h>

using namespace std;

int main(void) {
  const float coffeePrice = 1.25f;
  const float lattePrice = 4.75f;
  const float breakfastComboPrice = 12.104f;

  const size_t nameColumnLength = 20;
  const size_t priceColumnLength = 10;

  cout << left << fixed << showpoint << setprecision(2);

  cout << setfill('-') << setw(nameColumnLength + priceColumnLength) << ""
       << endl;
  cout << setfill(' ');

  cout << setw(nameColumnLength) << "Name" << setw(priceColumnLength) << "Price"
       << endl
       << setfill(' ');

  cout << setw(nameColumnLength) << "coffee" << setw(priceColumnLength)
       << coffeePrice << endl;
  cout << setw(nameColumnLength) << "latte" << setw(priceColumnLength)
       << lattePrice << endl;
  cout << setw(nameColumnLength) << "breakfast combo" << setw(priceColumnLength)
       << breakfastComboPrice << endl;

  return 0;
}