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


T_Aut atr;
T_Titre tr;
T_Code code;
char name_emp[K_MaxEmp];


int position;


chargement(&B);
do
{
chx= menu();
switch(chx)
	{
	case  1 : reponse = ajouterLivre(   &B  );
				if (reponse==1)
					printf(" ajout reussi !!");
					else
					printf("impossible d ajouter (bibliotheque pleine)");
			break;
	case 2 : reponse=afficherBibliotheque(&B);
			if (reponse==0)	
					printf("La bibliotheque est vide");

			break;	
	case 3 : lireChaine("Saisir le livre que vous cherchez \n", tr, K_MaxTit);
			reponse=recherchelivre( &B, tr);
			if (reponse==0)
					printf("La bibliotheque n'a aucun livre de ce nom \n");
			else printf("Le nombre d'exemplaires du livre %s est %d \n",tr,reponse );				
			
			break;
	case 4 : lireChaine("saisir le nom de l'auteur \n", atr , K_MaxAut );
			affichagelivre2(&B, atr);

			break;	
	case 5:	lireChaine("Saisir le livre que vous voulez supprimer \n", tr, K_MaxTit); 
			supprimerlivre(&B , tr)	;

			break;	
	case 6 :
			lireChaine("sasir le code du livre à emprunter", code, K_MaxCode);
			position = recherchecode(&B, code);
			if (position>=0)
				{
					lireChaine("saisir le nom de l'emprunteur", name_emp, K_MaxEmp);
					emprunt_livre(&B.etagere[position], name_emp);
				}
			else
				printf("code de livre non existant\n");

			break;
	case 7 :lireChaine("sasir le code du livre à rendre", code, K_MaxCode);
			position = recherchecode(&B, code);
			if (position>=0)
					rendre_livre(&B.etagere[position]);
			else
				printf("code de livre non existant\n");
			


			break;
	case 8 :
			trie_titre(&B);
	

			break;
	case 9 :
			trie_auteur(&B);


			break;		
	case 10 :
	
			trie_annee(&B);

			break;
	case 11 :
	
			Livres_dispo(&B);

			break;											
	case 12 :
	
			

			break;
	case 13 :
	
			

			break;				

	
	
	
	
	}

}while(chx!=0);




sauvegarde(&B);

return 0;

}