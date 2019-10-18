#include "point.h"

point::point(float x, float y){
    this->x = x;
    this->y = y;
}

void point::deplacer(float dx, float dy){
    this->x = this->x + dx;
    this->y = this->y + dy;
}

void point::afficher(){
    cout << "la valeur de x est : " << this->x << endl;
    cout << "la valeur de y est : " << this->y << endl;
}