#include <iostream>
#include <string>
#include <cctype> // Pour isupper, tolower, toupper
#include "crack.h"


// Fonction de crackage par force brute
void forceBrute(string chiffre)
{
    cout << "\n\t==========  Tentatives de déchiffrement  ==========" << endl;
    for (int key = 1; key < alphabetLength; key++)
        cout << "Clé " << key << ": " << cesar(chiffre, key, true) << endl;
}


// Fonction de crackage par analyse de fréquences
void analyseDeFrequences(string chiffre) {
    int frequencies[alphabetLength] = {0};
    int max, key;
    string mostCommonLetter;

    // On compte le nombres d'occurences des lettres du chiffre
    for (char c : chiffre )
        frequencies[(int)c]++;
    
    // On determine (par ordre) les lettres qui apparaissent le plus dans le message chiffré
    for (int i=0; i < alphabetLength; i++) {
        max = maximum(frequencies);
        if (frequencies[max] > 0) mostCommonLetter += (char)max;
        frequencies[max] = 0;
    }

    // cout << mostCommonLetter << " : " << mostCommonLetter.length() << endl;
    cout << "\n\t==========  Tentatives de déchiffrement  ==========" << endl;

    char mclif = MOST_COMMON_LETTER_IN_FRENCH[0]; // E
    int n = mostCommonLetter.length() >= 4 ? 4 : mostCommonLetter.length();

    for (int i=0; i<n; i++) {
        char mcl = mostCommonLetter[i];
        int key = (alphabetLength + (int)mcl - (int)mclif) % alphabetLength;
        cout << "Clé " << key << ": " << cesar(chiffre, key, true) << endl;
    }
}


// Fonction pour le menu de crackage
void crackage() {
    cout << "\n\t##############   CRACKAGE   ################\n" << endl;
    cout << "\t [1]. Force Brute" << endl;
    cout << "\t [2]. Analyses de fréquences" << endl;
    cout << "\t [0]. Quitter\n" << endl;

    int option;
    do {
        option = lireNombre(">> Option : ", "Option inconnue, veuillez réessayer.");
        switch (option) {
            case 0:
                return;
            case 1:
                cout << "\n\t=============  FORCE BRUTE  =============\n" << endl;
                break;
            case 2:
                cout << "\n\t=============  ANALYSE DE FRÉQUENCES  =============\n" << endl;
                break;
            default:
                cout << "Option inconnue, veuillez réessayer." << endl;
                continue;
        }
        break;
    }
    while(true);

    string chiffre;
    cout << ">> Chiffre : ";
    getline(cin, chiffre);

    if (option == 1) forceBrute(chiffre);
    else analyseDeFrequences(chiffre);

}

