#ifndef __GEEK_HPP
#define __GEEK_HPP

#include <iostream>
#include <string>
using namespace std;

namespace myspace {

  class geek {
    protected:
      string m_name;
      int m_quantity;

    public:
      geek (string name, int quantity);
      string getName();
      int getQuantity();


    };

} /*myspace */
ostream& operator<< (ostream& os, myspace::geek& g);

#endif
