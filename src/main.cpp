#include <iostream>
#include "crack.h"

using namespace std;

// Fonction pour l'execution des algorithmes
void menu()
{
    cout << "\t 1. Chiffrement" << endl;
    cout << "\t 2. Déchiffrement" << endl;
    cout << "\t 3. Crackage" << endl;
    cout << "\t 0. Quitter\n" << endl;

    int option;
    option = lireNombre("> Option : ", "Option inconnue, veuillez réessayer.");

    switch (option) {
        case 0:
            break;
        case 1:
            chiffrement();
            break;
        case 2:
            dechiffrement();
            break;
        case 3:
            crackage();
            break;
        default:
            cout << "Option inconnue, veuillez réessayer." << endl;
            menu();
    }
}

int main()
{
    cout << endl;
    cout << "\t _______________________________________________________ " << endl;
    cout << "\t|                                                       |" << endl;
    cout << "\t|                  ALGORITHME DE CÉSAR                  |" << endl;
    cout << "\t|                                                       |" << endl;
    cout << "\t ******************************************************* " << endl;
    cout << endl;

    // On lance l'execution des algorithmes
    menu();

    do {
        char choice = lireChar("\n> Voulez-vous reéssayer ? (O/N) : ", "Choix inconnue, veuillez réessayer.");

        if (toupper(choice) == 'O' || toupper(choice) == 'Y') {
            cout << endl;
            menu();
        }
        else if (toupper(choice) != 'N') cout << "Choix inconnue, veuillez réessayer." << endl;
        else break;
    }
    while(true);

    cout << "\nFermeture du programme....................................[OK]" << endl;
    return 0;
}
