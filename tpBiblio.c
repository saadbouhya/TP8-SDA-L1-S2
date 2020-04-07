// TP GESTION D'UNE BIBLIOTHEQUE 
#include "biblio.h"

int menu()
{
	int choix;
// au programme du TP6 :
printf("\n\n 1 - ajouter un nouveau livre dans la bibliotheque "); 
printf("\n 2 - afficher tous les livres de la bibliotheque "); 
printf("\n 3 - rechercher un livre (par son titre)");  // il peut y avoir plusieurs livres de même titre. Dans ce cas, indiquez le nombre d'exemplaires disponibles
printf("\n 4 - rechercher et afficher tous les livres d'un auteur");
printf("\n 5 - supprimer un livre de la bibliotheque");
// si les 5 choix ci dessus sont bien codés, modifiez votre structure T_Livre et passez à 5 champs (avec cote,editeur et annee)


// au programme du TP7 :
// ajouter le champ emprunteur à votre structure T_Livre

printf("\n 6 - emprunter un livre de la bibliotheque");
printf("\n 7 - restituer/rendre un livre de la bibliotheque");
printf("\n 8 - trier les livres (par titre)");
printf("\n 9 - trier les livres (par auteur)");
printf("\n 10 - trier les livres (par annee)");

// si les 5 choix (6-10) sont bien codés, changez le type T_Emp et remplacez-le par la structure T_Emp visible dans livre.h
// vous pourrez alors faire les menus 11,12,etc...
printf("\n 11- lister les livres disponibles "); 
printf("\n 12 - lister les emprunts en retard "); //on suppose qu'un emprunt dure 7 jours.
printf("\n 13 - ... imaginez vous même vos propres fonctionnalités ");
printf("\n 14 - sauvegarde");
printf("\n 15 - chargement");


printf("\n 0 - QUITTER");
printf("\n Votre choix : ");
scanf("%d[^\n]",&choix);getchar();
return choix;


}



int main()
{
int reponse,chx;
T_Bibliotheque B; 
init( &B );
char titre[MAX];
char auteur[MAX];
char code[MAX_CODE];
char nom_emprunteur[MAX];
int position;
int i;

do
{
chx = menu();
switch(chx)
	{
	case 1 : reponse = ajouterLivre(   &B  );
				if (reponse == 1)
					printf(" ajout reussi !!");
					else
					printf("impossible d ajouter (bibliotheque pleine)");

			break;
	case 2 : reponse = afficherBibliotheque(&B);
			if (reponse == 0)	
					printf("La bibliotheque est vide");

			break;	
	case 3 :  
			printf("saisir le titre du livre: ");
			gets(&titre);
			reponse = rechercherLivre(&B, titre);
			if(reponse >=  1)
				printf("le nombre de d'exemplaires est %d.\n", reponse);
			else 
				printf("Le livre n'existe pas.\n");

			break;

	case 4 :
			printf("Saisir le nom de l'auteur: ");
			gets(auteur);
			reponse = rechercherLivreAuteur(&B, auteur);
			if(reponse == 0)
				printf("Cet auteur n'a pas de livre.\n");

			break;
	case 5 : 
		printf("Saisir le titre du livre: ");
		gets(titre);
		reponse = supprimerLivre(&B, titre);
		if(reponse == 0)
			printf("Ce livre n'existe pas.\n");
		else 
			printf("Livre bien supprime.\n");

		break;
	case 6 :
		printf("Saisir le code du livre: ");
		gets(code);
		position = rechercherCode(&B, code);
		if(position == -1) 
			printf("Ce livre n'existe pas");
		else {
			printf("Saisir le nom de l'emprunteur: ");
			gets(nom_emprunteur);
			//1
			printf("\n quel est le jour de cet emprunt (0=lundi 1=mardi 2=mercredi 3=jeudi 4=vendredi 5 =samedi 6=dimanche)");
			scanf("%d",&i);
			B.etagere[position].emprunteur.lejour = i;
			//2
			printf("\n quel est la date de cet emprunt :");
			scanf("%d",&(B.etagere[position].emprunteur.ladate));getchar();
			//3
			printf("\n quel est le mois de cet emprunt : (0=janvier 1=fevrier 2=mars 3=avril 4=mai 5=juin .... 11=decembre)");
			scanf("%d",&i);getchar();
			B.etagere[position].emprunteur.lemois=i;
			//4
			printf("\n quel est l annee de cet emprunt :");
			scanf("%d",&(B.etagere[position].emprunteur.lannee));getchar();

			emprunterLivre(&B, nom_emprunteur, position);
			printf("Livre bien emprunte.");
		}
		break;
	case 7 : 
		printf("Saisir le code du livre a rendre : ");
		gets(code);
		position = rechercherCode(&B, code);
		if(position == -1)
			printf("Ce livre n'existe pas\n");
		else {
			rendreLivre(&B, position);
			printf("Livre bien rendu.\n");
		}
		break;
	case 8 :
		trierParTitre(&B);
		printf("Biblio bien triee.\n");
		break;
	case 9 : 
		trierParAuteur(&B);
		printf("Biblio bien triee.");
		break;
	case 10 :
		trierParAnnee(&B);
		printf("Biblio bien triee.");
		break;
	case 14 : 
		sauvegarde(&B);
		break;
	case 15 : 
		chargement(&B);
		break;
	case 11 :
		// printf("Saisir le code du livre: ");
		// gets(code);
		// position = rechercherCode(&B, code);
		// if(position == -1)
		// 	printf("Ce livre n'existe pas\n");
		// else {
		// 	reponse = livre_disponible(&B, position);
		// 	if (reponse == 1)
		// 		printf("Livre bien disponible.\n");
		// 	else
		// 		printf("Livre non disponible.\n");
		// }
		livre_disponible( &B );
		break;
	case 12 : 
		emprunts_retard( &B );
		break;
	}

}while(chx!=0);






return 0;

}