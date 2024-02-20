//LIBRERIE//

#include <iostream>
#include <vector>
#include <string>
#include "players.h"
#include "initialization.h"
#include "crea_dizionario.h"
#include "check_word.h"
#include "coordinate_direzione.h"
#include "controlli.h"
#include "stampa.h"
#include "inserimento_parola.h"
#include "griglia.h"
#include "turno_giocatore.h"


using namespace std;


int main()
{
    //PRESENTAZIONE//
    inizializzazione();

    string risposta;
    cout<<"Digitare 'R' per visionare le regole del gioco oppure 'C' per continuare : ";
    cin>>risposta;
    for(auto &c:risposta)
        c=toupper(c);
    while(risposta!="R" && risposta!="C")
    {
        cout<<"ERRORE:codifica errata, riprovare : ";
        cin>>risposta;
        for(auto &c:risposta)
            c=toupper(c);
    }
    if(risposta=="R")
        regoledelgioco();
    else
        system("cls");

    nodo* radice=creadizionario(); //creazione del dizionario
    vector<player> playerlist=crealistagiocatori(radice); //vettore che contiene l'elenco dei giocatori

    cout<<endl<<"DIZIONARIO CARICATO CON SUCCESSO"<<endl;




    //GESTIONE TURNO DEI GIOCATORI//
    size_t num_passi=0; //conteggio dei passi consecutivi
    for(unsigned int giocatore=0;giocatore<playerlist.size();giocatore++)
    {
        bool rifai_turno=true;
        system("pause");
        system("cls");
        cout<<endl;
        stampa(tabellone);
        cout<<"Turno di "<<playerlist[giocatore].nome<<" (Punti :"<<playerlist[giocatore].punteggio<<")"<<endl;
        cout<<"lettere : ";
        for(unsigned int i=0;i<playerlist[giocatore].lettere.size();i++)
            cout<<playerlist[giocatore].lettere[i];
        cout<<endl;



        char mossa;
        cout<<"Scegli mossa, 'T' = gioca turno / 'P' = passa turno : ";
        cin>>mossa;
        while(check_mossa(mossa)==false)
        {
            cout<<"ERRORE:codifica errata, reinserisci la mossa. 'T' = turno , 'P' = passa : ";
            cin>>mossa;
        }

        if(mossa=='T') //se il giocatore vuole giocare il suo turno
        {
            num_passi=0; //azzara il numero dei passi consecutivi
            while(rifai_turno==true)
            {
                system("pause");
                turno_di_gioco(playerlist[giocatore],radice,rifai_turno); //comincia il suo turno
            }
        }
        else //altrimenti aumenta il numero dei passi consecutivi
            num_passi++;

        if(giocatore==(playerlist.size()-1)) //se si è appena concluso il turno dell'ultimo giocatore
            giocatore=-1; //resetta il contatore dei giocatori
        if(num_passi==playerlist.size()) //se il gioco è giunto al termine
            giocatore=5; //termina il ciclo

    }

    system("pause");
    system("cls");
    cout<<setw(65)<<"FINE DEL GIOCO"<<endl;
    for(unsigned int j=0;j<playerlist.size();j++) //sottrazione punti finale
    {
        playerlist[j].punteggio=playerlist[j].punteggio-(playerlist[j].lettere.size()*5);
    }

    //ORDINAMENTO LISTA GIOCATORI IN BASE AL PUNTEGGIO BUBBLE SORT//

    bool swapped;
    int primo=0;
    int ultimo=playerlist.size();
    do
    {
        swapped=false;
        int corrente=primo+1;
        while(corrente!=ultimo)
        {
            if((playerlist[corrente-1].punteggio)< playerlist[corrente].punteggio)
            {
                swapp(playerlist[corrente-1],playerlist[corrente]);
                swapped=true;
            }
            corrente++;
        }
        ultimo--;
    }
    while(swapped);

    for(unsigned int t=0;t<playerlist.size();t++)
    {
        cout<<setw(35)<<" "<<t+1<<" classificato : "<<playerlist[t].nome<<" - Punti : "<<playerlist[t].punteggio<<endl;
    }







    return 0;
}
