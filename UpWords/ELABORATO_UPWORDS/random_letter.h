//PRELEVARE UN ELEMENTO RANDOM DA UN VETTORE DATO//
#ifndef RANDOM_LETTER_H
#define RANDOM_LETTER_H


#include <iostream>
#include <cstdlib>
#include <time.h>
#include <vector>
#include "sacchetto.h"

using namespace std;

char estrailettera()
{
    char temp; //variabile temporale
    srand(time(NULL) ); //inizializzazione del seme

    int random_index = rand() % letters.size(); //indice ottenuto randomicamente


    temp=letters.at(random_index);


    letters.erase(letters.begin()+random_index); //al vettore viene eliminato l'elemento che è stato prelevato

    return temp;
}


#endif // RANDOM_LETTER_H
