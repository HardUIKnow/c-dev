#ifndef __NERD_HPP
#define __NERD_HPP

#include "geek.hpp"

namespace myspace {
  class nerd : public geek {
  protected:
    int m_number_computer;

  public:
    nerd (string name, int quantity, int number_computer);
    int getNumber_computer();
    nerd& operator+=(nerd &snerd);
  };
} /* myspace */
ostream& operator<< (ostream& os, myspace::nerd& g);

#endif
