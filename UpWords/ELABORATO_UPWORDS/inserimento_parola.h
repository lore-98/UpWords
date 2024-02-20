//HEADER PER L'INSERIMENTO DELLE PAROLE//
#ifndef INSERIMENTO_PAROLA_H
#define INSERIMENTO_PAROLA_H
#include <iostream>
#include <string>
#include <vector>
#include "griglia.h"
#include "crea_dizionario.h"
#include "check_word.h"
#include "stampa.h"
#include "punteggio.h"
#include "players.h"
#include "controlli.h"
#include "coordinate_direzione.h"


using namespace std;


bool check_tabellone(cella tabellone[][MAXCOLONNE], nodo* radice) //controlla se le parole nel tabellone esistono e ritorna true se è presente un errore
{
    string parola;

    //CONTROLLO PAROLE ORIZZONTALI//
    for(unsigned int x=0;x<MAXRIGHE;x++)
    {
        parola.clear();
        for(unsigned int y=0;y<MAXCOLONNE;y++)
        {
            if(tabellone[x][y].lettera.empty()==true) //se la cella nel tabellone è vuota
            {
                if(parola.empty()==false && parola.length()>=3) //e se la parola è stata composta ed ha più di 3 lettere
                {
                    if(check_dictionary(radice,parola)==false) //e se la parola non è presente nel dizionario
                        return true;    //ritorna true ovvero presenza di errore
                }
                parola.clear(); //svuota parola
            }
            else //se la cella nel tabellone contiene una lettera
            {
                parola=parola+tabellone[x][y].lettera; //assembla la parola
            }

            if(y==9 && parola.empty()==false) //se mi trovo all'ultima cella della riga e ho una parola assemblata
            {
                if(parola.length()>=3) //e se la parola è lunga almeno 3 lettere
                {
                    if(check_dictionary(radice,parola)==false) //e se la parola non è presente nel dizionario
                        return true;    //ritorna true ovvero presenza di errore
                }
            }

        }
    }

    //CONTROLLO PAROLE VERTICALI//
    for(unsigned int y=0;y<MAXCOLONNE;y++)
    {
        parola.clear();
        for(unsigned int x=0;x<MAXCOLONNE;x++)
        {
            if(tabellone[x][y].lettera.empty()==true) //se la cella nel tabellone è vuota
            {
                if(parola.empty()==false && parola.length()>=3) //e se la parola è stata composta ed ha più di 3 lettere
                {
                    if(check_dictionary(radice,parola)==false) //e se la parola non è presente nel dizionario
                        return true;    //ritorna true ovvero presenza di errore
                }
                parola.clear(); //svuota parola
            }
            else //se la cella nel tabellone contiene una lettera
            {
                parola=parola+tabellone[x][y].lettera; //assembla la parola
            }

            if(x==9 && parola.empty()==false) //se mi trovo all'ultima cella della riga e ho una parola assemblata
            {
                if(parola.length()>=3) //e se la parola è lunga almeno 3 lettere
                {
                    if(check_dictionary(radice,parola)==false) //e se la parola non è presente nel dizionario
                        return true;    //ritorna true ovvero presenza di errore
                }
            }

        }
    }
    return false; //se non sono ancora stati rilevati errori allora il tabelloni non contiene errori e tutte la parole su di esso presenti esistono
}

void inserimentointabella(cella tabellone[][MAXCOLONNE],string parola, int coordx, int coordy,char direzione, nodo* radice, player &giocatore,bool &rifai_turno) //funzione che mi permette di inserire una parola nella tabella
{
    rifai_turno=false;
    cella vecchio_tabellone[MAXRIGHE][MAXCOLONNE];
    for(auto &c:parola)
        c=toupper(c);

    player copiagiocatore=giocatore; //copia del giocatore

    //COPIA DEL TABELLONE//
    for(unsigned int x=0;x<MAXRIGHE;x++)
        for(unsigned int y=0;y<MAXCOLONNE;y++)
        {
            vecchio_tabellone[x][y]=tabellone[x][y];
        }

    int x=coordx-1;
    int y=coordy-1;
    direzione=tolower(direzione);
    vector<char> word;
    int cont_canc=0;
    bool errore_livello=false; //sentinella che si attiva se una parola non può essere inserita per via di un problema coi livelli
    bool errore_sacchetto=false; //sentinella che si attiva quando non posso comporre la parola con le lettere a disposizione
    bool errore_lunghezza=false; //sentinells che che si attiva quando la parola esce dsi bordi
    bool errore_inserimento_centro=false; //sentinella che si attiva quando il primo inserimento non passa per il centro
    bool errore_inserimento_slegato=true; //impedisce l'inserimento di una parola che non incrocia con nessuna delle parole già presenti

    //COPIA DELLA PAROLA//
    for(auto lettera: parola)
        word.push_back(lettera);

    //controllo orizzontale fnziona, DA RIFARE VERTICALE
    if(direzione=='o') //caso parola ORIZZONTALE
    {
        for(unsigned int i=0;i<word.size();i++) //per ogni lettera della parola
        {


            if(errore_sacchetto!=true)
            {
                //if(i==0)
                errore_sacchetto=true;
                if(tabellone[x][y+i].lettera.empty()==true) //se la cella è libera inserisci la lettera e incrementa indice
                {
                    tabellone[x][y+i].lettera=word[i];
                    tabellone[x][y+i].indice++;
                    for(unsigned int w=0;w<giocatore.lettere.size();w++)
                    {
                        if(giocatore.lettere[w]==word[i])
                        {
                            errore_sacchetto=false;
                            giocatore.lettere.erase(giocatore.lettere.begin()+w);
                            cont_canc++;
                            break;
                        }
                    }
                }
                else //se la cella non è libera
                {
                    errore_inserimento_slegato=false;
                    if(tabellone[x][y+i].indice<5) //e se non ci sono già 5 lettere impilate sostituisci lettera e aumenta indice
                    {
                        if(tabellone[x][y+i].lettera[0]!=word[i])
                        {
                            tabellone[x][y+i].lettera=word[i];
                            tabellone[x][y+i].indice++;

                            for(unsigned int w=0;w<giocatore.lettere.size();w++)
                            {
                                if(giocatore.lettere[w]==word[i])
                                {
                                    errore_sacchetto=false;
                                    if(giocatore.lettere[w]!=word[i])
                                    {
                                        giocatore.lettere.erase(giocatore.lettere.begin()+w);
                                        cont_canc++;
                                        break;
                                    }
                                }
                            }
                        }
                        errore_sacchetto=false;
                    }
                    else // e se ci sono già 5 lettere non fare nulla
                    {
                        errore_livello=true;
                    }
                }
            }
        }
    }

    if(direzione=='v') //caso parola VERTICALE
    {
        for(unsigned int i=0;i<word.size();i++) //per ogni lettera della parola
        {
            if(errore_sacchetto!=true)
            {
                // if(i==0)
                errore_sacchetto=true;
                if(tabellone[x+i][y].lettera.empty()==true) //se la cella è libera inserisci la lettera e incrementa indice
                {
                    tabellone[x+i][y].lettera=word[i];
                    tabellone[x+i][y].indice++;
                    for(unsigned int w=0;w<giocatore.lettere.size();w++)
                    {
                        if(giocatore.lettere[w]==word[i])
                        {
                            errore_sacchetto=false;
                            giocatore.lettere.erase(giocatore.lettere.begin()+w);
                            cont_canc++;
                            break;
                        }
                    }
                }
                else //se la cella non è libera
                {
                    errore_inserimento_slegato=false;
                    if(tabellone[x+i][y].indice<5) //e se non ci sono già 5 lettere impilate sostituisci lettera e aumenta indice
                    {
                        if(tabellone[x+i][y].lettera[0]!=word[i])
                        {
                            tabellone[x+i][y].lettera=word[i];
                            tabellone[x+i][y].indice++;

                            for(unsigned int w=0;w<giocatore.lettere.size();w++)
                            {
                                if(giocatore.lettere[w]==word[i])
                                {
                                    errore_sacchetto=false;
                                    if(giocatore.lettere[w]!=word[i])
                                    {
                                        giocatore.lettere.erase(giocatore.lettere.begin()+w);
                                        cont_canc++;
                                        break;
                                    }
                                }
                            }
                        }
                        errore_sacchetto=false;

                    }
                    else // e se ci sono già 5 lettere non fare nulla
                    {
                        errore_livello=true;
                    }
                }
            }
        }
    }



    if(check_tabellone(tabellone, radice)==true)
        cout<<"ERRORE:sono presenti nel tabellone parole che non esistono"<<endl;
    if(errore_livello==true)
        cout<<"ERRORE:una lettera non puo' essere inserita perche' gia' stato raggiunto il livello massimo"<<endl;
    if(errore_sacchetto==true)
        cout<<"ERRORE:la parola non si puo' creare con le lettere a disposizione"<<endl;
    if(parola.length()<3)
    {
        errore_lunghezza=true;
        cout<<"ERRORE:la parola deve essere almeno lunga 3 lettere"<<endl;
    }

    if(check_primo_turno(vecchio_tabellone)==true && check_centro(coordx,coordy,parola,direzione)==false) // solo se è il primo turno controlla che l'inserimento passi dal centro
    {
        cout<<"ERRORE:il primo inserimento deve passare per una delle 4 celle centrali"<<endl;
        errore_inserimento_centro=true;
    }

    if(check_primo_turno(vecchio_tabellone)==false && errore_inserimento_slegato==true)
        cout<<"ERRORE:non e' possibile inserire una parola senza che ne intersechi un'altra"<<endl;

    if(cont_canc==7) //se sono state usate tutte e 7 le lettere nella mano del giocatore allora +20 punti bonus
        giocatore.punteggio=giocatore.punteggio+20;
    for(int q=0;q<cont_canc;q++) //se sono state usate delle lettere ridai al giocatore il numero di lettere usate
        giocatore.lettere.push_back(estrailettera());

    //RIPRISTINO DEL TABELLONE VECCHIO E DEL GIOCATORE//
    if(check_tabellone(tabellone,radice)==true || errore_livello==true || errore_sacchetto==true || errore_lunghezza==true || errore_inserimento_centro==true || (check_primo_turno(vecchio_tabellone)==false && errore_inserimento_slegato==true))
    {
        for(unsigned int x=0;x<MAXRIGHE;x++)
            for(unsigned int y=0;y<MAXCOLONNE;y++)
            {
                tabellone[x][y]=vecchio_tabellone[x][y];
            }
        giocatore=copiagiocatore;
        rifai_turno=true;
        //  turno_di_gioco(giocatore,radice);
    }

    giocatore.punteggio=giocatore.punteggio+calcolo_punteggio_tabellone(tabellone,vecchio_tabellone);
    stampa(tabellone);
}


#endif // INSERIMENTO_PAROLA_H
