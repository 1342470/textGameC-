/*The header file for main.cpp*/
#include<iostream>
#include <time.h>
#include "Creature.hpp"

using namespace std;
 

class Monster : public Creature {

Monster::Monster(string theName) {
    name = theName;
    money = rand() % 10 + 1;
    hitPoints = rand() % 10 + 1;
    rand() % 100 + 1;
    strenth = rand() % 10 + 1;


}


Creature::~Creature() {
  cout << name << " has died" << endl;
}

}