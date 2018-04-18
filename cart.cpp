//Holland Ho
//Date:4/12/2018
/* This program simulates a shopping cart where a user adds items to their cart and displays
   the contents of their cart. It's implementation uses the Cart and Product classes.
*/
#include <iostream>
#include <string>
#include "functions.hpp"

using namespace std;

int main()
{
  string prodName = ""; // Temporary holder of the product name
  double prodPrice = 0.0; // Temporary holder of the product price
  // Insert code here to create a Cart object
  Cart cart;
  int freeProdNum = 0; // Temporary holder for the product number


  cout << "Shopping cart v1.0" << endl;   // Display menu and questions
  cout << "==================" << endl;

  do
  {
    cout << "Please enter the name of the product you want to add (type q! to exit): "; // Get the name of the product
    getline(cin, prodName);
    if(prodName != "q!") // Check whether this is the name of the product or instruction to quit
    {
      cout << "Please enter the price of the product: "; // Get the price of the product
      cin >> prodPrice;
      cin.ignore();
      // Insert code here to create a Product object using the constructor that
      // accepts a product name and price
        Product prod(prodName, prodPrice); //Deleted Product prod;
      // Insert code here to add the product to the cart
      cart.addProduct(prod);
      cout << endl << prodName << " added to cart." << endl << endl;
    }
  }while(prodName != "q!");
  
    cout << endl << "Products purchased" << endl; // Display menu
  cout << "==================" << endl;
  // Insert code here to display the contents of the cart
  cart.display();
  cout << endl << "SURPRISE! We have a buy-one-get-one offer today! Which item would you like to get free? Input the product number: "; // Display surprise message and get product number of the free product
  cin >> freeProdNum;
  
  // Insert code here to retrieve the product from the cart based on the user's input
  // and assign to a Product object called freeProd
    prod freeprod = cart.getProduct(freeProdNum);
  // Insert code here to assign the name of the product to prodName
    prodName = prod freeprod;
  // Display information on the screen.  
  cout << endl << "Congratulations, you will get free " << prodName;

  // Insert code here to assign the price of the product to prodPrice
    prodPrice = prod freeprod;
  // Display information on the screen.
  cout << "! You just saved $" << prodPrice;
  cout << "! Happy shopping!" << endl; 
  return 0;
}
