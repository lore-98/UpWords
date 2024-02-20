//HEADER CHE CONTIENE IL TURNO DEL GIOCATORE//
#ifndef TURNO_GIOCATORE_H
#define TURNO_GIOCATORE_H
#include <iostream>
#include <vector>
#include <string>
#include "griglia.h"
#include "coordinate_direzione.h"
#include "players.h"
#include "check_word.h"
#include "inserimento_parola.h"
#include "punteggio.h"
#include "controlli.h"
#include "suggerimento.h"


using namespace std;

void turno_di_gioco(player &giocatore,nodo* radice,bool &rifai_turno)
{
    string parola;
    int coordx;
    int coordy;
    char direzione;
    string aiuto;
    system("cls");
    cout<<endl;
    stampa(tabellone);
    cout<<"turno di "<<giocatore.nome<<" (Punti:"<<giocatore.punteggio<<") "<<endl;
    cout<<"lettere : ";
    for(unsigned int i=0;i<giocatore.lettere.size();i++)
        cout<<giocatore.lettere[i];
    cout<<endl;

    cout<<"vuoi un aiuto? si/no : ";
    cin>>aiuto;
    for(auto &i: aiuto)
        i=toupper(i);
    while(aiuto!="SI" && aiuto!="NO")
    {
        cout<<"ERRORE:codifica errata, riprovare : ";
        cin>>aiuto;
        for(auto &i: aiuto)
            i=toupper(i);
    }

    if(aiuto=="SI")
    {
        string word;
        vector<string> parole_suggerite;
        string max;
        for(auto i:giocatore.lettere)
            word=word+i;
        cout<<endl;
        suggerimento(word,"",radice,parole_suggerite);
        if(parole_suggerite.empty())
            cout<<"ops, non ci sono parole suggerite"<<endl;
        else
        {
            max=parole_suggerite[0];
            for(unsigned int j=1;j<parole_suggerite.size();j++)
            {
                if(max<parole_suggerite[j])
                    max=parole_suggerite[j];
            }
            cout<<"suggerimento: "<<max<<endl;
        }
    }


    cout<<"inserisci la parola che vuoi giocare : ";
    cin>>parola;


    coordx=cincoordinatax();
    coordy=cincoordinatay();

    direzione=check_direzione();
    cout<<endl;

    while(controlla_limiti_tabellone(parola,coordx,coordy,direzione)==false)
    {
        cout<<"ERRORE:questa parola con queste coordinate esce dai bordi, riprova"<<endl;
        cout<<"inserisci la parola che vuoi giocare : ";
        cin>>parola;


        coordx=cincoordinatax();
        coordy=cincoordinatay();

        direzione=check_direzione();
        cout<<endl;
    }

    inserimentointabella(tabellone,parola,coordx,coordy,direzione,radice,giocatore,rifai_turno);





}

#endif // TURNO_GIOCATORE_H
