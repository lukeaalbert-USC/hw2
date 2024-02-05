#ifndef UTIL_H
#define UTIL_H

#include <string>
#include <iostream>
#include <set>


/** Complete the setIntersection and setUnion functions below
 *  in this header file (since they are templates).
 *  Both functions should run in time O(n*log(n)) and not O(n^2)
 */
template <typename T>
std::set<T> setIntersection(std::set<T>& s1, std::set<T>& s2)
{
  typename std::set<T>::iterator itFirst = s1.begin(); //create first iterator
  std::set<T> toRet; //create empty set to return


  while (itFirst != s1.end()) //while BOTH ITERATORS DON'T reach the end
  {
    if (s2.find(*itFirst) != s2.end())
    {
      toRet.insert(*itFirst); //add to list, increase both iterator
    }
    itFirst++;
  }
  return toRet; //return set with intersection
}


template <typename T>
std::set<T> setUnion(std::set<T>& s1, std::set<T>& s2)
{
  std::set<T> toRet; //create empty set to return

  typename std::set<T>::iterator itFirst = s1.begin(); //create first iterator

  while (itFirst != s1.end()) //for all vals of s1, insert in list
  {
    toRet.insert(*itFirst);
    ++itFirst;
  }

  typename std::set<T>::iterator itSec = s2.begin(); //create second iterator

  while (itSec != s2.end()) //for all vals of s1, insert in list. RECALL: c++ sets take care of duplicates automatically.
  {
    toRet.insert(*itSec); 
    ++itSec;
  }

  return toRet; //return set with intersection
}

/***********************************************/
/* Prototypes of functions defined in util.cpp */
/***********************************************/

std::string convToLower(std::string src);

std::set<std::string> parseStringToWords(std::string line);

// Used from http://stackoverflow.com/questions/216823/whats-the-best-way-to-trim-stdstring
// Removes any leading whitespace
std::string &ltrim(std::string &s) ;

// Removes any trailing whitespace
std::string &rtrim(std::string &s) ;

// Removes leading and trailing whitespace
std::string &trim(std::string &s) ;
#endif
