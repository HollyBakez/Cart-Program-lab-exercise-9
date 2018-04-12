/*
MIT License

Copyright (c) 2018 Paul Salvador Inventado

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
*/

#include "catch.hpp"
#include <sstream>
#include <string>
#include <stdlib.h>
#include <time.h>
#include <iostream>
#include <iomanip>
#include <fstream>
#include "functions.hpp"

#include <random>

using namespace std;

string couttest(string progName, string input)
{
  FILE *fp = popen(("echo \""+ input +"\" | ./" + progName).c_str(), "r");
  char buf[1024];
  string output = "";
  while (fgets(buf, 1024, fp)) {
    output += buf;
  }
  pclose(fp);  
  return output;
}

string to_string_double(double val, const int prec = 2)
{
    std::ostringstream out;
    out << fixed << setprecision(prec) << val;
    return out.str();
}

string func_str_out(function<void()> func)
{
  // code for capturing cout taken from
  // https://stackoverflow.com/questions/19485536/redirect-output-of-an-function-printing-to-console-to-string
  std::stringstream ss;
  auto old_buf = std::cout.rdbuf(ss.rdbuf()); 
  func();
  std::cout.rdbuf(old_buf);
  return ss.str();
}

string generate_string(int max_length){
    string possible_characters = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
    random_device rd;
    mt19937 engine(rd());
    uniform_int_distribution<> dist(0, possible_characters.size()-1);
    string ret = "";
    for(int i = 0; i < max_length; i++){
        int random_index = dist(engine); //get index between 0 and possible_characters.size()-1
        ret += possible_characters[random_index];
    }
    return ret;
}

TEST_CASE("Product", "[product]")
{
  srand(time(NULL));
  SECTION("Object creation (Default constructor)")
  {
    Product prod;
    CHECK(true == true);
  }
  SECTION("Object creation (Constructor overload)")
  {
    Product prod("name", 0.0);
    CHECK(true == true);
  }
  SECTION("Default constructor")
  {
    Product prod;
    CHECK(prod.getName() == "Unnamed product");
    CHECK(prod.getPrice() == 0.0);
  }
  SECTION("Constructor overload - assigning name and price")
  {
    for(int i = 0; i < 10; i++)
    {
      string randName = generate_string(rand()%10);
      double randPrice = rand() / RAND_MAX;
      Product prod(randName, randPrice);
      CHECK(prod.getName() == randName);
      CHECK(prod.getPrice() == randPrice);
    }
  }
  SECTION("Getters and setters design")
  {
      string randName = generate_string(rand()%10);
      double randPrice = rand() / RAND_MAX;
      Product prod;
      prod.setName(randName);
      prod.setPrice(randPrice);
      prod.getName();
      prod.getPrice(); 
      CHECK(true == true);
  }
  SECTION("Getters and setters implementation")
  {
    for(int i = 0; i < 10; i++)
    {
      string randName = generate_string(rand()%10);
      double randPrice = rand() / RAND_MAX;
      Product prod;
      prod.setName(randName);
      prod.setPrice(randPrice);
      CHECK(prod.getName() == randName);
      CHECK(prod.getPrice() == randPrice);
    }
  }
  SECTION("Product information display")
  {
      string randName = generate_string(rand()%10);
      double randPrice = rand() / RAND_MAX;
      Product prod(randName, randPrice);
      string result = func_str_out([&] (){
        prod.display();
      });
      string output = "1 x " + randName + " @ $" + to_string_double(randPrice) + "\n";
      CHECK(result == output);
  }
}

TEST_CASE("Cart", "[cart]")
{
  SECTION("Object creation")
  {
    Cart c;
    CHECK(true == true); 
  }
  SECTION("Cart constructor with default values")
  {
    Cart c;
    CHECK(c.getSize() == 0);
  }
  SECTION("addProduct function header")
  {
    Cart c;
    Product p;
    c.addProduct(p);
    CHECK(true == true);
  }
  SECTION("addProduct implementation - size increase")
  {
    for(int j = 0; j < 10; j++)
    {
      Cart c;
      int cartSize = rand() %10;
      for(int i = 0; i < cartSize; i++)
      {
        Product temp;
        c.addProduct(temp);
      }
      CHECK(c.getSize() == cartSize);
    }
  }
  SECTION("addProduct implementation - insertion to array and using getProduct")
  {
    for(int j = 0; j < 10; j++)
    {
      Cart c;
      int cartSize = rand() %10;
      Product prods[cartSize];
      for(int i = 0; i < cartSize; i++)
      {
        Product temp;
        c.addProduct(temp);
        prods[i] = temp;
      }
      CHECK(c.getSize() == cartSize);
      for(int i = 0; i < cartSize; i++)
      {
        CHECK(c.getProduct(i+1).getName() == prods[i].getName());
        CHECK(c.getProduct(i+1).getPrice() == prods[i].getPrice());
      }
    }
  }
  SECTION("Displaying cart contents")
  {
    for(int j = 0; j < 10; j++)
    {
      Cart c;
      int cartSize = rand() %10;
      string expected;
      for(int i = 0; i < cartSize; i++)
      {
        string randName = generate_string(rand()%10);
        double randPrice = rand() / RAND_MAX;
        Product prod(randName, randPrice);
        c.addProduct(prod);
        expected += to_string(i+1) +". 1 x " + randName + " @ $" + to_string_double(randPrice) + "\n";
      }
      string result = func_str_out([&] (){
        c.display();
      });
      CHECK(result == expected);
    }
  }
}
