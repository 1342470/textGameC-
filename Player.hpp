/*The header file for main.cpp*/

#include<iostream>
#include <time.h>
#include "Creature.hpp"
#include "Location.hpp"

using namespace std;

class Player
{
    string name;
    int hitPoints;
    float money;
    int pos;
    int strenth;
    int boundary;
    //int random = rand() % 10 + 1;


public:
    Player(string theName, int numOfRooms);
    void setName(string nameIn);      
    void bribe(int money);
    void minusMoney(int moneyOut);
    void addMoney(int moneyIn);
    double getMoney();
    void moveLeft();
    void moveRight();
    void printInfo();
    string getName();
    void showPos(Location world[]);
    void attack(Creature theTarget);
    void decreaseHelath();
    ~Player();
    
};

//constrctor 
Player::Player(string theName, int numOfRooms){
  name = theName;
  money = rand() % 10 + 1;
  hitPoints = rand() % 10 + 1;
  strenth = rand() % 10 + 1;
  boundary = numOfRooms;
  pos = 0;
}

void Player::showPos(Location world[]){
    cout << world[pos].showDiscription() << endl;
    //cout << pos;
}

Player::~Player(){
  cout << name << " has died" << endl;
}


void Player::setName(string nameIn)
{
    name = nameIn;
}

string Player::getName(){
  return name ;
}
void Player::bribe(int money)
{
  cout << name << " is bribeing " << money << " gold " << endl ;
}

double Player::getMoney(){
  return money;
}
 
void Player::addMoney(int moneyIn){
  money = money + moneyIn;
}

void Player::minusMoney(int moneyOut){
  money = money -moneyOut;
}

void Player::moveLeft(){
  if(pos > 0){
     pos--;
  }
}


void Player::moveRight(){
  if (pos < boundary){
    pos++;
  }
}

void Player::attack(Creature theTarget){
    int strike = this->strenth + rand() % 10 + 1;
    theTarget.decreasehealth(strike);
    System.out.println("You strike " + theEn.getName() + " the impact leaves them with " + theEn.getHealth() + "health left ");
}

void Player::decreaseHelath() {
    int healthLoss = rand() % 10 + 1 / this->strenth;
    hitPoints = hitPoints - healthLoss;
}

void Player::printInfo()
{
    cout << "your Players name is " << name << " you have " << money << " gold " << " and have " << strenth << " strenth" << endl;
}
    

