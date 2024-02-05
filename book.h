#ifndef BOOK_H
#define BOOK_H
#include <iostream>
#include <string>
#include <set>
#include <vector>
#include <algorithm>

#include "product.h"

using namespace std;

class Book: public Product 
{
  public: 
    Book(const std::string category, const std::string name, double price, int qty, const std::string ISBN, const std::string Author);
    ~Book(); 

    std::set<std::string> keywords() const;
    std::string displayString() const;

    /**
    * Outputs the product info in the database format
    */
    void dump(std::ostream& os) const;

  private:
    std::string ISBN_;
    std::string Author_;
};

#endif