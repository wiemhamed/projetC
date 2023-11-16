#ifndef GESTIONRDV_H_INCLUDED
#define GESTIONRDV_H_INCLUDED
typedef struct {
 int jj;
 int mm;
 int yy;


}Date;
typedef struct {
  int id ;
  int Cin;
  char etab[50];
  Date dateRdv;
  char type[50];
  char fume[50];
  char tatouage[50];


}Donneur;


typedef struct{
    int id;
    char nom[50];
    char adresse[50];
    int capacite;
    char region[50];
    int telephone;
}ets;
int ajouterDonneur(char *, Donneur );
int modifierDonneur( char *, int, Donneur );
int supprimerDonneur(char *, int );
Donneur chercherDonneur(char *, int);
int listeRDV(char *,char *,int , int ,int,Donneur *);
int nbEts(char *);
float moyRDV_ETS(char * , char * , int , int , int );
#endif // GESTIONRDV_H_INCLUDED
