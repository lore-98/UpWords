//HEADER CONTENENTE LE FUNZIONI PER I CONTROLLI DELLE PAROLE//
#ifndef CHECK_WORD_H
#define CHECK_WORD_H

#include <vector>
#include <string>
#include <iostream>
#include "crea_dizionario.h"

using namespace std;

bool check_word(vector<char> mano_giocatore, string word)  //controlla se la parola candidata si può creare con le parole della mano del giocatore
{
    vector<char> copia_mano; // vettore utilizzato per copiare la mano del giocatore utilizzato per lavorarci sopra
    bool sentinella_valida=true;
    bool gia_cancellato=false;

    for(auto c: mano_giocatore) //carico il vettore copia_mano
        copia_mano.push_back(c);
    for(unsigned int i=0;i<word.length();i++)
    {
        gia_cancellato=false;
        for(unsigned int j=0;j<copia_mano.size();j++)
        {
            if(word[i]==copia_mano[j] && gia_cancellato==false)
            {
                copia_mano.erase(copia_mano.begin()+j);
                gia_cancellato=true;
            }
        }
        if(gia_cancellato==false)
            sentinella_valida=false;

    }

    return sentinella_valida;

}


bool check_dictionary(nodo const* radice, string const& word, size_t posizione = 0) //controllla se la parola candidata è presente nel dizionario e in questo caso ritorna true
{
    if (radice == nullptr) // se il sottoalbero è vuoto la parola non è presente
        return false;
    if (posizione == word.length()) // se sono arrivato alla fine della parola
    {
        return radice->fine; // se è stop la parola è presente, altrimenti no
    }
    return check_dictionary(radice->figli[word[posizione] - 'A'], word, posizione + 1); // chiamata ricorsiva sul figlio relativo alla prossima lettera
}


#endif // CHECK_WORD_H
