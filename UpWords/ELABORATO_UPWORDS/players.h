//HEADER PER LA CREAZIONE DELL'ELENCO DEI GIOCATORI//
#ifndef PLAYERS_H
#define PLAYERS_H


#include <vector>
#include <iostream>
#include <string>
#include <stdlib.h> //isdigit
#include <stdio.h> //isdigit
#include <ctype.h> //isdigit
#include "random_letter.h"
#include "suggerimento.h"
#include "sacchetto.h"

using namespace std;

const int  LETTERE_GIOCATORE=7; //numero delle lettere assegnate ad ogni giocatore ad inizio gioco

//DICHIARAZIONE STRUTTURA GIOCATORE//
struct player{
    string nome;
    int punteggio=0;
    vector<char> lettere;
};

player creagiocatore(int i,nodo* radice)
{
    player nuovogiocatore;
    cout<<"inserisci il nome del "<<i+1<<" giocatore : ";
    cin>>nuovogiocatore.nome;
    for(auto &c: nuovogiocatore.nome)
        c=toupper(c);
    for(unsigned int k=0;k<LETTERE_GIOCATORE;k++)
        nuovogiocatore.lettere.push_back(estrailettera());

    string word;
    vector<string> parole_suggerite;

    for(auto i:nuovogiocatore.lettere)
        word=word+i;
    suggerimento(word,"",radice,parole_suggerite);

    while(parole_suggerite.empty()==true) //se non ci sono parole suggerite
    {
        for(unsigned int t=0;t<nuovogiocatore.lettere.size();t++)
        {
            letters.push_back(nuovogiocatore.lettere[t]);
            nuovogiocatore.lettere.erase(nuovogiocatore.lettere.begin()+t);
        }
    }

    return nuovogiocatore;



}

vector<player> crealistagiocatori(nodo* radice)
{
    //controllo inserimento lettere//
    char numero_giocatori; //numero giocatori in char
    int num_giocatori; //numero giocatori in intero
    int cont_errore=0; //contatore errori
    bool sentinella_errore=false; //sentinella per verificare che non ci siano errori in input
    vector<player> listagiocatori; //vettore che contiene l'elenco dei giocatori
    cout<<"Quanti sono i giocatori?"<<endl;
    cin>>numero_giocatori;

    if(numero_giocatori!='2' && numero_giocatori!='3' && numero_giocatori!='4') //controllo errore nell'input
        sentinella_errore=true;

    while(sentinella_errore==true)
    {
        ++cont_errore;
        system("cls");
        cout<<"ERRORE("<<cont_errore<<"): i giocatori possono essere 2,3,4 "<<endl;
        cout<<"Quanti sono i giocatori?"<<endl;
        cin>>numero_giocatori;

        if(numero_giocatori!='2' && numero_giocatori!='3' && numero_giocatori!='4') //controllo errore nell'input
            sentinella_errore=true;
        else
            sentinella_errore=false;


    }
    num_giocatori=numero_giocatori-'0';

    cout<<endl;

    for(int i=0;i<num_giocatori;i++)
    {
        player giocatore=creagiocatore(i,radice);
        listagiocatori.push_back(giocatore);
        cout<<endl<<"Giocatore : "<<giocatore.nome<<" confermato."<<endl<<endl;
        /*        cout<<"Mano del giocatore "<<giocatore.nome<<" : ";
        for(auto x: giocatore.lettere)
            cout<<x;
        cout<<endl<<endl;
*/
    }


    return listagiocatori;
}

#endif // PLAYERS_H


