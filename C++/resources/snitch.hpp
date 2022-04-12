#include <iostream>
#include "menu.hpp"
using namespace std;

struct data{
    string name = "";
    float quantity = 0;
    float percentage = 0;
    float failure_probability = 0;
    float weapon_and_noFailing = 0;
}ba, sd, cbw, ax, dggr, potion, bm, fb;

void reseting (){
    ba.quantity = 0;
    ba.percentage = 0;
    ba.failure_probability = 0;
    ba.weapon_and_noFailing = 0;

    sd.quantity = 0;
    sd.percentage = 0;
    sd.failure_probability = 0;
    sd.weapon_and_noFailing = 0;

    cbw.quantity = 0;
    cbw.percentage = 0;
    cbw.failure_probability = 0;
    cbw.weapon_and_noFailing = 0;

    ax.quantity = 0;
    ax.percentage = 0;
    ax.failure_probability = 0;
    ax.weapon_and_noFailing = 0;

    dggr.quantity = 0;
    dggr.percentage = 0;
    dggr.failure_probability = 0;
    dggr.weapon_and_noFailing = 0;

    potion.quantity = 0;
    potion.percentage = 0;
    potion.failure_probability = 0;
    potion.weapon_and_noFailing = 0;

    bm.quantity = 0;
    bm.percentage = 0;
    bm.failure_probability = 0;
    bm.weapon_and_noFailing = 0;

    fb.quantity = 0;
    fb.percentage = 0;
    fb.failure_probability = 0;
    fb.weapon_and_noFailing = 0;
}

void calculating (node *pointer){
    int total = 0; 
    node *jumper = pointer; 

    ba.name = "Arco y flecha";
    sd.name = "Espada"; 
    cbw.name = "Ballesta";
    ax.name = "Hacha";
    dggr.name = "Daga";
    potion.name = "Pocion";
    bm.name = "Baston Magico"; 
    fb.name = "Bola de Fuego";

    while (jumper){
        total++;

        if (jumper->equipment.name == "Arco y flecha"){
            ba.quantity++;
            ba.failure_probability = jumper->equipment.failure_prob;
        }
        if (jumper->equipment.name == "Espada"){
            sd.quantity++;
            sd.failure_probability = jumper->equipment.failure_prob;
        }
        if (jumper->equipment.name == "Ballesta"){
            cbw.quantity++;
            cbw.failure_probability = jumper->equipment.failure_prob; 
        }
        if (jumper->equipment.name == "Hacha"){
            ax.quantity++;
            ax.failure_probability = jumper->equipment.failure_prob; 
        }
        if (jumper->equipment.name == "Daga"){
            dggr.quantity++;  
            dggr.failure_probability = jumper->equipment.failure_prob;
        }
        if (jumper->equipment.name == "Pocion"){
            potion.quantity++;
            potion.failure_probability = jumper->equipment.failure_prob;
        }
        if (jumper->equipment.name == "Baston Magico"){
            bm.quantity++;
            bm.failure_probability = jumper->equipment.failure_prob;
        }
        if (jumper->equipment.name == "Bola de Fuego"){
            fb.quantity++;
            fb.failure_probability = jumper->equipment.failure_prob;
        }
        jumper = jumper->right;
    } 

    if (total > 0){
        //4/4 = 1(1-0.5) = 0.5
        ba.percentage = ba.quantity / total; 
        ba.weapon_and_noFailing = (ba.percentage * (1-ba.failure_probability));

        sd.percentage = sd.quantity / total; 
        sd.weapon_and_noFailing = sd.percentage * (1-sd.failure_probability);

        cbw.percentage = cbw.quantity / total;
        cbw.weapon_and_noFailing = cbw.percentage * (1-cbw.failure_probability);

        ax.percentage = ax.quantity / total; 
        ax.weapon_and_noFailing = ax.percentage * (1-ax.failure_probability);

        dggr.percentage = dggr.quantity / total;
        dggr.weapon_and_noFailing = dggr.percentage * (1-dggr.failure_probability);

        potion.percentage = potion.quantity / total;
        potion.weapon_and_noFailing = potion.percentage * (1-potion.failure_probability);

        bm.percentage = bm.quantity / total;
        bm.weapon_and_noFailing = bm.percentage * (1-bm.failure_probability);

        fb.percentage = fb.quantity / total;
        fb.weapon_and_noFailing = fb.percentage * (1-fb.failure_probability); 
    }
}

void printing (){
    cout << "\n|-------------------------------------------------------------------------|";
    cout << "\n|    Probabilidades de que el contrincante utilice un arma y no falle     |";
    cout << "\n|-------------------------------------------------------------------------|";
    if (ba.percentage > 0){
        cout << "\n|" << ba.name << ": " << ba.weapon_and_noFailing;
    }
    if (sd.percentage > 0){
        cout << "\n|" << sd.name << ": " << sd.weapon_and_noFailing;
    }
    if (cbw.percentage > 0){
        cout << "\n|" << cbw.name << ": " << cbw.weapon_and_noFailing; 
    }
    if (ax.percentage > 0){
        cout << "\n|" << ax.name << ": " << ax.weapon_and_noFailing;
    }
    if (dggr.percentage > 0){
        cout << "\n|" << dggr.name << ": " << dggr.weapon_and_noFailing;
    }
    if (potion.percentage > 0){
        cout << "\n|" << potion.name << ": " << potion.weapon_and_noFailing;
    }
    if (bm.percentage > 0){
        cout << "\n|" << bm.name << ": " << bm.weapon_and_noFailing;
    }
    if (fb.percentage > 0){
        cout << "\n|" << fb.name << ": " << fb.weapon_and_noFailing;
    }
}