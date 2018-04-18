//Holland Ho
//Date:4/12/2018
//This program stores the classes and functions that are used in the product and cart int main
#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

# ifndef FUNCTIONS_HPP // This code prevents multiple includes of functions.hpp
# define FUNCTIONS_HPP

// Insert code here for the product Class and the Cart class
class Product
{
 private:
  string name;
  double price;
 public:
  
  Product() //Default constructor
   {
     name = "Unnamed product";
     price = 0.0;
   }
  Product(string n, double p) //Constructor that sets the name and price
   {
     name = n;
     price = p;
   }
  void setName(string n)
   {
     name = n;
   }
  string getName() //Returns the name of said object
   {
     return name;
   }
  void setPrice(double p)
   {
     price = p; 
   }
  double getPrice() //Returns price of said object
   {
     return price;
   }
  void display() //Display function that shows the price, amount, and product name
  {
      cout<< "1" << " x " << name << " @ "<< "$";
      cout<<fixed<<setprecision(2); // sets into 2 decimal places
      cout<<price<<endl;
  }
}; // Added ;

class Cart //Cart class that has the size of the cart and the prototypes to add, display, and get the products
{
  private:
  Product contents[100];
  int size;
  public:
  Cart() //Constructor, sets the initial size to 0
  {
    size = 0;
  }
  int getSize()
  {
    return size;
  }
 void addProduct(Product singleProd); //Function prototypes
 void display();
 Product getProduct(int prodNum);
}; //Added ;


#endif

