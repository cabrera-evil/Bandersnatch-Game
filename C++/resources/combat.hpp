#include "clean.hpp"
#include<thread>
#include <chrono>
using namespace std; 

void Players::life(void){
    if(!salir)
    {
        //life general
        if(player1.life >= 0 && (player2.life >= 0 || BotPlayer.life >= 0)){
            system("clear");
            cout << "\n|-------------------------------------------------------------------------|";
            cout << "\n|La vida del jugador 1 es: " << player1.life;
            if(!bot)
                cout << "\n|La vida del jugador 2 es: " << player2.life;
            else
                cout << "\n|La vida del Bot es: " << BotPlayer.life;
        }
        //Game over - Player 1 won
        if(player2.life <= 0 || BotPlayer.life <= 0){
            cout << "\n|-------------------------------------------------------------------------|";
            cout << "\n|GAME OVER";
            cout << "\n|El ganador es: " << player1.name;
            this_thread::sleep_for(chrono::milliseconds(3000));
            mainMenu();

        }
        //Game over 2 players - Player 2 won
        else if(!bot && player1.life <= 0){
            cout << "\n|-------------------------------------------------------------------------|";
            cout << "\n|GAME OVER";
            cout << "\n|El ganador es: " << player2.name;
            cout << "\n|-------------------------------------------|";
            this_thread::sleep_for(chrono::milliseconds(3000));
            mainMenu();
        }
        //Game over 1 player - won bot
        else if (bot && player1.life <= 0){
            cout << "\n|-------------------------------------------------------------------------|";
            cout << "\n|GAME OVER";
            cout << "\n|El ganador es: " << BotPlayer.name;
            cout << "\n|-------------------------------------------------------------------------|";
            this_thread::sleep_for(chrono::milliseconds(3000));
            mainMenu();
        }  
    }
}

void Players::chooseWeapon(void){
    if(!salir)
    {
        int position = 0;
        node *jumper;

        life ();
        if (!bot){
            while (player1.life > 0 && player2.life > 0){
                reseting ();
                jumper = innings(); //Inicializando jumper en el puntero inicial de la lista a la que le corresponde
                if (jumper){
                    life();
                    if (jumper == P1){
                        calculating (P2); // obtenemos los calculos y recomendaciones del soplón
                        printing(); 
                        cout << "\n|-------------------------------------------------------------------------|";
                        cout << "\n|Armas disponibles. Jugador 1: ";
                        print (jumper);
                    }
                    else if (jumper == P2){
                        calculating (P1); // obtenemos los calculos y recomendaciones del soplón
                        printing();
                        cout << "\n|-------------------------------------------------------------------------|";
                        cout << "\n|Armas disponibles. Jugador 2: ";
                        print (jumper);
                    }
                    do{
                        cout << "\n|-------------------------------------------------------------------------|";
                        cout << "\n|Selecciona tu arma para el ataque: "; cin >> position;
                    }while (position <= 0);
                    
                    chooseWeapon(position, jumper); //búsqueda del arma en la lista y su disponibilidad
                }
                else{ //Insertar el nodo de los puños al jugador
                    cout << "\n|-------------------------------------------------------------------------|";
                    cout << "\n|Te has quedado sin armas. Hora de usar los punios! ";
                    if (turn % 2 != 0)
                        insert(fist, 1, 1);
                    else 
                        insert (fist, 2, 1);
                    chooseWeapon();
                }
                life();
            }
        }
        else{
            while (player1.life > 0 && BotPlayer.life > 0){
                life();
                reseting ();
                if(!salir)
                {
                    jumper = innings();  //Inicializando jumper en el puntero inicial de la lista a la que le corresponde
                    if (jumper){
                        if (jumper == P1) {
                            cout << "\n|-------------------------------------------------------------------------|";
                            cout << "\n|Armas disponibles. Jugador 1: ";
                            cout << "\n|-------------------------------------------------------------------------|";
                            print (jumper);
                            calculating (BotP); // obtenemos los calculos y recomendaciones del soplón
                            printing(); 
                            
                            do{
                                cout << "\n|-------------------------------------------------------------------------|";
                                cout << "\n|Selecciona tu arma para el ataque: "; cin >> position;
                            } while (position <= 0);
                        }
                        else 
                            position = chooseeWeaponBot(); // Esogiendo un arma en una posicion random para el bot
                        chooseWeapon(position, jumper);
                    }
                    else { //Insertar el nodo de los puños al jugador
                        cout << "\n|-------------------------------------------------------------------------|";
                        cout << "\n|Te has quedado sin armas. Hora de usar los punios! ";
                        if (turn % 2 != 0)
                            insert (fist, 1, 1);
                        else
                            insert (fist, 3, 1);
                        chooseWeapon();
                    }
                    life();
                }
                else break;
            }
        }
    }
}

void Players::chooseWeapon (int position, node *jumper){
    if(!salir)
    {
        if (jumper && jumper->position != position){
            jumper = jumper->right;
            chooseWeapon (position, jumper);
        }
        else if (jumper && jumper->position == position){
            if(jumper->equipment.name == "Pocion de curacion"){
                heal(jumper);
                turn++;
                return;
            }
            else{
                attack(jumper);
                turn++;
                return;
            }
        }
        else{
            cout << "|-------------------------------------------------------------------------|";
            cout << "\n|No cuentas con un arma de ese tipo :("; 
            return chooseWeapon();
        }
    }
}

void Players::attack(node *jumper){
    if (turn % 2 == 0){  //turno del jugador 2 o del bot para atacar
        if (difficulty){
            if (hard_failureProbabilities(jumper->equipment)){ //Definir si el arma funcionara o no
                player1.life -= jumper->equipment.damage;  //Disminuyendo la vida del jugador
            }
            else{
                cout << "\n|-------------------------------------------------------------------------|";
                cout << "\n|El arma ha fallado :( " << endl;
            }
        }
        else{
           if (easy_failureProbabilities(jumper->equipment)){ //Definir si el arma funcionara o no
                player1.life -= jumper->equipment.damage; //Disminuyendo la vida del jugador
            }
            else {
                cout << "\n|-------------------------------------------------------------------------|";
                cout << "\n|El arma ha fallado :( " << endl; 
            }
        }
        jumper->equipment.usage_limit--;  //La vida del arma disminuye en uno
        if (jumper->equipment.usage_limit <= 0) // eliminar el nodo del arma si esta ya no tiene vida
            del(jumper);
        return;
    }  
    else if (!bot && turn % 2 != 0){ //turno del jugador 1 para atacar al jugador 2
        if (difficulty){
            if (hard_failureProbabilities(jumper->equipment)) //Definir si el arma funcionara o no
                player2.life -= jumper->equipment.damage;  //Disminuyendo la vida del jugador
            else{
                cout << "\n|El arma ha fallado :( " << endl;
                cout << "\n|-------------------------------------------------------------------------|";
            }
        }
        else{
            if (easy_failureProbabilities(jumper->equipment)) //Definir si el arma funcionara o no
                player2.life -= jumper->equipment.damage;  //Disminuyendo la vida del jugador
            else {
                cout << "\n|El arma ha fallado :( " << endl;
                cout << "\n|-------------------------------------------------------------------------|";
            }
        }
        jumper->equipment.usage_limit--;  //La vida del arma disminuye en uno
        if (jumper->equipment.usage_limit <= 0)
            del(jumper);
        return;
    }
    else if (bot && turn % 2 != 0){ // turno del jugador 1 para atacar al bot
        if (difficulty){
            if (hard_failureProbabilities(jumper->equipment)) //Definir si el arma funcionara o no
                BotPlayer.life -= jumper->equipment.damage;  //Disminuyendo la vida del jugador
            else{
                cout << "\n|-------------------------------------------------------------------------|";
                cout << "\n|El arma ha fallado :( " << endl;
            }
        }
        else{
            if (easy_failureProbabilities(jumper->equipment)) //Definir si el arma funcionara o no
                BotPlayer.life -= jumper->equipment.damage;  //Disminuyendo la vida del jugador
            else{ 
                cout << "\n|-------------------------------------------------------------------------|";
                cout << "\n|El arma ha fallado :( " << endl;
            }
        }
        jumper->equipment.usage_limit--;  //La vida del arma disminuye en uno
        if (jumper->equipment.usage_limit <= 0) //eliminar el nodo del arma que ya no tiene vida
            del(jumper);
        return;
    }
}

void Players::heal(node *jumper){
    if(turn % 2 != 0)
        player1.life += 20;
    else if(!bot && turn % 2 == 0)
        player2.life += 20;
    else
        BotPlayer.life += 20;
    jumper->equipment.usage_limit--;
}