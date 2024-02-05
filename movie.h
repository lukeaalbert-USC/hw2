#ifndef MOVIE_H
#define MOVIE_H
#include <iostream>
#include <string>
#include <set>
#include <vector>
#include <algorithm>

#include "product.h"

using namespace std;

class Movie: public Product 
{
  public: 
    Movie(const std::string category, const std::string name, double price, int qty, const std::string Genre, const std::string Rating);
    virtual ~Movie();

    virtual std::set<std::string> keywords() const;
    virtual std::string displayString() const;

    /**
    * Outputs the product info in the database format
    */
    virtual void dump(std::ostream& os) const;

    virtual void cartShow() const;

  private:
    std::string Genre_;
    std::string Rating_;
};

#endif