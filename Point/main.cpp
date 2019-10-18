
#include "point.h"

int main(int argc, char const *argv[])
{
    point A(2.5, 3.4); // a coordoonées 2.5 3.4
    point B(0, 0); // b coordonnées 0 0

    A.afficher();
    B.afficher();

    B.deplacer(7.5, 5.2);
    A.afficher();
    B.afficher();

    return 0;
}
