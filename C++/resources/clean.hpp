#include "snitch.hpp"

//DESTRUCTOR
Players::~Players(){
    node *p;
    while(P1){
        p = P1;
        P1 = P1->right;
        delete p;
    }
    while(P2){
        p = P2;
        P2 = P2->right;
        delete p;
    }
    while(BotP){
        p = BotP;
        BotP = BotP->right;
        delete p;
    }
}

//RESET DE VARIABLES
void Players::reset(){
    //Variables de clase
    turn = 1;
    bot = false;

    //Variables globales
    option = 0;
    difficulty = false;

    //Variables de estructura player
    player1.life = 250;
    player2.life = 250;
    BotPlayer.life = 250;
    player1.name = "";
    player2.name = "";
    BotPlayer.name = "";

    //Nodo que sera eliminado
    node *p;

    //Nodos de jugador
    while(P1){
        p = P1->right;
        delete P1;
        P1 = p;
    }
    while(P2){
        p = P2->right;
        delete P2;
        P2 = p;
    }
    while(BotP){
        p = BotP->right;
        delete BotP;
        BotP = p;
    }
}