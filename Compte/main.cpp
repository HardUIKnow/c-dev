#include"client.h"

int main(int argc, char const *argv[])
{
    int num;
    int montant;

    client A("toto", "dupont", 25625963, 336365214);
    client B("joe", "black", 74859652, 415263859);


    while(1){
    cout << "Opérations principales: " << endl;
    cout << "1: Depot" << endl;
    cout << "2: Retrait" << endl;
    cout << "3: Afficher solde" << endl;
    cout << "4: Virement" << endl;
    cout << "Quels operations sougaitez vous effectuer: " << endl;
    cin >> num;
    switch (num)
    {
    case 1:
       // int montant;
        cout << "Quels sommes souhaitez vous deposer: " << endl;
        cin >> montant;
        A.depot(montant);
        break;

    case 2:
       // int montant;
        cout << "Quels sommes souhaitez vous retirer: " << endl;
        cin >> montant;
        A.retrait(montant);
        break;

    case 3:
        A.afficherCompte();
        B.afficherCompte();
        break;
    
    case 4:
        cout << "Quels sommes souhaitez vous virer: " << endl;
        cin >> montant;
        A.virement(B, montant);
        break;
    
    default:
        break;
    }
    }
    /*
    A.depot(5000);
    A.retrait(300);
    A.afficherCompte();
    */
    return 0;
}

