#include <sstream>
#include <string>
#include <iomanip>
#include "util.h"
#include "movie.h"

using namespace std;

Movie::Movie(const std::string category, const std::string name, double price, int qty, const std::string Genre, const std::string Rating) :
  Product(category, name, price, qty),
  Genre_(Genre),
  Rating_(Rating)
{
}

Movie::~Movie()
{

}

std::set<std::string> Movie::keywords() const
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


  std::set<std::string> tempTwo = parseStringToWords(Genre_);
  string y = convToLower(Genre_);
  toRet.insert(trim(y));

  set<std::string>::iterator itrB;

  for (itrB = tempTwo.begin(); 
      itrB != tempTwo.end(); itrB++) 
  {
    toRet.insert(*itrB);
  }
  return toRet;
}


std::string Movie::displayString() const
{
  std::string toRet;

  toRet.append(name_); 
  toRet.append("\n");
  toRet.append("Genre: ");
  toRet.append(Genre_);
  toRet.append(" Rating: ");
  toRet.append(Rating_);
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

void Movie::dump(std::ostream& os) const
{
    os << category_ << "\n" << name_ << "\n" << price_ << "\n" << qty_ << "\n" << Genre_ << "\n" << Rating_ << endl;
}