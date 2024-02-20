//HEADER PER L'INIZIALIZZAZIONE DEL GIOCO//
#ifndef INITIALIZATION_H
#define INITIALIZATION_H


#include <iostream> // i-o
#include <iomanip> // setw
#include <windows.h> // sleep


using namespace std;

void inizializzazione()
{

    cout<<endl<<endl;
    cout<<setw(65)<<"~~~~~BANCALE LORENZO 890982~~~~"<<endl<<endl;
    cout<<setw(65)<<"*******************************"<<endl;
    cout<<setw(65)<<"*********** UPWORDS ***********"<<endl;
    cout<<setw(65)<<"*******************************"<<endl;

    //STAMPA DEL TABELLONE VUOTO//

    //PRIMA RIGA//
    cout<<setw(65)<<" 1  2  3  4  5  6  7  8  9  10"<<endl;
    cout<<setw(35);
    cout<<char(201)<<char(205)<<char(205);
    for(unsigned int i=0;i<9;i++)
        cout<<char(203)<<char(205)<<char(205);
    cout<<char(187)<<endl;

    //MEZZO//
    cout<<setw(35);
    for(unsigned int j=0;j<9;++j)
    {
        cout<<setw(35);
        cout<<setw(34)<<j+1;
        for(unsigned int x=0;x<11;x++)
            cout<<char(186)<<setw(3);
        cout<<endl;

        cout<<setw(35);
        cout<<char(204);
        for(unsigned int x=0;x<9;x++)
            cout<<char(205)<<char(205)<<char(206);
        cout<<char(205)<<char(205)<<char(185);
        cout<<endl;
    }

    cout<<setw(34)<<"10";
    for(unsigned int x=0;x<11;x++)
        cout<<char(186)<<setw(3);
    cout<<endl;

    //ULTIMA RIGA//
    cout<<setw(35);
    cout<<char(200)<<char(205)<<char(205);
    for(unsigned int i=0;i<9;i++)
        cout<<char(202)<<char(205)<<char(205);
    cout<<char(188)<<endl;


    //CANCELLA OUTPUT PER INIZIARE IL GIOCO//
    Sleep(5000);
    system("cls");
    cout<<endl<<setw(60)<<"INIZIO TRA : 5"<<endl;
    Sleep(1000);
    system("cls");
    cout<<endl<<setw(60)<<"INIZIO TRA : 4"<<endl;
    Sleep(1000);
    system("cls");
    cout<<endl<<setw(60)<<"INIZIO TRA : 3"<<endl;
    Sleep(1000);
    system("cls");
    cout<<endl<<setw(60)<<"INIZIO TRA : 2"<<endl;
    Sleep(1000);
    system("cls");
    cout<<endl<<setw(60)<<"INIZIO TRA : 1"<<endl;
    Sleep(1000);
    system("cls");
}

void regoledelgioco()
{
    cout<<endl<<endl<<endl;
    cout<<"REGOLE DEL GIOCO :"<<endl;
    cout<<"Ad ogni giocatore vengono date inizialmente 7 lettere, con le quali bisogna comporre parole sul tabellone.\n";
    cout<<"Ogni componimento valido garantisce dei punti ai giocatori.\n";
    cout<<"Le parole possono essere inserite in orizzontale (da sinistra a destra) e in verticale(dall'alto in basso).\n";
    cout<<"E' possibile sovrapporre una lettera ad un'altra lettera gia' inserita nel tabellone, a patto che non si superino 5 liveeli.\n";
    cout<<endl<<"PUNTEGGIO : "<<endl;
    cout<<"Ogni parola inserita fa guadagnare tanti punti quanti sono i livelli totali coinvolti;\n";
    cout<<"Se una parola contiene solo lettere del primo livello, allora la parola ha punteggio doppio;\n";
    cout<<"Se un giocatore utilizza tutte e 7 le lettere a disposizione, allora guadagna 20 punti bonus;\n";
    cout<<"Al termine del gioco ogni giocatore perde 5 punti per ogni lettera che gli e' rimasta in mano.\n";
    cout<<endl<<"SCOPO DEL GIOCO : "<<endl;
    cout<<"L'obiettivo del giocatore e' quello di inserire piu' parole in modo tale da totalizzare piu' punti degli avversari."<<endl<<endl;
    system("pause");
    system("cls");
}


#endif // INITIALIZATION_H
