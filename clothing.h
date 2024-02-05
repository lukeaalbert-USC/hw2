#ifndef CLOTHING_H
#define CLOTHING_H
#include <iostream>
#include <string>
#include <set>
#include <vector>
#include <algorithm>

#include "product.h"

using namespace std;

class Clothing: public Product 
{
  public: 
    Clothing(const std::string category, const std::string name, double price, int qty, const std::string Sizee, const std::string Brand);
    virtual ~Clothing();

    virtual std::set<std::string> keywords() const;
    virtual std::string displayString() const;

    /**
    * Outputs the product info in the database format
    */
    virtual void dump(std::ostream& os) const;

  private:
    std::string Size_;
    std::string Brand_;
};

#endif