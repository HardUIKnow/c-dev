#include<iostream>
using namespace std;

class compte
{
private:
    /* data */
    int id;
    int solde;

public:
    compte(int id, int solde);
    void crediter(int somme);
    void crediter(compte& comp, int somme);
    void debiter(int somme);
    float consulter();

    ~compte();
};