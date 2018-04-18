//Holland Ho
//Date:4/12/2018
//This header file holds the functions that call upon the Cart class
#include "functions.hpp"

// Insert code here to implement addProduct, display, and getProduct
void Cart::addProduct(Product singleProd)
 {
 contents[size] = singleProd;
 size++;
 }
void Cart::display()
 {
   for(int k = 0; k < size; k++)
   {
     cout<< k+1;
     contents[k].display();
   }
 }
Product Cart::getProduct(int prodNum)
 {
     return contents[prodNum-1];
     
 }
