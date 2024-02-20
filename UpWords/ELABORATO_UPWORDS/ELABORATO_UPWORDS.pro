TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp

HEADERS += \
    players.h \
    initialization.h \
    sacchetto.h \
    random_letter.h \
    crea_dizionario.h \
    check_word.h \
    griglia.h \
    coordinate_direzione.h \
    suggerimento.h \
    controlli.h \
    inserimento_parola.h \
    stampa.h \
    punteggio.h \
    turno_giocatore.h

DISTFILES += \
    words_italian.txt
