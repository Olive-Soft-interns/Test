//Yosra FARHAT IF3 B , Aya ZOUAY IF3 A
#include <stdio.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void charge_tab (int t[], int n)
{
     int val;
     int hanen ;
     int o ;
int a ;

	 int k;// ligne ajoutée
int olive;// deuxieme ligne ajoutée
	 for(int i=0;i<n;i++)
        {
        printf("Entrez la valeur a saisir dans le tableau: ");
        scanf("%d", &val);
        t[i]=val;
        }

}
void Affiche (int tab[], int n)
{
    printf("/**/ Affichage du tableau /**/\n");
    for(int i=0;i<n;i++){
        printf("%d \n",tab[i]);
    }
    printf("/**/ Fin Affichage /**/\n");
}

int Recherche_elt (int tab[],int n,int element){

    for(int i=0;i<n;i++)
        {
        if(tab[i] == element){
            return 1;
        }
        }
    return 0;
}
void decalage(int t[],int n,int pos)
{

    for(int i=pos;i<n-1;i++)
    {
        t[i]=t[i+1];
    }

}

void Supprimer(int t[],int val,int *n){

     int taille=*n;
    for(int i=0; i<taille; i++){
        if(t[i]==val){
            decalage(t,taille,i);
           (*n)--;
        }

    }
}

void mouvementGD(int t[],int n)
{

    int dernier_elt = t[0];
    for(int i=0;i<n-1;i++){
        t[i] = t[i+1];
    }
    t[n-1]=dernier_elt;
}

void mouvementDG(int t[], int n){

    int premier_elt = t[n-1];
    for(int i=n-1;i>0;i--){
        t[i]=t[i-1];
    }
    t[0]=premier_elt;
}

void permuter(int *x,int *y)
 {
     int a;
     a=*x;
     *x=*y;
     *y=a;
 }

 void get_i_min_i_max(int t[],int n, int i , int *i_min,int *i_max)
{
    int j;
    for (*i_min=*i_max=i,j=i+1;j<n-i-1;j++)
    {
        if (t[j]<t[*i_min])
            *i_min=j;

        if (t[j]>t[*i_max])
            *i_max=j;

    }
}

void tri_min_max(int t[], int n)
{
    int i_min,i_max;
    i_min=0; i_max=0;
    for (int i=0; i<n/2; i++)
     {
      get_i_min_i_max(t,n,i,&i_min,&i_max);
        if(i_min!=i)
            permuter (&t[i],&t[i_min]);
        if(i_max!=n-i-1)
        {
            if (i_max!=i)
                permuter(&t[n-i-1],&t[i_max]);
            else
                permuter(&t[n-i-1],&t[i_min]);
        }
}
}

int main()
{
    int t[100];
    int n;
    int element;
    int val;
    int opt;

    printf("Donner la taille du tableau:\n");
        scanf("%d",&n);
        charge_tab(t,n);




        printf("Menu\n");
            printf("Entrez le chiffre correspondant a votre choix:\n");
            printf("1:Recherche d'un element dans un tableau\n");
            printf("2:Supprimer un element du tableau\n");
            printf("3:Afficher le tableau\n");
            printf("4:Mouvement DROITE_GAUCHE\n");
            printf("5:Mouvement GAUCHE_DROITE\n");
            printf("6:Tri min-max\n");
            printf("7:exit\n");

        printf("Choisir une option de 1 a 7:\n");
        scanf("%d",&opt);



        switch (opt)
        {


        case 1:

       printf("Donner la valeur a rechercher:\n");
        scanf("%d",&element);
            if(Recherche_elt(t,n,element))
                printf("La valeur existe\n");
            else
                printf("La valeur n'existe pas\n");

            break;

        case 2:
             printf("Donner la valeur a supprimer:\n");
            scanf("%d",&val);
             printf("tableau  avant suppression\n");
             Affiche(t,n);
            Supprimer(t,val,&n);
            printf("tableau  apres suppression\n");
            Affiche(t,n);

            break;

        case 3:
            Affiche(t,n);
            printf("\n");

            break;

        case 4:
    printf("tableau apres mouvement DG\n");
    mouvementDG(t,n);
    Affiche(t,n);

            break;

        case 5:
          printf("tableau apres mouvement GD\n");
    mouvementGD(t,n);
    Affiche(t,n);
            break;

        case 6:
    printf("tableau apres tri min_max\n");
    tri_min_max(t,n);
    Affiche(t,n);
            break;

        default:
            exit(0);
            break;


        }
}















