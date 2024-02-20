//HEADER CHE CONTIENE LE FUNZIONI PER IL CALCOLO DEL PUNTEGGIO//
#ifndef PUNTEGGIO_H
#define PUNTEGGIO_H
#include <iostream>
#include <vector>
#include <string>
#include "griglia.h"

using namespace std;

int calcolo_punteggio_tabellone(cella tabellone[][MAXCOLONNE],cella tabellone_vecchio[][MAXCOLONNE]) //funzione che ritorna il punteggio della mossa del giocatore
{
    bool sentinella_x2=true; //sentinella che si attiva quando una parola è composta da sole lettere a livello 1 (implica il punteggio doppio)
    bool parola_nuova=false; //sentinella che si attiva quando viene rilevata una parola nuova
    bool presenza_parola=false; //sentinella che segnala presenza di una parola
    string parola; //variabile utilizzata per memorizzare la parola trovata
    int punteggio_parziale=0; //variabile che contiene il punteggio parziale delle singole parole
    int punteggio_globale=0; //variabile che contiene il punteggio globale totalizzato nel turno attuale

    //ANALISI PAROLE ORIZZONTALI//
    for(unsigned int x=0;x<MAXRIGHE;x++)
    {
        for(unsigned int y=0;y<MAXCOLONNE;y++)
        {
            if(tabellone[x][y].lettera.empty()==false) //se trovo una lettera
            {
                presenza_parola=true; //segnalo la presenza di una parola
                parola=parola+tabellone[x][y].lettera; //compongo parola
                ++punteggio_parziale; //aumento il punteggio parziale
                if(tabellone[x][y].indice!=1) //se ce una lettera superiore al primo livello
                {
                    ++punteggio_parziale; //aumento il punteggio parziale
                    sentinella_x2=false; //sentinella parola al primo livello disattivata
                }
                if(tabellone[x][y].lettera != tabellone_vecchio[x][y].lettera) //se la lettera è diversa dalla lettera del tabellone vecchio allora si attiva la sentinella che indica la presenza di una parola nuova
                    parola_nuova=true;
            }

            else //se trovo uno spazio bianco
            {
                if(presenza_parola==true && parola.length()>=3 && parola_nuova==true) //e se avevo trovato una parola in precedenza nuova e di lunghezza >3
                {
                    if(sentinella_x2==true) //se la parola sta tutta al livello 1
                        punteggio_parziale=punteggio_parziale*2; //raddoppio il suo punteggio
                    punteggio_globale=punteggio_globale+punteggio_parziale; //aggiungo al punteggio globale il punteggio parziale
                }
                //resetto variabili//
                punteggio_parziale=0;
                parola.clear();
                sentinella_x2=true;
                parola_nuova=false;
                presenza_parola=false;

            }


            if(y==9) //se mi trovo all'ultima colonna
            {
                if(presenza_parola==true && parola.length()>=3 && parola_nuova==true) //e se avevo trovato una parola in precedenza nuova e di lunghezza >3
                {
                    if(sentinella_x2==true) //se la parola sta tutta al livello 1
                        punteggio_parziale=punteggio_parziale*2; //raddoppio il suo punteggio
                    punteggio_globale=punteggio_globale+punteggio_parziale; //aggiungo al punteggio globale il punteggio parziale
                }
                //resetto variabili//
                punteggio_parziale=0;
                parola.clear();
                sentinella_x2=true;
                parola_nuova=false;
                presenza_parola=false;
            }
        }
        //resetto variabili di sicurezza//
        punteggio_parziale=0;
        parola.clear();
        sentinella_x2=true;
        parola_nuova=false;
        presenza_parola=false;
    }

    //ANALISI PAROLE VERTICALI//
    for(unsigned int y=0;y<MAXCOLONNE;y++)
    {
        for(unsigned int x=0;x<MAXRIGHE;x++)
        {
            if(tabellone[x][y].lettera.empty()==false) //se trovo una lettera
            {
                presenza_parola=true; //segnalo la presenza di una parola
                parola=parola+tabellone[x][y].lettera; //compongo parola
                ++punteggio_parziale; //aumento il punteggio parziale
                if(tabellone[x][y].indice!=1) //se ce una lettera superiore al primo livello
                {
                    ++punteggio_parziale; //aumento il punteggio parziale
                    sentinella_x2=false; //sentinella parola al primo livello disattivata
                }
                if(tabellone[x][y].lettera != tabellone_vecchio[x][y].lettera) //se la lettera è diversa dalla lettera del tabellone vecchio allora si attiva la sentinella che indica la presenza di una parola nuova
                    parola_nuova=true;
            }

            else //se trovo uno spazio bianco
            {
                if(presenza_parola==true && parola.length()>=3 && parola_nuova==true) //e se avevo trovato una parola in precedenza nuova e di lunghezza >3
                {
                    if(sentinella_x2==true) //se la parola sta tutta al livello 1
                        punteggio_parziale=punteggio_parziale*2; //raddoppio il suo punteggio
                    punteggio_globale=punteggio_globale+punteggio_parziale; //aggiungo al punteggio globale il punteggio parziale
                }
                //resetto variabili//
                punteggio_parziale=0;
                parola.clear();
                sentinella_x2=true;
                parola_nuova=false;
                presenza_parola=false;

            }

            if(x==9) //se mi trovo all'ultima colonna
            {
                if(presenza_parola==true && parola.length()>=3 && parola_nuova==true) //e se avevo trovato una parola in precedenza nuova e di lunghezza >3
                {
                    if(sentinella_x2==true) //se la parola sta tutta al livello 1
                        punteggio_parziale=punteggio_parziale*2; //raddoppio il suo punteggio
                    punteggio_globale=punteggio_globale+punteggio_parziale; //aggiungo al punteggio globale il punteggio parziale
                }
                //resetto variabili//
                punteggio_parziale=0;
                parola.clear();
                sentinella_x2=true;
                parola_nuova=false;
                presenza_parola=false;
            }
        }
        //resetto variabili di sicurezza//
        punteggio_parziale=0;
        parola.clear();
        sentinella_x2=true;
        parola_nuova=false;
        presenza_parola=false;
    }

    return punteggio_globale;
}

#endif // PUNTEGGIO_H
