#include "combat.hpp"
#include <ctime>
using namespace std;

int Players::chooseeWeaponBot (){ // Nivel facil
    int selection = 1;
    node *jumper = BotP;

    while (jumper->right)
        jumper = jumper->right;     
    selection = rand()% (BotP->position - jumper->position + 1)+ jumper->position;
    return selection;
}