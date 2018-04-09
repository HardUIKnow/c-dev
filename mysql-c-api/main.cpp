#include <stdio.h>
#include <stdlib.h>
#include <winsock.h>
#include <time.h>
#include <windows.h>
#include <MySQL/include/mysql.h>

int main(void)
{
    long nombreMystere = 0, nombreEntre = 0, choix = 0;
    const long MAX = 100, MIN = 1;
    char pseudo[20] = "";
    int i = 1;

    // Génération du nombre aléatoire

    srand(time(NULL));

    //Choix de voir les scores ou de jouer
    printf("Bienvenue dans mon jeu de plus ou moins!\n\n");

    printf("1- Jouer\n");
    printf("2- Scores\n\n");

    scanf("%ld", &choix);


    switch (choix)
    {
        //Si on veut jouer
        case 1:
            //On génére le nombre aléatoire
            nombreMystere = (rand() % (MAX - MIN + 1)) + MIN;

            do
            {
                // On demande le nombre
                printf("Quel est le nombre ? ");
                scanf("%ld", &nombreEntre);

                // On compare le nombre entré avec le nombre mystère

                if (nombreMystere > nombreEntre)
                    printf("C'est plus !\n\n");
                else if (nombreMystere < nombreEntre)
                    printf("C'est moins !\n\n");
                else
                    printf ("Bravo, vous avez trouve le nombre mystere !!!\n\n");

                i++;
            } while (nombreEntre != nombreMystere);

            printf("Votre score est de: %d\n\n", i);
            printf("Veuillez entrer votre pseudo\n");
            scanf("%s", pseudo);

            //Déclaration de l'objet de type MYSQL
            MYSQL mysql;
            //Initialisation de MySQL
            mysql_init(&mysql);
            //Options de connexion
            mysql_options(&mysql,MYSQL_READ_DEFAULT_GROUP,"option");

            //Si la connexion réussie...
            if(mysql_real_connect(&mysql,"localhost","root","","test",0,NULL,0))
            {
                //On déclare un tableau de char pour y stocker la requete
                char requete[150] = "";

                //On stock la requete dans notre tableau de char
                sprintf(requete, "INSERT INTO `scores`(`nom`, `score`) VALUES ('%s','%d')", pseudo, i);

                //On execute la requete
                mysql_query(&mysql, requete);

                //Fermeture de MySQL
                mysql_close(&mysql);
            }
            else
            {
                printf("Une erreur s'est produite lors de la connexion a la BDD!\n");
            }

            break;

        //On veut voir les scores
        case 2:
            printf("Liste des scores du jeu: \n\n");

            //Déclaration de l'objet de type MYSQL
            MYSQL mysql2;
                //Initialisation de MySQL
                mysql_init(&mysql2);
                //Options de connexion
                mysql_options(&mysql2,MYSQL_READ_DEFAULT_GROUP,"option2");

                //Si la connexion réussie...
                if(mysql_real_connect(&mysql2,"localhost","root","","test",0,NULL,0))
                {
                    //Requête qui sélectionne tout dans ma table scores
                    mysql_query(&mysql2, "SELECT * FROM scores ORDER BY score");

                    //Déclaration des pointeurs de structure
                    MYSQL_RES *result = NULL;
                    MYSQL_ROW row;

                    unsigned int i = 0;
                    unsigned int num_champs = 0;
                    int j =1;

                    //On met le jeu de résultat dans le pointeur result
                    result = mysql_use_result(&mysql2);

                    //On récupère le nombre de champs
                    num_champs = mysql_num_fields(result);

                    //on stock les valeurs de la ligne choisie
                    while ((row = mysql_fetch_row(result)))
                    {

                        //On déclare un pointeur long non signé pour y stocker la taille des valeurs
                        unsigned long *lengths;

                        //On stocke ces tailles dans le pointeur
                        lengths = mysql_fetch_lengths(result);

                        //On affiche la position du joueur
                        printf("%d- ", j);

                        //On fait une boucle pour avoir la valeur de chaque champs
                       for(i = 1; i < num_champs; i++)
                       {

                           //On ecrit toutes les valeurs
                           printf("%.*s ", (int) lengths[i], row[i] ? row[i] : "NULL");
                       }
                       printf("pts\n");

                       //On incrémente la position du joueur
                       j++;

                    }

                    //Libération du jeu de résultat
                    mysql_free_result(result);

                    //Fermeture de MySQL
                    mysql_close(&mysql2);

                }
                else  //Sinon ...
                {
                    printf("Une erreur s'est produite lors de la connexion a la BDD!");
                }
            break;
        //Sinon
        default:
            printf("Le choix que vous avez entre n'est pas valide!");
            break;
    }
    return 0;
}
