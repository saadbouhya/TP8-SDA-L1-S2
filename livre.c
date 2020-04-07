#include "livre.h"


void saisirLivre(T_livre * ptrL)
{
lireChaine("TITRE :", (ptrL->titre), MAX_TITRE );
lireChaine("AUTEUR :", (ptrL->auteur ), MAX);
lireChaine("EDITEUR :", (ptrL->editeur), MAX);
lireInt("ANNEE :", &(ptrL->annee));
lireChaine("CODE :", (ptrL->code), MAX_CODE);
strcpy((ptrL->emprunteur.nomemprunteur), "");
ptrL->emprunteur.ladate = 0;
ptrL->emprunteur.lannee = 0;
ptrL->emprunteur.lejour = -1;
ptrL->emprunteur.lemois = -1;
}

void afficherLivre1(const T_livre *ptrL)
{
afficherChaine("TITRE :", (ptrL->titre));
printf("\n");
// afficherChaine("AUTEUR :", (ptrL->auteur ));
// printf(" - ");
// afficherChaine("EDITEUR :", (ptrL->editeur ));
// printf(" - ");
// afficherInt("ANNEE :", (ptrL->annee ));
// printf(" - ");
afficherChaine("CODE :", (ptrL->code ));
printf("\n");
// afficherChaine("EMPRUNTEUR :", (ptrL->emprunteur.nomemprunteur ));
printf("Ce livre n'est pas emprunte.");
printf("\n");
}

void afficherLivre(const T_livre *L)
{

char jour[13],mois[13];

afficherChaine("TITRE :", (L->titre));

printf("\n");

afficherChaine("CODE :", (L->code ));

printf("\n");

afficherChaine("EMPRUNTEUR :", (L->emprunteur.nomemprunteur ));

printf("\n  emprunt realise le : ");
switch(L->emprunteur.lejour)
{
case 0 :  strcpy(jour,"lundi");break;
case 1 :  strcpy(jour,"mardi");break;
case 2 :  strcpy(jour,"mercredi");break;
case 3 :  strcpy(jour,"jeudi");break;
case 4 :  strcpy(jour,"vendredi");break;
case 5 :  strcpy(jour,"samedi");break;
case 6 :  strcpy(jour,"dimanche");break;

default : strcpy(jour,"jour inconnu");break;
}
printf("%s ",jour);

printf("%d ",L->emprunteur.ladate);


switch(L->emprunteur.lemois)
{
case 0 :  strcpy(mois,"janvier");break;
case 1 :  strcpy(mois,"fevrier");break;
case 2 :  strcpy(mois,"mars");break;
case 3 :  strcpy(mois,"avril");break;
case 4 :  strcpy(mois,"mai");break;
case 5 :  strcpy(mois,"juin");break;
case 6 :  strcpy(mois,"juillet");break;
case 7 :  strcpy(mois,"aout");break;
case 8 :  strcpy(mois,"septembre");break;
case 	9 :  strcpy(mois,"octobre");break;
case 10 :  strcpy(mois,"novembre");break;
case 11 :  strcpy(mois,"decembre");break;

default : strcpy(jour,"mois inconnu");break;
}
printf("%s ",mois);

printf("%d ",L->emprunteur.lannee);

printf("\n");

}

int lireDateSysteme(T_Emp *E)
{
char j[9],m[10],h[9],mer[11],vir[2];
int d,a;


system("date > ladate"	);
FILE * fic=NULL;  // pointeur de fichier
fic=fopen("ladate","r"); //fileOpen en mode 'r'EAD

//ici , si fic vaut NULL, alors le fopen a indiqué
//que le fichier ladate n'est pas accessible
int tab[12] = {0, 31, 59, 90, 120, 151, 181, 212, 243, 273, 304, 334};
int result;
int mois;
if (fic!=NULL)
	{
	while(!feof(fic))	
		{
		fscanf(fic,"%s %d %s %d %s %s %s",j,&d,m,&a,vir,h,mer);		
		if (!feof(fic)){ 
			//printf("\n-->LU : %s- %d- %s- %d- %s- %s",j,d,m,a,h,mer);
			printf("\n");		
				if (strcmp(m,"janvier")==0) mois = 0;
				if (strcmp(m,"fevrier")==0) mois = 1;
				if (strcmp(m,"mars")==0) mois = 2;
				if (strcmp(m,"avril")==0) mois = 3;
				if (strcmp(m,"mai")==0) mois = 4;
				if (strcmp(m,"juin")==0) mois = 5;
				if (strcmp(m,"juillet")==0) mois = 6;
				if (strcmp(m,"aout")==0) mois = 7;
				if (strcmp(m,"septembre")==0) mois = 8;
				if (strcmp(m,"octobre")==0) mois = 9;
				if (strcmp(m,"novembre")==0) mois = 10;
				if (strcmp(m,"decembre")==0) mois = 11;
			result = 365 * a + tab[mois] + d;
			return result;
		}
	}
	fclose(fic);
	
if (strcmp(j,"lundi")==0) E->lejour=lundi;
if (strcmp(j,"mardi")==0) E->lejour=mardi;
if (strcmp(j,"mercredi")==0) E->lejour=mercredi;
if (strcmp(j,"jeudi")==0) E->lejour=jeudi;
if (strcmp(j,"vendredi")==0) E->lejour=vendredi;
if (strcmp(j,"samedi")==0) E->lejour=samedi;
if (strcmp(j,"dimanche")==0) E->lejour=dimanche;

E->ladate=d;

if (strcmp(m,"janvier")==0) E->lemois=janvier;
if (strcmp(m,"fevrier")==0) E->lemois=fevrier;
if (strcmp(m,"mars")==0) E->lemois=mars;
if (strcmp(m,"avril")==0) E->lemois=avril;
if (strcmp(m,"mai")==0) E->lemois=mai;
if (strcmp(m,"juin")==0) E->lemois=juin;
if (strcmp(m,"juillet")==0) E->lemois=juillet;
if (strcmp(m,"aout")==0) E->lemois=aout;
if (strcmp(m,"septembre")==0) E->lemois=septembre;
if (strcmp(m,"octobre")==0) E->lemois=octobre;
if (strcmp(m,"novembre")==0) E->lemois=novembre;
if (strcmp(m,"decembre")==0) E->lemois=decembre;


E->lannee=a;
	}
	else
	{
		printf("n souci avec la date systeme !!");
		
		//on range une date irréelle 
		E->lejour=dimanche;
		E->ladate=99;
		E->lemois=decembre;
		E->lannee=-999;


	}

}

