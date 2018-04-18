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
  
  Product()
   {
     name = "Unnamed product";
     price = 0.0;
   }
  Product(string n, double p)
   {
     name = n;
     price = p;
   }
  void setName(string n)
   {
     name = n;
   }
  string getName()
   {
     return name;
   }
  void setPrice(double price)
   {
     price = p; 
   }
  double getPrice()
   {
     return price;
   }
  void display()
  {
    cout<< "1" << " x " << name << " @ "<< "$"<< price;\
  }
}; // Added ;

class Cart
{
  private:
  Product contents[100];
  int size;
  public:
  Cart()
  {
    size = 0;
  }
  int getSize()
  {
    return size;
  }
 void addProduct(Product singleProd);
 void display();
 void getProduct(Product prodNum);
}; //Added ;


#endif

