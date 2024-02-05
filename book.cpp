#include <sstream>
#include <string>
#include <iomanip>
#include "util.h"
#include "book.h"

using namespace std;

Book::Book(const std::string category, const std::string name, double price, int qty, const std::string ISBN, const std::string Author) :
  Product(category, name, price, qty),
  ISBN_(ISBN),
  Author_(Author)
{
}

Book::~Book()
{

}

std::set<std::string> Book::keywords() const
{
  std::set<std::string> toRet;

  std::set<std::string> tempOne = parseStringToWords(name_);
  string x = convToLower(name_);
  toRet.insert(trim(x));

  set<std::string>::iterator itrA;

  for (itrA = tempOne.begin(); 
       itrA != tempOne.end(); itrA++) 
  {
    toRet.insert(*itrA);
  }


  std::set<std::string> tempTwo = parseStringToWords(Author_);
  string y = convToLower(Author_);
  toRet.insert(trim(y));

  set<std::string>::iterator itrB;

  for (itrB = tempTwo.begin(); 
      itrB != tempTwo.end(); itrB++) 
  {
    toRet.insert(*itrB);
  }

  std::set<std::string> tempThree = parseStringToWords(ISBN_);
  string z = convToLower(ISBN_);
  toRet.insert(trim(z));

  set<std::string>::iterator itrC;

  for (itrC = tempThree.begin(); 
    itrC != tempThree.end(); itrC++) 
  {
    toRet.insert(*itrC);
  }

  return toRet;
}


std::string Book::displayString() const
{
  std::string toRet;

  toRet.append(name_); 
  toRet.append("\n");
  toRet.append("Author: ");
  toRet.append(Author_);
  toRet.append(" ISBN: ");
  toRet.append(ISBN_);
  toRet.append("\n");
  
  stringstream forPrice;
  forPrice << std::fixed << std::setprecision(2) << price_;
  std::string newPrice = forPrice.str();
  toRet.append(newPrice);

  toRet.append(" ");
  toRet.append(std::to_string(qty_));
  toRet.append(" left.");
  //MAY NEED TO ADD ADDITONAL NEWL HERE!!!!!!!

  return toRet;
}

void Book::dump(std::ostream& os) const
{
    os << category_ << "\n" << name_ << "\n" << price_ << "\n" << qty_ << "\n" << ISBN_ << "\n" << Author_ << endl;
}