#include "geek.hpp"

myspace::geek::geek(string name = "toto", int quantity = 0) : m_name(name), m_quantity(quantity){

}

string myspace::geek::getName(){
  return m_name;
}

int myspace::geek::getQuantity(){
  return m_quantity;
}

ostream& operator<< (ostream& os,  myspace::geek& g){
    os << g.getName() << " possede " << g.getQuantity() << " ordinateurs !" << endl;
  return os;
}
