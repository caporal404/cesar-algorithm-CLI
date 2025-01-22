#include <iostream>
#include <string>
#include <cassert>
#include "params.h"
#include "cesar.h"
#include "crack.h"
#include "utils.h"
using namespace std;

void testCesar() {
    cout << "Test du chiffrement et déchiffrement...\n";

    string message = "HELLO WORLD";
    int key = 3;
    string chiffre = cesar(message, key, false);

    // Test de chiffrement
    assert(chiffre == "KHOOR ZRUOG");

    // Test de déchiffrement
    string dechiffre = cesar(chiffre, key, true);
    assert(dechiffre == message);

    cout << "  Chiffrement et déchiffrement réussis !\n";
}

void testForceBrute() {
    cout << "Test de la force brute...\n";

    string chiffre = "KHOOR ZRUOG";
    // Test manuel des premières clés générées par la force brute
    cout << "  Force brute exécutée (vérifiez la sortie manuelle).\n";
    forceBrute(chiffre);
}

void testAnalyseDeFrequences() {
    cout << "Test de l'analyse de fréquences...\n";

    string chiffre = "KHOOR KHOOR KHOOR"; // Message avec répétitions pour l'analyse
    cout << "  Analyse de fréquences exécutée (vérifiez la sortie manuelle).\n";
    analyseDeFrequences(chiffre);
}

void testUtils() {
    cout << "Test des fonctions utilitaires...\n";

    // Test de lireNombre
    int nombre = lireNombre("Entrez 42 (test automatique) : ", "Erreur");
    assert(nombre == 42);

    // Test de lireChar
    char c = lireChar("Entrez 'A' (test automatique) : ", "Erreur");
    assert(c == 'A');

    // Test de lireNombreOuChar avec un nombre
    int indice = lireNombreOuChar("Entrez 3 (test automatique) : ", "Erreur");
    assert(indice == 3);

    // Test de lireNombreOuChar avec une lettre
    indice = lireNombreOuChar("Entrez 'C' (test automatique) : ", "Erreur");
    assert(indice == (int)'C');

    cout << "  Fonctions utilitaires validées !\n";
}

int main() {
    cout << "\n================= TESTS =================\n";

    testCesar();
    testForceBrute();
    testAnalyseDeFrequences();
    testUtils();

    cout << "\nTous les tests sont passés avec succès !\n";
    return 0;
}
