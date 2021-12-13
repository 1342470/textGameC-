/*The header file for main.cpp*/

#include<iostream>
#include <time.h>
#include "Player.hpp"
#include "Location.hpp"

using namespace std;

class Creature
{
    string name;
    int hitPoints;
    float money;
    int pos;
    int strenth;
    int boundary;
    //int random = rand() % 10 + 1;


public:
    Creature(string theName, int numOfRooms);
    void setName(string nameIn);
    void minusMoney(int moneyOut);
    void addMoney(int moneyIn);
    double getMoney();
    void printInfo();
    string getName();
    void attack(Player theTarget);
    void decreaseHelath();
    ~Creature();

};

//constrctor 
Creature::Creature(string theName, int numOfRooms) {
    name = theName;
    money = rand() % 10 + 1;
    hitPoints = rand() % 10 + 1;
    strenth = rand() % 10 + 1;
    boundary = numOfRooms;
    pos = 0;
}


Creature::~Creature() {
    cout << name << " has died" << endl;
}


void Creature::setName(string nameIn)
{
    name = nameIn;
}

string Creature::getName() {
    return name;
}


double Creature::getMoney() {
    return money;
}

void Creature::addMoney(int moneyIn) {
    money = money + moneyIn;
}

void Creature::minusMoney(int moneyOut) {
    money = money - moneyOut;
}


void Creature::attack(Player theTarget) {
    int strike = this->strenth + rand() % 10 + 1;
    theTarget.decreasehealth(strike);
    System.out.println("You strike " + theEn.getName() + " the impact leaves them with " + theEn.getHealth() + "health left ");
}

void Creature::decreaseHelath() {
    int healthLoss = rand() % 10 + 1 / this->strenth;
    hitPoints = hitPoints - healthLoss;
}

void Creature::printInfo()
{
    cout << "the Creatures name is " << name << " they have " << money << " gold " << " and have " << strenth << " strenth" << endl;
}


