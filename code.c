#include "biblio.h"

void lectureFichierTXT();


int menu()
{
int chx;
printf("\n\t 1 - ajouter un livre ");
printf("\n\t 2 - lister les livres ");
printf("\n\t 0 - QUITTER");
scanf("%d",&chx);
fflush(stdin);
return chx;
}


void sauvegarde(T_Bibliotheque *ptrB)
{
FILE *fic=NULL; //le type FILE
int i;
fic=fopen("baseLivres","w"); // w = le mode = write avec ECRASEMENT
//fopen renvoie NULL si probleme (disque plein, disque non accessible ...
if (fic!=NULL)
	{
	for(i=0;i<ptrB->nbLivres;i++)
		{
//fwrite(const void *ptr, size_t size, size_t nmemb, FILE *stream)
    fwrite(  &(ptrB->etagere[i])        ,sizeof(T_livre),1,fic);

		}
	fclose(fic);
	puts("SAUVEGARDE REUSSIE ..............");



	}
	else puts("ECHEC DE SAUVEGARDE  !!!!!  ");




}



void chargement(T_Bibliotheque *ptrB)
{
FILE *fic=NULL; //le type FILE
int i=0;
fic=fopen("baseLivres","r"); // r = le mode read
//fopen renvoie NULL si probleme (disque plein, disque non accessible ...
if (fic!=NULL)
	{
	do
		{

		fread(  &(ptrB->etagere[i]) ,sizeof(T_livre),1,fic);
		i++;
		}
		while(!feof(fic));
	fclose(fic);
	ptrB->nbLivres=i-1;
	puts("CHARGEMENT  REUSSI ..............");
	}
	else puts("ECHEC DE CHARGEMENT  !!!!!  ");

}




////////************PP
int main( )
{
//lectureFichierTXT();


int choix,reponse;
T_Bibliotheque B;
init(&B);

chargement(&B); //chargement d'un fichier de structure(s) T_livre

do{
	choix=menu();
	switch(choix)
		{
		case 1  : reponse = ajouter(&B);
            if (reponse==1)
                puts("Ajout reussi !!!");
            else
                puts("Bibliotheque pleine !! impossible d ajouter");
		break;

		case 2  : reponse = lister_bibliotheque(&B);
            if (reponse==0)
                puts("Bibliotheque VIDE  !!");
		break;



		}
}while(choix!=0);
	sauvegarde(&B);

}



void lectureFichierTXT()
{
int M=100;
FILE *fic=NULL; //le type FILE
char chaine[M];
char chaine2[M];
char c;
fic=fopen("fic.txt","rt"); // r = le mode read   w = mode write (avec ecrasement)
//fopen renvoie NULL si probleme (fichier effac� , disque non accessible ...
if (fic!=NULL)
	{
	do
		{
		//fgets(chaine,M,fic);   //fputs pour �crire dans un fichier txt
		//fscanf(fic,"%s",chaine); //fprintf pour �crire dans un fichier txt
	//	fscanf(fic,"%s %s",chaine,chaine2);
		fscanf(fic,"%c",&c);
		//fscanf(fic,"%c",&chaine[0]);
	//	if (!feof(fic))
           //printf("\n\t >%s--%s<",chaine,chaine2);
        printf(">%c<",c);
		}
    while(!feof(fic));
	fclose(fic);
	puts("\nLECTURE REUSSIE ..............");
	}
	else puts("ECHEC DE LECTURE DU FICHIER TXT !!!!!  ");
}





