
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
    int score;
    int level;
    int exp;
    int healthItem;
    int strenthItem;
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
    int getScore();
    int getExp();
    int getStrenth();
    void setExp(int theExp);
    void levelUp();
    void setScore(int theScore);
    void setStrenth(int theScore);
    int setExp();
    void setHealth(int theHealth);
    int getLevel();
    void attack(Creature *theTarget);
    int decreaseHealth(int strike);
    int getHealth();
    int getLoc();
    int getHealthItem();
    int getStrenthItem();
    int useHealthItem();
    int useStrenthItem();
    int addHealthItem();
    int addStrenthItem();
    // string getAction(Creature *theTarget);
    void bribe(Creature theTarget);
};

Player::Player(string name, int numRooms){
    this->name = name;
    this->numRooms = numRooms;
    hitPoints = 25;
    location = 0;
    score = 0;
    exp = 0;
    level = 1;
    money = 20;
    healthItem = 1;
    strenth = 1;
}



string Player::getName(){
  return this->name;
}

void Player::moveLeft(){
  if(location > 0){
    location--;
  }else{cout << "thee cannot traveleth this wayy" << endl;}
}

void Player::moveRight(){
  if(location < numRooms){
    location++;
  }else{cout << "thee cannot traveleth this way" << endl;}
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
    int crit = rand() % 5;
    int strike;
    if(crit == 3){int strike = this->strenth + rand() % 10 + 10;}else{int strike = this->strenth + rand() % 10 + 1;}
    theTarget->decreaseHealth(strike);
    cout << "thee striketh " << theTarget->getName() << " dealing " << strike << " damage the impact leaves them with " << theTarget->getHealth() << " health left " << endl ;
}

void Player::bribe(Creature theTarget){
    int amount;
    cout << "How much shall thee bribe?" << endl;
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
      cout << "AHH fine that will do to, you may pass" << endl;
    }
  }


int Player::decreaseHealth(int stirke) {
  int healthLoss = rand() % 10 + stirke - this->strenth;
  hitPoints = hitPoints - healthLoss;
  return hitPoints;
}

int Player::getHealth() {
  return hitPoints;
}

void Player::setHealth(int theHealth) {
  hitPoints = theHealth + hitPoints;
}

void Player::setStrenth(int theStrenth) {
  strenth = theStrenth + strenth;
}

void Player::setExp(int theExp) {
  exp = theExp + exp;
}


int Player::getExp() {
  return exp;
}

int Player::getLevel() {
  return level;
}


int Player::getStrenth() {
  return strenth;
}

int Player::getScore() {
  return score;
}


void Player::levelUp() {
  level++;
  cout << "sir " << this->getName() << " thee has't level'd up thee anon art leveleth " << this->getLevel() << " and has't " << this->getHealth() << " health and " << this->getStrenth() << "strenth" << endl;
  this->setExp(0);
  this->setHealth(this->getHealth() + this->getLevel() * 1);
  this->setStrenth(this->getStrenth() + this->getLevel() + 1);
}

void Player::setScore(int theScore) {
 score = score + theScore;
}


void Player::printInfo()
{
    cout << " thee has't " << money << " gold " << " and has't " << strenth << " strenth" << " and has't " << hitPoints << " health now" << endl;
}

int Player::getHealthItem(){
  return healthItem;
}

int Player::getStrenthItem(){
  return strenthItem;
}
    
int Player::addHealthItem(){
  healthItem++;
  return healthItem;
}

int Player::addStrenthItem(){
  strenthItem++;
  return strenthItem;
}

int Player::useHealthItem(){
  this->hitPoints = hitPoints + 10;
  healthItem--;
  return healthItem;
}

int Player::useStrenthItem(){
  this->strenth = strenth + 1;
  strenthItem--;
  return strenthItem;
}