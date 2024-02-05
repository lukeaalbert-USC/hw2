#ifndef MYDATASTORE_H
#define MYDATASTORE_H
#include <string>
#include <set>
#include <vector>
#include <map>
#include "datastore.h"

/**
 * DataStore Interface needed for parsing and instantiating products and users
 * My derived version of DataStore.
 */


class MyDataStore: public DataStore {
public:
  MyDataStore();
  ~MyDataStore();

  /**
  * Adds a product to the dataStore
  */
  void addProduct(Product* p);

  /**
  * Adds a user to the data store
  */
  void addUser(User* u);

  /**
  * Performs a search of products whose keywords match the given "terms"
  *  type 0 = AND search (intersection of results for each term) while
  *  type 1 = OR search (union of results for each term)
  */
  std::vector<Product*> search(std::vector<std::string>& terms, int type);

  /**
  * Reproduce the database file from the current Products and User values
  */
  void dump(std::ostream& ofile);

  //Add item to username's cart
  void AddToCart(std::string& username, int hitIndex);

  void ViewCart(std::string& username);

  void BuyCart(std::string& username);

  User* checkUsernameValidity(std::string& username);

  private:
    std::vector<Product*> Products; //vec to hold Products
    std::vector<User*> Users; //vec to hold Users
    std::map<std::string, std::set<Product*>> ProductMap;
    std::vector<Product*> PrevSearchResults;
    std::map<User*, std::vector<Product*>> carts;
};

#endif