#include"compte.h"

compte::compte(int id, int solde){
    this->id = id;
    this->solde = solde;
}

void compte::crediter(int somme){
    this->solde += somme;
}

void compte::crediter(compte& comp, int somme){

}

void compte::debiter(int somme){
    this->solde-= somme;
}



float compte::consulter(){
    return this->solde;
}

compte::~compte()
{
}
