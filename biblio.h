#ifndef BIBLIO_H   //compilation conditionnelle
#define BIBLIO_H


#include "livre.h"

#define CAPACITE_BIBLIO 5 // nb maximum de livres ds la bibliotheque

typedef  T_livre 	T_tabloDeLivres[CAPACITE_BIBLIO];

typedef struct
{
	T_tabloDeLivres etagere;
	int nbLivres;  //nb de livres actuellement ds la bibliotheque

} T_Bibliotheque;




//prototypes
void init (T_Bibliotheque *ptrB);
int ajouterLivre(T_Bibliotheque  *ptrB);
int afficherBibliotheque(const T_Bibliotheque  *ptrB);
int rechercherLivre(T_Bibliotheque  *ptrB, char titre[MAX]);
int rechercherLivreAuteur(T_Bibliotheque  *ptrB, char auteur[MAX]);
int supprimerLivre(T_Bibliotheque  *ptrB, char titre[MAX]);
int rechercherCode(T_Bibliotheque  *ptrB, char code[MAX_CODE]);
int emprunterLivre(T_Bibliotheque  *ptrB, char nom_emprunteur[MAX], int position);
void rendreLivre(T_Bibliotheque  *ptrB, int position);
void trierParTitre(T_Bibliotheque  *ptrB);
void trierParAuteur(T_Bibliotheque  *ptrB);
void trierParAnnee(T_Bibliotheque  *ptrB);
void sauvegarde(T_Bibliotheque *ptrB);
void chargement(T_Bibliotheque *ptrB);
int livre_disponible(T_Bibliotheque *ptrB);
void emprunts_retard (T_Bibliotheque *ptrB);


#endif