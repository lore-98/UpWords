//HEADER PER LA DEFINIZIONE DEL TABELLONE DI GIOCO//
#ifndef GRIGLIA_H
#define GRIGLIA_H
#include <iostream>

using namespace std;

//definizione struttura della singola cella//
struct cella{
    int indice=0;
    string lettera="";
};

//dimensione tabellone//
const int MAXRIGHE=10;
const int MAXCOLONNE=10;


//definizione tabellone//
cella tabellone[MAXRIGHE][MAXCOLONNE];

#endif // GRIGLIA_H
