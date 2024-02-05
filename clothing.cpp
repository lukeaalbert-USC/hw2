#include <sstream>
#include <string>
#include <iomanip>
#include "util.h"
#include "clothing.h"

using namespace std;

Clothing::Clothing(const std::string category, const std::string name, double price, int qty, const std::string Sizee, const std::string Brand) :
  Product(category, name, price, qty),
  Size_(Sizee),
  Brand_(Brand)
{
}

Clothing::~Clothing()
{

}

std::set<std::string> Clothing::keywords() const
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


  std::set<std::string> tempTwo = parseStringToWords(Brand_);
  string y = convToLower(Brand_);
  toRet.insert(trim(y));

  set<std::string>::iterator itrB;

  for (itrB = tempTwo.begin(); 
      itrB != tempTwo.end(); itrB++) 
  {
    toRet.insert(*itrB);
  }

  return toRet;
}


std::string Clothing::displayString() const
{
  std::string toRet;

  toRet.append(name_); 
  toRet.append("\n");
  toRet.append("Size: ");
  toRet.append(Size_);
  toRet.append(" Brand: ");
  toRet.append(Brand_);
  toRet.append("\n");
  toRet.append(std::to_string(price_));
  toRet.append(" ");
  toRet.append(std::to_string(qty_));
  toRet.append(" left.");
  //MAY NEED TO ADD ADDITONAL NEWL HERE!!!!!!!


  return toRet;
}

void Clothing::dump(std::ostream& os) const
{
    os << category_ << "\n" << name_ << "\n" << price_ << "\n" << qty_ << "\n" << Size_ << "\n" << Brand_ << endl;
}

void Clothing::cartShow() const
{
  std::cout << "name: ";
  std::cout << name_;
  std::cout << ", \n";

  std::cout << "info: ";
  std::cout << "Size: ";
  std::cout <<Size_;
  std::cout << " Brand: ";
  std::cout << Brand_;
  std::cout << ", \n";


  std::cout << "stock: ";
  std::cout << qty_;
  std::cout << ", \n";
  std::cout << "price: ";
  std::cout << price_;
}