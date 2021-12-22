#include<iostream>
#include "Player.hpp"
#include "Location.hpp"


const int numOfRooms = 3;

Player *myPlayer = new Player("Bob", numOfRooms);
Creature *Boss = new Creature("Devil");

Creature *test = new Creature("Devil2");

//create world by creating a dymic arrary of locaitons 
Location *world[numOfRooms]= {
  new Location("The peaceful City Manclesester where you currently live within"), 
  new Location("Forest full of monsters"), 
  new Location("test")
  }; 


void getWorldLoc(Location *world,Player *thePlayer){
  cout << "Before moving. The Location is: ";
  cout << world->getDescription(thePlayer->getLoc()) << endl;
  cout << "After Moving. The Location is: ";
  cout << world[thePlayer->getLoc()].getDescription(thePlayer->getLoc());

  


  
}

string getAction(Player *thePlayer,Creature *theTarget){
  string action;

  while ((action != "fight") && (action != "bribe")){
    cout << "Would you like to fight or bribe?" << endl;
    cout << "To fight enter fight" << endl;
    cout << "To bribe enter 'bribe'" << endl;
    cin >> action;
  }

  return action;
    if(action == "fight"){
      thePlayer->attack(theTarget);
  }

  if(action == "bribe"){
    thePlayer->bribe(*theTarget);
  }

}

string getMovement(Player *thePlayer){
  string action;
  while ((action != "left") && (action != "right")){
    cout << "Which path will you take?" << endl;
    cout << "There are two paths on leading to the right and one to the lef" << endl;
    cin >> action;
  }

  return action;
    if(action == "left"){

  }

  if(action == "right"){
    
  }
}

void battle(Player *thePlayer,Creature *theTarget){
  while ((thePlayer->getHealth() <= 0) && (theTarget->getHealth() <=0)){
    getAction(thePlayer,theTarget);

  }
}
 

void story(Player thePlayer, Creature theBoss){
  cout << "thou are sir" << thePlayer.getName() << " thou are thy brave knight who has been tasked in defeating thy evil demon" << theBoss.getName()<< " go forth with thou great chivalry and bravery to save thy day" << " if thou are stuck type help thy when a action is needed to be selected" << endl;
}

void help(){
  cout << "your goal is to get to the evil villans casle and defeat the demon in order to save the world to to move your player type in either move left or right to move, to fight when in battle press f, to bribe a monster press b. If you lose all your health it is gameover." << endl;
}

int main(){

// story(*myPlayer,*Boss);
myPlayer->moveRight();
getWorldLoc(*world,myPlayer);
myPlayer->moveRight();
  

  






}
