#include <iostream>
#include <sstream>
#include "mydatastore.h"
#include "product_parser.h"
#include "book.h"
#include "clothing.h"
#include "movie.h"
#include "util.h"

using namespace std;

MyDataStore::MyDataStore(){} 

MyDataStore::~MyDataStore() {
  for (size_t i = 0; i < Products.size(); i++)
  {
    delete Products[i];
  }

    for (size_t i = 0; i < Users.size(); i++)
  {
    delete Users[i];
  }
}


void MyDataStore::addProduct(Product* p)
{
  Products.push_back(p);

  std::set<std::string> keywrds = p -> keywords();
  std::set<std::string>::iterator itrKey;

  for (itrKey = keywrds.begin(); 
       itrKey != keywrds.end(); itrKey++) 
  {
    ProductMap[*itrKey].insert(p);
  }
}

/**
* Adds a user to the data store
*/
void MyDataStore::addUser(User* u) 
{
  if (u == nullptr)
  {
    return;
  }
  Users.push_back(u);
}

/**
* Performs a search of products whose keywords match the given "terms"
*  type 0 = AND search (intersection of results for each term) while
*  type 1 = OR search (union of results for each term)
*/
std::vector<Product*> MyDataStore::search(std::vector<std::string>& terms, int type)
{
  std::vector<Product*> toRet;
  
  if (terms.size() > 0)
  {
    terms[0] = convToLower(terms[0]);
    std::set<Product*> retSet = ProductMap[trim(terms[0])];

    for (std::size_t i = 1; i < terms.size(); ++i)
    {
      terms[i] = convToLower(terms[i]);
      std::set<Product*> temp = ProductMap[trim(terms[i])];

      if (type == 0)
      {
        retSet = setIntersection(retSet, temp);
      }
      else if (type == 1)
      {
        retSet = setUnion(retSet, temp);
      }
    }
    set<Product*>::iterator itr;

    for (itr = retSet.begin(); 
      itr != retSet.end(); itr++) 
    {
      toRet.push_back(*itr);
    }
  }

  PrevSearchResults = toRet;
  return toRet;
}

/**
* Reproduce the database file from the current Products and User values
*/
void MyDataStore::dump(std::ostream& ofile) 
{
  ofile << "<products>" << endl;
  for (std::size_t i = 0; i < Products.size(); ++i)
  {
    Products[i] -> dump(ofile);
  }
  ofile << "</products>" << endl;
  ofile << "<users>" << endl;
  for (std::size_t i = 0; i < Users.size(); ++i)
  {
    Users[i] -> dump(ofile);
  }
  ofile << "</users>" << endl;
}

User* MyDataStore::checkUsernameValidity(std::string& username)
{
  for (std::size_t i= 0; i < Users.size(); ++i)
  {
    if (Users[i] -> getName() == username)
    {
      User* currUser = Users[i];
      return currUser;
    }
  }

  return nullptr;
}

void MyDataStore::AddToCart(std::string& username, int hitIndex)
{
  hitIndex--;
  if (PrevSearchResults.size() == 0 || (unsigned int)hitIndex + 1 > PrevSearchResults.size() || hitIndex < 0)
  {
    std::cout << "Invalid request" << endl;
    return;
  }
  User* currUser = checkUsernameValidity(username);
  if (currUser == nullptr)
  {
    std::cout << "Invalid request" << endl;
    return;
  }

  carts[currUser].push_back(PrevSearchResults[hitIndex]);
} 


void MyDataStore::ViewCart(std::string& username)
{
  User* currUser = checkUsernameValidity(username);

  if (currUser == nullptr)
  {
    std::cout << "Invalid username" << endl;
    return;
  }
  // std::cout << "Curr User " << currUser -> getName() << std::endl;
  std::vector<Product*> userCart = carts[currUser];

  // std::cout << "Curr User" << currUser << std::endl;
  for (std::size_t i = 0; i < userCart.size(); ++i)
  {
    std::cout << "\n";
    std::cout << "Item " << i + 1 << "\n";
    std::cout << userCart[i] -> displayString();
  }
}

void MyDataStore::BuyCart(std::string& username)
{
  User* currUser = checkUsernameValidity(username);
  if (currUser == nullptr)
  {
    std::cout << "Invalid username" << endl;
    return;
  }

  std::vector<Product*> modCart;

  for (size_t i = 0; i < carts[currUser].size(); i++)
  {
    if (currUser -> getBalance() > (carts[currUser][i]) -> getPrice() && (carts[currUser][i]) -> getQty() > 0)
    {
      currUser -> deductAmount((carts[currUser][i]) -> getPrice());
      (carts[currUser][i]) -> subtractQty(1);
    }
    else
    {
      modCart.push_back(carts[currUser][i]);
    }
  }

  carts[currUser] = modCart;
}