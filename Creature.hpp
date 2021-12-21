/*The header file for main.cpp*/

#include<iostream>
#include <time.h>


using namespace std;

class Creature
{
    string name;
    int hitPoints;
    float money;
    int strenth;
    int location;
    //int random = rand() % 10 + 1;


public:
    Creature(string theName);
    void setName(string nameIn);
    void minusMoney(int moneyOut);
    void addMoney(int moneyIn);
    double getMoney();
    void printInfo();
    string getName();
    void attack(Creature theTarget);
    void decreaseHealth(int strike);
    ~Creature();
    int getHealth();


};

//constrctor 
Creature::Creature(string theName) {
    name = theName;
    money = rand() % 10 + 1;
    hitPoints = rand() % 10 + 1;
    strenth = rand() % 10 + 1;
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


void Creature::attack(Creature theTarget) {
    int strike = this->strenth + rand() % 10 + 1;
    theTarget.decreaseHealth(strike);
    cout << "You strike " << theTarget.getName() << " the impact leaves them with " << theTarget.getHealth() << "health left " << endl;
}

int Creature::getHealth() {
    return hitPoints;
}

void Creature::decreaseHealth(int strike) {
    int healthLoss = rand() % 10 + 1 / this->strenth;
    hitPoints = hitPoints - healthLoss;
}

void Creature::printInfo()
{
    cout << "the Creatures name is " << name << " they have " << money << " gold " << " and have " << strenth << " strenth" << endl;
}
