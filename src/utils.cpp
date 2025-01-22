#include <iostream>
#include <string>
#include <cctype> // Pour isupper, tolower, toupper
#include <algorithm> // Pour all_of
#include "utils.h" 


// Fonction de recherche du maximum d'un tableau
int maximum(int t[]) {
    int max=0;
    for(int i=0; i < alphabetLength; i++) 
        if (t[i] > t[max]) max=i;
    return max;
}

// Fonction pour recupérer un entier au clavier sans erreur
int lireNombre(string message, string erreur) {
    string tmp;
    cout << message;
    getline(cin, tmp);

    if (tmp.length() != 0 && all_of(tmp.begin(), tmp.end(), ::isdigit)) return stoi(tmp);
    cout << erreur << endl;

    return lireNombre(message, erreur);
}

// Fonction pour recupérer un caractère au clavier sans erreur
char lireChar(string message, string erreur) {
    string tmp;
    cout << message;
    getline(cin, tmp);

    if (tmp.length() == 1) return tmp[0];
    cout << erreur << endl;

    return lireChar(message, erreur);
}

// Fonction pour recupérer l'indice d'un caractère entré au clavier sans erreur
int lireNombreOuChar(string message, string erreur) {
    string tmp;
    cout << message;
    getline(cin, tmp);

    if (tmp.length() != 0 && all_of(tmp.begin(), tmp.end(), ::isdigit)) 
        return stoi(tmp);
    if (tmp.length() == 1) 
        return (int)tmp[0];
    
    cout << erreur << endl;
    return lireNombreOuChar(message, erreur);
}

// Fonction pour demander une clé valide à l'utilisateur
int demanderCle() {
    while (true) {
        int key = lireNombreOuChar(">> Clé [0-" + to_string((alphabetLength - 1)) + "] : ", "Clé invalide, veuillez réessayer.");
        if (key >= 0 && key <= (alphabetLength - 1)) 
            return key;
        cout << "Clé invalide, veuillez réessayer !" << endl;
    }
}

