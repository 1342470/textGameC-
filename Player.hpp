/*The header file for main.cpp*/

#include<iostream>
#include <time.h>

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
    void fight();
    void moveLeft();
    void moveRight();
    void printInfo();
    string getName();
    void showPos(Location world[]);
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

void Player::printInfo()
{
    cout << "your Players name is " << name << " you have " << money << " gold " << " and have " << strenth << " strenth" << endl;
}
    

