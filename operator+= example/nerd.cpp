#include "nerd.hpp"

myspace::nerd::nerd(string name, int quantity, int number_computer) : myspace::geek::geek(name, quantity), m_number_computer(number_computer){

}


int myspace::nerd::getNumber_computer(){
  return m_number_computer;
}

myspace::nerd& myspace::nerd::operator+=(nerd &snerd){
  this->m_name += snerd.getName();
  this->m_quantity += snerd.getQuantity();
  this->m_number_computer += snerd.getNumber_computer();
  return *this;
}


ostream& operator<< (ostream& os,  myspace::nerd& g){
    os << g.getName() << " possede " << g.getQuantity() << " ordinateurs dont " << g.getNumber_computer() << " personnels !!!" << endl;
  return os;
}
