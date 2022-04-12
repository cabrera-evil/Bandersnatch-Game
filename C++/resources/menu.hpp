#include <iostream>
#include <ctime>
using namespace std;

int option = 0;
bool difficulty = false;
bool salir = false;

//ARMAS Y EQUIPAMIENTO
struct equipment {
    string name = "";
    float failure_prob = 0; 
    int usage_limit = 0; 
    float damage = 0;
    float healing = 0;
}bow_and_arrow, sword, crossbow, axe, dagger, fist, healing_potion, magic_staff, fire_ball;

struct node {
    struct equipment equipment;
    int position = 0;
    node *right;
    node *left;
};

struct players {
    string name = "";
    float life = 250;
}player1, player2, BotPlayer;

void easy_settings (void){
    bow_and_arrow.usage_limit = 4;  
    bow_and_arrow.failure_prob = 0.5;//1/2
    bow_and_arrow.damage = 27.5;

    sword.usage_limit = 3;  
    sword.failure_prob = 0.3;//3/10
    sword.damage = 25.5;

    crossbow.usage_limit = 4;  
    crossbow.failure_prob = 0.2;//1/5
    crossbow.damage = 20.2;

    axe.usage_limit = 5;  
    axe.failure_prob = 0.1875; //3/16
    axe.damage = 18.7;
    
    dagger.usage_limit = 4;
    dagger.failure_prob = 0.15;//3/20
    dagger.damage = 15;

    magic_staff.usage_limit = 2;
    magic_staff.failure_prob = 0.75;//3/4
    magic_staff.damage = 100;

    fire_ball.usage_limit = 2;
    fire_ball.failure_prob = 0.5;//1/2
    fire_ball.damage = 50;

    fist.name = "Punios";
    fist.usage_limit = 1000;
    fist.failure_prob = 0;//0
    fist.damage = 1;

    healing_potion.usage_limit = 2;
    healing_potion.healing = 20;
}

void hard_settings (void){
    bow_and_arrow.usage_limit = 3;  
    bow_and_arrow.failure_prob = 0.66; // 4/6
    bow_and_arrow.damage = 27.5;

    sword.usage_limit = 3;  
    sword.failure_prob = 0.429; // 3/7
    sword.damage = 25.5;

    crossbow.usage_limit = 4;  
    crossbow.failure_prob = 0.33; // 1/3
    crossbow.damage = 20.2;

    axe.usage_limit = 4;  
    axe.failure_prob = 0.25; // 1/4
    axe.damage = 18.7;
    
    dagger.usage_limit = 5;
    dagger.failure_prob = 0.16; // 1/6
    dagger.damage = 15;

    magic_staff.usage_limit = 2;
    magic_staff.failure_prob = 0.9;//9/10
    magic_staff.damage = 100;

    fire_ball.usage_limit = 2;
    fire_ball.failure_prob = 0.75;//3/4
    fire_ball.damage = 50;

    fist.name = "Punios";
    fist.usage_limit = 1000;
    fist.failure_prob = 0;
    fist.damage = 1;

    healing_potion.usage_limit = 2;
    healing_potion.healing = 20;
}

bool easy_failureProbabilities (equipment weapon){
    int random = 0;
    
    if (weapon.name == "Arco y flecha"){
        random = rand()%(2-1+1)+1;
        if (random == 1)
            return false;
        else 
            return true;
    }
    else if (weapon.name == "Espada"){
        random = rand()%(10-1+1)+1;
        if (random == 1 || random == 2 || random == 3)
            return false;
        else
            return true;
    }
    else if (weapon.name == "Ballesta"){
        random = rand()%(5-1+1)+1;
        if (random == 1)
            return false;
        else
            return true;
    }
    else if (weapon.name == "Hacha"){
        random = rand()%(16-1+1)+1;
        if (random == 1 || random == 2 || random == 3)
            return false;
        else
            return true;
    }
    else if (weapon.name == "Daga"){
        random = rand()%(20-1+1)+1;
        if (random == 1 || random == 2 || random == 3)
            return false;
        else
            return true;
    }
    else if(weapon.name == "Punios")
            return true;
    else if (weapon.name == "Baston Magico"){
        random = rand()%(4-1+1)+1;
        if (random == 1 || random == 2 || random == 3)
            return false;
        else
            return true;
    }
    else if (weapon.name == "Bola de Fuego"){
        random = rand()%(2-1+1)+1;
        if (random == 1)
            return false;
        else
            return true;
    }
    return true; 
    
}

bool hard_failureProbabilities (equipment weapon){
    int random = 0;
    
    if (weapon.name == "Arco y flecha"){
        random = rand()%(6-1+1)+1;
        if (random == 1 || random == 2 || random == 3 || random == 4)
            return false;
        else 
            return true;
    }
    else if (weapon.name == "Espada"){
        random = rand()%(7-1+1)+1;
        if (random == 1 || random == 2 || random == 3)
            return false;
        else
            return true;
    }
    else if (weapon.name == "Ballesta"){
        random = rand()%(3-1+1)+1;
        if (random == 1)
            return false;
        else
            return true;
    }
    else if (weapon.name == "Hacha"){
        random = rand()%(4-1+1)+1;
        if (random == 1)
            return false;
        else
            return true;
    }
    else if (weapon.name == "Daga"){
        random = rand()%(6-1+1)+1;
        if (random == 1)
            return false;
        else
            return true;
    }
    if (weapon.name == "Baston Magico"){
        random = rand()%(10-1+1)+1;
        if (random == 1 || random == 2 || random == 3 || random == 4 || random == 5 || random == 6 || random == 7 || random == 8 || random == 9)
            return false;
        else
            return true;
    }
    else if (weapon.name == "Bola de Fuego"){
        random = rand()%(4-1+1)+1;
        if (random == 1 || random == 2 || random == 3)
            return false;
        else
            return true;
    }
    return true;
}

class Players {
    private: 
        node *P1;
        node *P2;
        node *BotP;
        int turn = 1;
        bool bot = 0;
    public:
        Players ();
        ~Players ();
        void mainMenu ();
        void difficulty_selection ();
        void selection (int playerNumber); 
        void insert (equipment, int playerNumber, int position);
        node *innings ();
        void del (node *);  
        void print (node *);
        void chooseWeapon ();
        void chooseWeapon (int reference, node *);
        int chooseeWeaponBot();
        void attack(node *);
        void defense(string, node *);
        void heal(node *);
        void reset();
        void life();
};

//CONSTRUCTOR
Players::Players(void){
    P1 = NULL;
    P2 = NULL;
    BotP = NULL;
}

//MENU PRINCIPAL
void Players::mainMenu(){
    reset();
    int playerNumber = 1;
    system("clear");
    cout << "\n|-------------------------------------------|";
    cout << "\n|         BIENVENIDO A BANDERSNATCH         |";
    cout << "\n|---------------------|---------------------|";
    cout << "\n| 1. Jugar contra     | 2. Multijugador     |";
    cout << "\n|    un bot           |    local            |";
    cout << "\n|---------------------|---------------------|";
    cout << "\n| 3. Dificultad       | 4. Salir            |";
    cout << "\n|-------------------------------------------|";
    cout << "\n|Tu opcion: "; cin >> option; cin.ignore();
    switch (option){
        case 1: 
            bot = 1;
            BotPlayer.name = "Bot";
            cout << "|-------------------------------------------|";
            cout << "\n|Nombre de Jugador " << playerNumber << ": "; getline(cin, player1.name);
            selection(playerNumber);
            break;
        case 2: 
            while (playerNumber <= 2){
                bot = 0;
                cout << "\n|-------------------------------------------|";
                cout << "\n|Nombre de Jugador " << playerNumber << ": "; 
                if(playerNumber == 1)
                    getline(cin, player1.name);
                else
                    getline(cin, player2.name);
                selection(playerNumber);
                playerNumber++;
                
            }
            break;
        case 3:
            difficulty_selection();
            mainMenu();
            break;
        case 4:
            cout << "|-------------------------------------------|";
            cout << "\n|     GRACIAS POR JUGAR A BANDERSNATCH      |";
            cout << "\n|-------------------------------------------|" << endl;
            salir = true;
            break;
        default:
            cout << "\n|     LA OPCION SELECCIONADA NO EXISTE      |";
            mainMenu();
            break;
    }
}

//MENU DE SELECCION DE DIFICULTAD
void Players::difficulty_selection(){
    int op = 0; 

    do{
        system("clear");
        cout << "|-------------------------------------------|";
        cout << "\n|        SELECCIONA LA DIFICULTAD          |";
        cout << "\n|---------------------|---------------------|";
        cout << "\n| 1. Facil            | 2. Dificil          |";
        cout << "\n|---------------------|---------------------|";
        cout << "\n|Tu opcion: "; cin >> op; cin.ignore();
        switch (op){
            case 1: 
                difficulty = 0; 
                break; 
            case 2: 
                difficulty = 1;
                break; 
            default: 
                cout << "\nOpcion no valida"; 
                break;
        }
    }while(op != 1 && op != 2);
}
//SELECCION DE EQUIPAMIENTO
void Players::selection (int playerNumber){
    int option = 0, counter = 1; 
    system("clear");
    while(counter <= 4){
        cout << "|-------------------------------------------|";
		cout << "\n|         ° ELIJE TU EQUIPAMIENTO °         |";
        cout << "\n|                JUGADOR "<<  playerNumber << "                  |";
		cout << "\n|---------------------|---------------------|";
		cout << "\n| 1. Arco y Flecha    | 5. Daga             |";
		cout << "\n| 2. Espada           | 6. Baston Magico    |";
		cout << "\n| 3. Ballesta         | 7. Bola de Fuego    |";
        cout << "\n| 4. Hacha            | 8. Pocion           |";
		cout << "\n|---------------------|---------------------|";
		cout << "\n|Tu opcion: ";cin >> option; cin.ignore();
        switch(option){
            case 1:
                bow_and_arrow.name = "Arco y flecha";
                insert(bow_and_arrow, playerNumber, counter);
                counter++;
                break;
            case 2:
                sword.name = "Espada";
                insert(sword, playerNumber, counter);
                counter++;
                break;
            case 3:
                crossbow.name = "Ballesta";
                insert(crossbow, playerNumber, counter);
                counter++;
                break; 
            case 4:
                axe.name = "Hacha";
                insert(axe, playerNumber, counter); 
                counter++;
                break;
            case 5:
                dagger.name = "Daga";
                insert(dagger, playerNumber, counter);
                counter++;
                break;
            case 6:
                magic_staff.name = "Baston Magico";
                insert(magic_staff, playerNumber, counter);
                counter++;
                break;
            case 7:
                fire_ball.name = "Bola de Fuego";
                insert(fire_ball, playerNumber, counter);
                counter++;
                break;
            case 8:
                healing_potion.name = "Pocion";
                insert(healing_potion, playerNumber, counter);
                counter++;
                break;
            default:
                cout << "\nEL ITEM SELECCIONADO NO EXISTE" << endl;
                break;
        }
    }system("clear");
}

//FUNCION DE INSERTAR
void Players::insert(equipment data, int playerNumber, int i){
    node *newNode = new node;
    newNode->equipment = data; 
    newNode->position = i;
    
    if (playerNumber == 1){
        if (!P1){
            newNode->left = newNode->right = NULL;
            P1 = newNode;
        }
        else {
            newNode->right = P1; 
            newNode->left = NULL;
            P1->left = newNode;
            P1 = newNode;
        }   
    }
    else if (!bot && playerNumber == 2){
            if (!P2){
            newNode->left = newNode->right = NULL;
            P2 = newNode;
        }
        else {
            newNode->right = P2; 
            newNode->left = NULL;
            P2->left = newNode;
            P2 = newNode;
        } 
    }
    if (bot){
            node *newNode = new node;
            newNode->equipment = data; 
            newNode->position = i;
        if (!BotP){
            newNode->left = newNode->right = NULL;
            BotP = newNode;
        }
        else {
            newNode->right = BotP; 
            newNode->left = NULL;
            BotP->left = newNode;
            BotP = newNode;
        } 
    }
}

//INICIALIZAR EL TURNO DEL JUGADOR
node *Players::innings(void){
    if (turn % 2 != 0){
        return P1; //turno del jugador 1
    }
    else if (!bot && turn % 2 == 0){
        return P2; //turno del jugador 2 
    }
    else if (bot && turn % 2 == 0){
        return BotP; //turno del bot
    }
    return NULL;
}

//IMPRIMIR LAS ARMAS DISPONIBLES(EN COMBATE)
void Players::print (node *pointer){
    if (pointer){
        while (pointer->right)
            pointer = pointer->right;
        while (pointer->left){
            cout << "\n|" << pointer->position << ". " << pointer->equipment.name;
            pointer = pointer->left;
        }
        cout << "\n|" << pointer->position << ". " << pointer->equipment.name;
    }
    else return;
}


void Players::del(node *jumper){
    node *aux;
    int i = 1;

    if (turn % 2 != 0)
        aux = P1;
    else if (!bot && turn % 2 == 0)
        aux = P2;
    else if (bot && turn % 2 == 0)
        aux = BotP;

    if (jumper->left && !jumper->right){ //General
        jumper->left->right = NULL;
        delete (jumper);
        jumper = NULL;
        while (aux){  // ajustando las posiciones de cada arma
            aux->position--;
            aux = aux->right;
        }
        return;
    }
    else if (turn % 2 != 0 && !jumper->left && jumper->right){ //P1 
        P1->right->left = NULL;
        P1 = P1->right;
        delete (jumper);
       // jumper = P1 = NULL;
        return;
    }
    else if ( turn %2 != 0 && !jumper->right && !jumper->left){ // P1
        delete (P1);
        jumper = P1 = NULL;
        return;
    }
    else if (!bot && turn % 2 == 0 && !jumper->left && jumper->right){//P2
        P2->right->left = NULL;
        P2 = P2->right;
        delete (jumper);
       // jumper = P2 = NULL;
        return;
    }
    else if ( turn %2 == 0 && !jumper->right && !jumper->left){ // P2
        delete (P2);
        jumper = P2 = NULL;
        return;
    }
    else if (bot && turn % 2 == 0 && !jumper->left && jumper->right){//Bot
        BotP->right->left = NULL;
        BotP = BotP->right;
        delete (jumper);
        //jumper = BotP = NULL;
        return;
    }
    else if ( turn %2 == 0 && !jumper->right && !jumper->left){ // Bot
        delete (BotP);
        jumper = BotP = NULL;
        return;
    }
    else { //General
        jumper->left->right = jumper->right;
        jumper->right->left = jumper->left;
        delete(jumper);
        jumper = aux;
        while(aux->right) // saltando hasta el último nodo de la lista (de posición 1)
            aux = aux->right;
        while (aux){  // ajustando las posiciones de cada arma
            aux->position = i;
            i++;
            aux = aux->left;//Arreglar
        }
        return;
    }
}