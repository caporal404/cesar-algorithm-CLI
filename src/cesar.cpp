#include <iostream>
#include <string>
#include <cctype> // Pour isupper, tolower, toupper
#include "cesar.h"


// Fonction pour le chiffrer et le déchiffrer un message
string cesar(string message, int key, bool isDecryption = false) {
    string result;
    if (isDecryption) key = alphabetLength - key; // On inverse la clé pour le dechiffrement
    
    for (char c : message) {
        // On calcul de l'indice du caractère chiffré 
        if (c == ' ') result += c;
        else {
            int index = ((int)c + key) % alphabetLength;
            result += (char)index;
        }
    }
    return result;
}


// Fonctions pour le menu de chiffrement
void chiffrement() {
    cout << "\n\t############  CHIFFREMENT  #############" << endl;

    string message;
    int key;

    cout << "\n>> Message : ";
    getline(cin, message);

    key = demanderCle();

    cout << ">> Chiffre : " << cesar(message, key) << endl;
}


// Fonctions pour le menu de déchiffrement
void dechiffrement()
{
    cout << "\n\t############  DÉCHIFFREMENT  #############" << endl;

    string chiffre;
    int key;

    cout << "\n>> Chiffre : ";
    getline(cin, chiffre);

    key = demanderCle();

    cout << ">> Message : " << cesar(chiffre, key, true) << endl;
}

