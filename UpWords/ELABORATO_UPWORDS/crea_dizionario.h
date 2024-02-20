//HEADER PER LA CREAZIONE DEL DIZIONARIO//
#ifndef CREA_DIZIONARIO_H
#define CREA_DIZIONARIO_H
#include <iostream>
#include <string>
#include <fstream>
#include <stdio.h>
#include <ctype.h>

using namespace std;

const int DIMENSIONE_ALFABETO='z' - 'a' + 1;

struct nodo{
    bool fine;
    nodo* figli[DIMENSIONE_ALFABETO];
};

void aggiungi_parola(nodo*& radice,string parola,size_t posizione=0)
{
    if (radice == nullptr) // se il sottoalbero corrente è vuoto
    {
        radice = new nodo(); // creo il nodo
        radice->fine = false; // inizializzo a non stop
        for (char l = 'A'; l <= 'Z'; ++l) // per ogni figlio
        {
            radice->figli[l - 'A'] = nullptr; // lo inizializzo a nullptr
        }
    }
    if (posizione == parola.length()) // se sono arrivato alla fine della parola
    {
        radice->fine = true; // segno il nodo corrente come stop
    }
    else
    {
        aggiungi_parola(radice->figli[parola[posizione] - 'A'], parola, posizione + 1); // continuo l'inserimento nel sottoalbero relativo alla prossima lettera
    }
}



nodo* creadizionario()
{

    ifstream file("words_italian.txt");
    string parola;
    nodo* radice=nullptr;


    while(getline(file,parola))
    {
        bool valido=true;
        for(auto &c: parola)
        {
            if(!isalpha(c))
                valido=false;
            c=toupper(c);
        }
        if(valido==true && parola.length()>=3)
            aggiungi_parola(radice,parola);
    }

    return radice;
}



#endif // CREA_DIZIONARIO_H
