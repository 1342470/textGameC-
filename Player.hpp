
#include<string>
using namespace std;
#include "Creature.hpp"


class Player
{
  private:
    int location;
    string name;
    int numRooms;
    int hitPoints;
    float money;
    int strenth;
  public:
    Player(string name, int numRooms);
    string getName();
    void moveLeft();
    void moveRight();
    void bribe(int money);
    void minusMoney(int moneyOut);
    void addMoney(int moneyIn);
    double getMoney();
    void printInfo();
    void attack(Creature *theTarget);
    void decreaseHealth(int strike);
    int getHealth();
    int getLoc();
    // string getAction(Creature *theTarget);
    void bribe(Creature theTarget);
};

Player::Player(string name, int numRooms){
    this->name = name;
    this->numRooms = numRooms;
    hitPoints = 10;
    location = 0;
}

string Player::getName(){
  return this->name;
}

void Player::moveLeft(){
  if(location > 0){
    location--;
  }  
}

void Player::moveRight(){
  if(location < numRooms){
    location++;
  } 
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

int Player::getLoc(){
  return location;
}

void Player::attack(Creature *theTarget){
    int strike = this->strenth + rand() % 10 + 1;
    theTarget->decreaseHealth(strike);
    cout << "You strike " << theTarget->getName() << " the impact leaves them with " << theTarget->getHealth() << " health left " << endl ;
}

void Player::bribe(Creature theTarget){
    int amount;
    cout << "How much will you bribe?" << endl;
    cin >> amount;
    if (amount > money){
      cout << "How dare you try to fool me you dont have the money for that: The Creature gets angry and attacks you" << endl;
      decreaseHealth(2);
    }else if(amount < theTarget.getGreed()){
      cout << "YOU THINK THAT IS ENOUGH COIN TO BUY ME OUT:" << theTarget.getName() << " in rage strikes you" << endl;
      decreaseHealth(2);
    }
    else{
      money = money - amount; 
    }
  }


void Player::decreaseHealth(int stirke) {
    int healthLoss = rand() % 10 + stirke / this->strenth;
    hitPoints = hitPoints - healthLoss;
}

int Player::getHealth() {
    return hitPoints;
}

void Player::printInfo()
{
    cout << "you are " << name << " you have " << money << " gold " << " and have " << strenth << " strenth" << endl;
}
    

