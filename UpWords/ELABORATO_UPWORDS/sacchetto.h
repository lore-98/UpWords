//HEADER CHE DEFINISCE IL SACCHETTO DOVE SONO CONTENUTE TUTTE LE LETTERE//
#ifndef SACCHETTO_H
#define SACCHETTO_H

#include <iostream>
#include <vector>

/*
ELENCO DELLE LETTERE PRESENTI NEL GIOCO

"J Qu V X Z" x1
"K W Y" x2
"B F G H P" x3
"C" x4
"D L M N R T U" x5
"S" x6
"A I O" x7
"E" x8
*/

//VETTORE CHE CONTIENE TUTTE LE LETTERE, RAPPRESENTA IL SACCHETTO DA CUI PESCARE//
std::vector<char> letters=
{
    'J','Q','V','X','Z',
    'K','W','Y','K','W','Y',
    'B','F','G','H','P','B','F','G','H','P','B','F','G','H','P',
    'C','C','C','C',
    'D','L','M','N','R','T','U','D','L','M','N','R','T','U','D','L','M','N','R','T','U','D','L','M','N','R','T','U','D','L','M','N','R','T','U',
    'S','S','S','S','S','S',
    'A','I','O','A','I','O','A','I','O','A','I','O','A','I','O','A','I','O','A','I','O',
    'E','E','E','E','E','E','E','E'
};


#endif // SACCHETTO_H
