//Holland Ho
//Date:4/12/2018
//This header file holds the functions that call upon the Cart class
#include "functions.hpp"

// Insert code here to implement addProduct, display, and getProduct
void Cart::addProduct(Product singleProd)
 {
 contents[size] = singleProd; //the size of the contetnt
 size++;
 }
void Cart::display()
 {
   for(int k = 0; k < size; k++) //Function displays what's in the cart by counting through the contents array
   {
     cout<< k+1 <<". ";
     contents[k].display(); //calls upon on display function
   }
 }
Product Cart::getProduct(int prodNum)
 {
     return contents[prodNum-1]; //returns the object based on the user number input
     //subtracts 1 from prodNum because the array counts 1 ahead i.e input 2 would be 0,1,2 so subtract 1 from input
 }
