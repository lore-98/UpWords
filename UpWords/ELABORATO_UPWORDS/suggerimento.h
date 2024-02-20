//HEADR PER LA FUNZIONE CHE IMPLEMENTA IL SUGGERIMENTO//
/*Il suggerimento si basa su una funzione ricorsiva che trova
 * tutte i possibili anagrammi di una parola e delle sotto parole
 * ricavabili dalla parola iniziale*/

#ifndef SUGGERIMENTO_H
#define SUGGERIMENTO_H
#include <iostream>
#include <string>
#include <vector>
#include "check_word.h"
#include "players.h"

using namespace std;



void suggerimento(string word, string res,nodo* radice,vector<string> &parole_suggerite)
{

    if(res.length()>2 && check_dictionary(radice,res))
        parole_suggerite.push_back(res);
    for(unsigned int i=0;i<word.length();i++)
        suggerimento(string(word).erase(i,1),res+word[i],radice,parole_suggerite);
}


#endif // SUGGERIMENTO_H

