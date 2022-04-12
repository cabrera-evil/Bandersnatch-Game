#include "resources/bot.hpp"
using namespace std;

int main(void){
    Players Players;

    if (difficulty)
        hard_settings();
    else
        easy_settings();

    Players.mainMenu();
    if (option != 4)
        Players.chooseWeapon();
    else
        return 0;
}