/*The header file for main.cpp*/

#include<iostream>


using namespace std;

class Creature {
  string name;
  int hitPoints;
  float money;
  int strenth;
  int location;
  int greed;

  public:
    Creature(string theName);
  void setName(string nameIn);
  void minusMoney(int moneyOut);
  void addMoney(int moneyIn);
  double getMoney();
  void printInfo();
  string getName();
  int attack();
  void decreaseHealth(int strike);
  ~Creature();
  int getHealth();
  int getGreed();
  int getStrenth();
  int setHealth(int theHealth);

};

//constrctor 
Creature::Creature(string theName) {
  name = theName;
  money = rand() % 10 + 1;
  hitPoints = rand() % 10 + 1;
  strenth = rand() % 10 + 1;
  greed = rand() % 10 + 1;
}

Creature::~Creature() {
  cout << name << " has died" << endl;
}

int Creature::setHealth(int theHealth) {
  hitPoints = theHealth;
}

void Creature::setName(string nameIn) {
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

int Creature::attack() {
  int strike = this -> strenth + rand() % 5 + 1;
  return strike;
}

int Creature::getHealth() {
  return hitPoints;
}

int Creature::getGreed() {
  return greed;
}

int Creature::getStrenth() {
  return strenth;
}

void Creature::decreaseHealth(int strike) {
  int healthLoss = rand() % 10 + 1 / this -> strenth;
  hitPoints = hitPoints - healthLoss;
}

void Creature::printInfo() {
  cout << "the Creatures name is " << name << " they have " << getHealth() << " health" << " and have " << getGreed() << " greed " << money << " gold " << " and have " << strenth << " strenth" << endl;
}