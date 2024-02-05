#include <iostream>
#include <sstream>
#include <cctype>
#include <algorithm>
#include "util.h"

using namespace std;
std::string convToLower(std::string src)
{
    std::transform(src.begin(), src.end(), src.begin(), ::tolower);
    return src;
}

/** Complete the code to convert a string containing a rawWord
    to a set of words based on the criteria given in the assignment **/
std::set<std::string> parseStringToWords(string rawWords)
{
  std::set<string> hitWords; // create a set to return

  std::stringstream ss; // stringstream ss

  ss << rawWords;
  string tmp;

  while(ss >> tmp)
  {
    int count = 0;
    string toRet;

    for (unsigned int i = 0; i < tmp.size(); ++i)
    {
      if (ispunct(tmp[i]))
      {
        if (count >= 2)
        {
          toRet = convToLower(toRet);
          hitWords.insert(trim(toRet));
        }
        count = 0;
        toRet.clear();
      }

      else
      {
        ++count;
        toRet += tmp[i];
      }
    }

    if (count >= 2)
    {
      toRet = convToLower(toRet);
      hitWords.insert(trim(toRet));
    }
  }

  return hitWords;
}

/**************************************************
 * COMPLETED - You may use the following functions
 **************************************************/

// Used from http://stackoverflow.com/questions/216823/whats-the-best-way-to-trim-stdstring
// trim from start
std::string &ltrim(std::string &s) {
    s.erase(s.begin(), 
	    std::find_if(s.begin(), 
			 s.end(), 
			 std::not1(std::ptr_fun<int, int>(std::isspace))));
    return s;
}

// trim from end
std::string &rtrim(std::string &s) {
    s.erase(
	    std::find_if(s.rbegin(), 
			 s.rend(), 
			 std::not1(std::ptr_fun<int, int>(std::isspace))).base(), 
	    s.end());
    return s;
}

// trim from both ends
std::string &trim(std::string &s) {
    return ltrim(rtrim(s));
}
