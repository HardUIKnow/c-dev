#include"compte.h"


class client
{
private:
    /* data */
    string name;
    string lastName;
    int CiN;
    int phone;
    compte *principale;

public:
    client(string name, string lastName, int CiN, int phone);
    void depot(int somme);
    void retrait(int somme);
    void virement(client& cible, int valeur);
    void afficherCompte();
    ~client();
};


