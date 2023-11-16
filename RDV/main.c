#include <stdio.h>
#include <stdlib.h>
#include"gestionRdv.h"
int main()
{
     char filename[50]="wiem.txt";
     char filename1[50]="ets.txt";
    Donneur d = {22,586588,"sang",12,12,2021,"palsmatique","non","non"};
   /* int x = ajouterDonneur(filename,d);
    if(x==1){
        printf(" ajout ");
    }else{
        printf(" failed ");

    }*/
   /* int y = modifierDonneur(filename,22,d);

     if(y==1){
        printf(" modifié ");
    }else{
        printf(" failed ");

    }*/

    /*int z = supprimerDonneur(filename,22);
     if(z==1){
        printf(" supprimer ");
    }else{
        printf(" failed ");

    }*/

   /* Donneur d1;
     d1 = chercherDonneur(filename,22);
      printf("%s",d1.etab);*/

      Donneur d4[100];
      int k = listeRDV(filename,"sang",12,12,2021,d4);
      for(int i =0; i <k+1 ; i++){
          printf("%s",d4[i].etab);
      }

    /*int a = nbEts(filename1);
    printf("%d",a);*/

    float moyenne;
    moyenne = moyRDV_ETS(filename1,filename,12,12,2021);
    printf("%f",moyenne);

    return 0;
}
