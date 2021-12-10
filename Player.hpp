/*The header file for main.cpp*/

#include<iostream>
#include <time.h>

using namespace std;

class Player
{
    string name;
    int hitPoints;
    float money;
    int pos;
    int strenth;
    //int random = rand() % 10 + 1;


public:
    Player(string theName);
    void setName(string nameIn);      
    void bribe(int money);
    void minusMoney(int moneyOut);
    void addMoney(int moneyIn);
    double getMoney();
    void fight();
    void move();
    void printInfo();
    string getName();
    ~Player();
    
};

//constrctor 
Player::Player(string theName){
  name = theName;
  money = rand() % 10 + 1;
  hitPoints = rand() % 10 + 1;
  strenth = rand() % 10 + 1;
  pos = 0;
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

void Player::move(){
  
}

void Player::printInfo()
{
    cout << "your Players name is " << name << " you have " << money << " gold " << " and have " << strenth << " strenth" << endl;
}
    

