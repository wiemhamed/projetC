#include "gestionRdv.h"
#include<stdio.h>
#include<string.h>


int ajouterDonneur(char *filename, Donneur d)
{

    FILE * f=fopen(filename, "a");
    if(f!=NULL)
    {
        fprintf(f,"%d %d %s %d %d %d %s %s %s\n",d.id,d.Cin,d.etab,d.dateRdv.jj,d.dateRdv.mm,d.dateRdv.yy,d.type,d.fume,d.tatouage);
        fclose(f);
        return 1;
    }
    else return 0;


}


int modifierDonneur( char *filename, int id, Donneur nouv)
{

    int tr=0;
    Donneur d;
    FILE * f=fopen(filename, "r");
    FILE * f2=fopen("nouv.txt", "w");
    if(f!=NULL && f2!=NULL)
    {
        while(fscanf(f,"%d %d %s %d %d %d %s %s %s\n",&d.id,&d.Cin,d.etab,&d.dateRdv.jj,&d.dateRdv.mm,&d.dateRdv.yy,d.type,d.fume,d.tatouage)!=EOF)
        {
            if(d.id== id)
            {
                fprintf(f2,"%d %d %s %d %d %d %s %s %s\n",nouv.id,nouv.Cin,nouv.etab,nouv.dateRdv.jj,nouv.dateRdv.mm,nouv.dateRdv.yy,nouv.type,nouv.fume,nouv.tatouage);
                tr=1;
            }
            else
                fprintf(f2,"%d %d %s %d %d %d %s %s %s\n",d.id,d.Cin,d.etab,d.dateRdv.jj,d.dateRdv.mm,d.dateRdv.yy,d.type,d.fume,d.tatouage);

        }
    }
    fclose(f);
    fclose(f2);
    remove(filename);
    rename("nouv.txt", filename);
    return tr;

}


int supprimerDonneur(char *filename, int id)
{


    int tr=0;
    Donneur d;
    FILE * f=fopen(filename, "r");
    FILE * f2=fopen("nouv.txt", "w");
    if(f!=NULL && f2!=NULL)
    {
        while(fscanf(f,"%d %d %s %d %d %d %s %s %s\n",&d.id,&d.Cin,d.etab,&d.dateRdv.jj,&d.dateRdv.mm,&d.dateRdv.yy,d.type,d.fume,d.tatouage)!=EOF)
        {
            if(d.id== id)
                tr=1;
            else
                fprintf(f2,"%d %d %s %d %d %d %s %s %s\n",d.id,d.Cin,d.etab,d.dateRdv.jj,d.dateRdv.mm,d.dateRdv.yy,d.type,d.fume,d.tatouage);
        }
    }
    fclose(f);
    fclose(f2);
    remove(filename);
    rename("nouv.txt", filename);
    return tr;


}

Donneur chercherDonneur(char *filename, int id )
{

    Donneur d;
    int tr=0;
    FILE * f=fopen(filename, "r");
    if(f!=NULL)
    {
        while(tr==0&& fscanf(f,"%d %d %s %d %d %d %s %s %s\n",&d.id,&d.Cin,d.etab,&d.dateRdv.jj,&d.dateRdv.mm,&d.dateRdv.yy,d.type,d.fume,d.tatouage)!=EOF)
        {
            if(d.id== id)
                tr=1;
        }
    }
    fclose(f);
    if(tr==0)
        d.id=-1;
    return d;


}


int listeRDV(char *filename,char *etab,int jj, int mm,int yy,Donneur *resultat)
{

    Donneur d;

    int i = 0;
    FILE * f=fopen(filename, "r");
    if(f!=NULL)
    {
        while( fscanf(f,"%d %d %s %d %d %d %s %s %s\n",&d.id,&d.Cin,d.etab,&d.dateRdv.jj,&d.dateRdv.mm,&d.dateRdv.yy,d.type,d.fume,d.tatouage)!=EOF)
        {
            if(strcmp(d.etab, etab) == 0  && d.dateRdv.jj == jj && d.dateRdv.mm == mm && d.dateRdv.yy == yy)
            {
                resultat[i] = d;
                i++;
            }
        }
    }
    fclose(f);
    return i;


}


int nbEts(char *filename)
{
    ets e;

    int i = 0;
    FILE * f=fopen(filename, "r");
    if(f!=NULL)
    {
        while( fscanf(f,"%d %s %s %d %s %d\n",&e.id,e.nom,e.adresse,&e.capacite,e.region,&e.telephone)!=EOF)
        {


            i++;

        }
    }
    fclose(f);
    return i;

}



float moyRDV_ETS(char *filename1 , char *filename , int jj , int mm, int yy ){

      Donneur d;
    float moyenne = 0;
    int i = 0;
    FILE * f=fopen(filename, "r");
    if(f!=NULL)
    {
        while( fscanf(f,"%d %d %s %d %d %d %s %s %s\n",&d.id,&d.Cin,d.etab,&d.dateRdv.jj,&d.dateRdv.mm,&d.dateRdv.yy,d.type,d.fume,d.tatouage)!=EOF)
        {
            if( d.dateRdv.jj == jj && d.dateRdv.mm == mm && d.dateRdv.yy == yy)
            {

                i++;
            }
        }
    }
    fclose(f);
      int nb = nbEts(filename1);

     if (i > 0){
        moyenne = (float)i / (float)nb;
        return (float)moyenne;
      }

       return moyenne;

}
