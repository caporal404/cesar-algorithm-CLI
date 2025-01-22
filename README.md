# ALGORITHME DE CESAR
**Auteur : caporal404**  
**Langage : C++**

---

## 1. Introduction  
L’algorithme de César est une méthode de chiffrement par substitution dans laquelle chaque lettre du message clair est remplacée par une autre lettre située à un certain nombre fixe de positions plus loin dans l’alphabet. 
Ce projet implémente une version en ligne de commande (CLI) de l'algorithme César, en C++.
Ses parties sont :  
- Le **chiffrement** et le **déchiffrement** des messages.  
- Le **crackage** par force brute et par **analyse de fréquences**.

---

## 2. Fonctionnalités principales  

### 2.1. Chiffrement  
Le message est chiffré en décalant chaque lettre de l'alphabet d'une clé donnée.  
- **Entrées** :  
  - Un message clair.  
  - Une clé (entier entre 0 et 25).  
- **Sortie** : Le message chiffré.  
- **Caractéristiques** :  
  - Les espaces, les caractères spéciaux et les chiffres ne sont pas modifiés.  
  - Les majuscules/minuscules sont conservées.

### 2.2. Déchiffrement  
Le déchiffrement utilise la clé pour inverser le processus de chiffrement.  
- **Entrées** :  
  - Un message chiffré.  
  - Une clé.  
- **Sortie** : Le message clair.

---

## 3. Crackage du message chiffré  
Deux méthodes sont utilisées pour casser un message chiffré sans connaître la clé :  

### 3.1. Force brute  
- Teste toutes les clés possibles (de 1 à 25).  
- Affiche toutes les tentatives pour permettre à l’utilisateur d’identifier le message clair.  

### 3.2. Analyse de fréquences  
- Compte le nombre d’occurrences de chaque lettre dans le message chiffré.  
- Compare les lettres les plus fréquentes dans le message avec celles de la langue française (`E`, `S`, `A`, etc.).  
- Déduit une ou plusieurs clés probables et propose des tentatives de déchiffrement.

---

## 4. Organisation du code

### 4.1. Fichiers importants
- **`cesar()`** : Chiffre ou déchiffre un message selon une clé donnée.  
- **`forceBrute()`** : Affiche toutes les tentatives possibles par force brute.  
- **`analyseDeFrequences()`** : Analyse les fréquences des lettres pour deviner la clé.  

### 4.2. Fonctions auxiliaires
- **Gestion des entrées utilisateur** :  
  - `lireNombre` : Récupère un entier valide au clavier.  
  - `lireChar` : Récupère un caractère valide.  
  - `demanderCle` : Valide une clé entrée.  
- **Outils pour les tableaux** :  
  - `maximum` : Trouve l’indice de la valeur maximale dans un tableau.  

---

## 5. Interface utilisateur  
Le programme affiche un menu principal :  
1. **Chiffrement** : Saisir un message et une clé pour obtenir le message chiffré.  
2. **Déchiffrement** : Saisir un message chiffré et une clé pour retrouver le message clair.  
3. **Crackage** : Choisir entre force brute ou analyse de fréquences pour tenter de casser un message chiffré.  
0. **Quitter** : Terminer le programme.

Le menu est simple et interactif pour une meilleure expérience utilisateur.

---

## 6. Limites et améliorations possibles
- **Limites :**  
  - Efficacité réduite pour des messages courts en analyse de fréquences.  
  - Pas de prise en charge d’autres alphabets (ex. : caractères accentués).  
- **Améliorations envisagées :**  
  - Support de différents alphabets et langues.  
  - Implémentation de tests automatisés pour valider chaque fonctionnalité.

---

## 7. Exemple d’exécution
1. **Chiffrement** :  
   **Entrée** : `Message = "Salut !", Clé = 3`  
   **Sortie** : `Vdoxw !`  

2. **Déchiffrement** :  
   **Entrée** : `Message = "Vdoxw !", Clé = 3`  
   **Sortie** : `Salut !`  

3. **Force brute** :  
   Affiche toutes les combinaisons possibles pour identifier le message clair.  

4. **Analyse de fréquences** :  
   Pour un message comme `Jxuhhxgx`, propose plusieurs clés probables selon les lettres les plus fréquentes.

---

## 8. Conclusion
Ce projet montre comment appliquer et casser l’algorithme de César à travers des outils interactifs et éducatifs. Il met en évidence les forces et les faiblesses de ce chiffrement classique tout en offrant des méthodes efficaces pour le déchiffrer.  
