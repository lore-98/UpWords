//HEADER CHE CONTIENE LE FUNZIONI CHE RIGUARDANO I CONTROLLI PER GLI INPUT//
#ifndef CONTROLLI_H
#define CONTROLLI_H
#include <iostream>
#include <string>
#include <vector>
#include "players.h"
#include "griglia.h"

using namespace std;

char check_direzione() //ritorna true se l'inserimento è corretto
{
    char direzione;
    cout<<"inserisci direzione v/o : ";
    cin>>direzione;

    direzione=toupper(direzione);
    while(direzione!='V' && direzione!='O')
    {
        cout<<"ERRORE:codifica errata, riprovare : ";
        cin>>direzione;
        direzione=toupper(direzione);
    }
    return direzione;
}

bool check_centro(int coordx,int coordy,string word,char direzione) //ritorna true se l'inserimento passa dal centro
{
    direzione=tolower(direzione);

    if((coordx==5 && coordy==5) || (coordx==5 && coordy==6) || (coordx==6 && coordy==5) || (coordx==6 && coordy==6))
        return true;


    if(direzione=='o' && (coordx==5 || coordx==6))
    {
        for(unsigned int p=0;p<word.length();p++)
        {
            if((coordy+p)==5 || (coordy+p)==6)
                return true;
        }
        return false;
    }


    if(direzione=='v' && (coordy==5 || coordy==6))
    {
        for(unsigned int p=0;p<word.length();p++)
        {
            if((coordx+p)==5 || (coordx+p)==6)
                return true;
        }
        return false;
    }

    return false; //non arriverà mai a ritornare false

}


bool check_confirmation(char conferma) //ritorna true se la conferma è stata codificata correttamente
{
    conferma=tolower(conferma);
    if(conferma=='s' || conferma=='n')
        return true;
    else
        return false;
}


bool check_mossa(char &mossa) //ritorna true se la scelta della mossa è codificata correttamente
{
    mossa=toupper(mossa);
    if(mossa=='P' || mossa=='T')
        return true;
    else
        return false;
}


bool check_fine(unsigned int num_passi, unsigned int num_giocatori, player giocatore) //ritorna true se il gioco è giunto al termine
{
    if (num_passi==num_giocatori)
        return true;
    if(giocatore.lettere.empty()==true)
        return true;
    return false;
}


int cincoordinatax() //controllo coordinata x
{
    string coordx;
    int cx=0;
    cout<<"Inserisci la riga : ";
    cin>>coordx;
    for(auto i:coordx)
        cx=i-'0'+cx*10;
    while(cx<1 || cx>10)
    {
        cx=0;
        cout<<"ERRORE:codifica errata, riprova : ";
        cin>>coordx;
        for(auto i:coordx)
            cx=i-'0'+cx*10;
    }
    return cx;

}

int cincoordinatay() //controllo coordinata y
{
    string coordy;
    int cy=0;
    cout<<"Inserisci la colonna : ";
    cin>>coordy;
    for(auto i:coordy)
        cy=i-'0'+cy*10;
    while(cy<1 || cy>10)
    {
        cy=0;
        cout<<"ERRORE:codifica errata, riprova : ";
        cin>>coordy;
        for(auto i:coordy)
            cy=i-'0'+cy*10;
    }
    return cy;

}

void swapp(player &primo,player &secondo)
{
    player temp= primo;
    primo=secondo;
    secondo=temp;
}

bool check_primo_turno(cella tabellone[][MAXCOLONNE])
{
    for(int x=0;x<MAXRIGHE;x++)
        for(int y=0;y<MAXCOLONNE;y++)
            if(tabellone[x][y].indice!=0)
                return false;

    return true;
}

#endif // CONTROLLI_H
