#include "client.h"

client::client(string name, string lastName, int CiN, int phone)
{
    this->name = name;
    this->lastName = lastName;
    this->CiN = CiN;
    this->phone = phone;
    principale = new compte(1, 0);
}

void client::retrait(int somme){
    principale->debiter(somme);
}

void client::depot(int somme){
    principale->crediter(somme);
}

void client::virement(client& cible, int valeur){
    cible.principale->crediter(valeur);
    this->principale->debiter(valeur);
}

void client::afficherCompte(){
    cout << "le solde de " << this->name << " est de : " << principale->consulter() << endl;
}

client::~client()
{
    delete principale;
}