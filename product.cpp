/* This program asks the user to input information about a product
   and uses this to create a Product object. The Product object's
   display function is used to show information about it.
*/

#include <iostream>
#include <string>
#include "functions.hpp"

using namespace std;

int main()
{
  string prodName; // name of the product
  double prodPrice; // price of the product
  // Get details about the product
  cout << "Please enter the name of the product: ";
  getline(cin, prodName);
  cout << "Please enter the price of the product: ";
  cin >> prodPrice;
  // Insert code here to create the Product object using the appropriate constructor
  Product prod();
  // that uses name and price from the user.
  Product prod (prodName, prodPrice);
  // Insert code here that calls the display function to show information about the product.
  prod.display();
  return 0;
}
