//HEADER PAR LA STAMPA DEL TABELLONE//
#ifndef STAMPA_H
#define STAMPA_H
#include <iostream>
#include <iomanip>
#include <windows.h>
#include "griglia.h"

using namespace std;

void stampa(cella tabellone[][MAXCOLONNE])
{
    //PRIMA RIGA//
    cout<<setw(65)<<"  1   2   3   4   5   6   7   8   9   10"<<endl;

    cout<<setw(26)<<char(201)<<char(205)<<char(205)<<char(205);
    for(unsigned int i=0;i<9;i++)
        cout<<char(203)<<char(205)<<char(205)<<char(205);
    cout<<char(187)<<endl;

    //MEZZO E FINE DELLA TABELLA//
    for(unsigned int x=0;x<MAXRIGHE;x++)
    {
        cout<<setw(26);
        for(unsigned int j=0;j<MAXCOLONNE;j++) //stampa della prima delle tre righe che compone una cella
        {
            cout<<char(186);
            if(tabellone[x][j].indice==0) //se la cella è vuota
                cout<<"   ";
            else
                cout<<"  "<<tabellone[x][j].indice;
        }
        cout<<char(186)<<endl;

        cout<<setw(25)<<x+1;
        for(unsigned int k=0;k<MAXCOLONNE;k++) //stampa della seconda riga delle tre righe che compone una cella
        {
            cout<<char(186); //stampo il numero della riga
            if(tabellone[x][k].lettera.empty()==true) //se la cella è vuota
                cout<<"   ";
            else
            {
                if(tabellone[x][k].lettera=="Q") //se la lettera è la 'Q' allora sul tabellone viene visualizzato 'Qu'
                    cout<<tabellone[x][k].lettera<<"u"<<" ";
                else
                    cout<<" "<<tabellone[x][k].lettera<<" ";
            }
        }
        cout<<char(186)<<endl;

        if(x<9) //ultima riga della cella che corrisponde alla separazione orizzontale
        {
            cout<<setw(26)<<char(204);
            for(unsigned int q=0;q<MAXCOLONNE-1;q++)
                cout<<char(205)<<char(205)<<char(205)<<char(206);
            cout<<char(205)<<char(205)<<char(205)<<char(185)<<endl;
        }



    }

    cout<<setw(26)<<char(200);
    for(unsigned int q=0;q<MAXCOLONNE-1;q++)
        cout<<char(205)<<char(205)<<char(205)<<char(202);
    cout<<char(205)<<char(205)<<char(205)<<char(188);
    cout<<endl;
}

#endif // STAMPA_H
