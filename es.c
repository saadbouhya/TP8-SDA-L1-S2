#include "es.h"


char *lire(char* lachaine,int nbMAXcaracAsaisir)
{
char car;
int i=0,nbesp=0;
do
{
 	car=getchar();
	//printf("\n>>%c",car);
	if (car!='\n')
		{	
	 	if (car!=' ' ) //ou if (car!=32)
	 		{lachaine[i++]=car;nbesp=0;}
	 	else
	 	{ // c'est un espace
	 	 if (i!=0 && nbesp==0)
	 	 	{	
	 	 	lachaine[i++]=car;nbesp++;	
	 	 	}
	 	}
		}
 }
while(car!='\n' && i<nbMAXcaracAsaisir);
// le caractere \n est rangé dans lachaine !!
lachaine[i]='\0';

if (i==nbMAXcaracAsaisir) 
	if (lachaine[i-2]==' ')
		lachaine[i-2]='\0';
	else
		lachaine[i-1]='\0';
else //i<MAX
if (lachaine[i-1]==' ')
	lachaine[i-1]='\0';

return lachaine;
}



char * lireChaine(const char *  nomChamps, char *chaine, int nbcarac)
{
printf("%s  ",nomChamps);
lire(chaine,nbcarac); // lire du TP4 (modifiée)
return chaine;
}

int * lireInt(const char *  nomChamps, int *champ)
{
printf("%s  ", nomChamps);
scanf("%d", champ);
while(getchar() != '\n');
return *champ;
}

void afficherChaine(const char *nomChamp, const char *valeur)
{
printf("%s %s",nomChamp, valeur);

}

void afficherInt(const char *nomChamp, int valeur)
{
printf("%s %d",nomChamp, valeur);

}


