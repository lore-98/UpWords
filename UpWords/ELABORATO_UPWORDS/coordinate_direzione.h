//HEADER CHE CONTIENE LE FUNZIONI PER I CONTROLLI PER L'INSERIMENTO DELLE PAROLE NEL TABELLONE//
#ifndef COORDINATE_DIREZIONE_H
#define COORDINATE_DIREZIONE_H
#include <iostream>
#include "griglia.h"

using namespace std;

bool controlla_limiti_tabellone(string parola, int coordx, int coordy, char direzione)  //funzione che controlla che la parola non esca dai bordi e ritorna true se la parola è valida
{
    direzione=toupper(direzione);
    if(direzione=='V')
    {
        int altezza=coordx-1;
        if((altezza+parola.length())>10)
            return false;
        else
            return true;
    }

    if(direzione=='O')
    {
        int profond=coordy-1;
        if((profond+parola.length())>10)
            return false;
        else
            return true;
    }

    return false;
}


bool controlla_indice(int coordx, int coordy) //funzione che controlla se ho raggiunto il massimo numero di livelli in pila possibili e ritorna true se l'inserimento è valido (solo per una lettera)
{
    int col=coordy-1;
    int riga=coordx-1;

    if(tabellone[riga][col].indice==5)
        return false;
    else
        return true;
}


#endif // COORDINATE_DIREZIONE_H
