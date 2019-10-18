/* declaration de la classe point 
*/
#include<iostream>
using namespace std;

class point
{
private:
    float x = 0; // coordonnées en x du point
    float y = 0; // coordonnées en y du point

public:
    point(float x, float y);
    void deplacer(float dx, float dy);
    void afficher();

};


