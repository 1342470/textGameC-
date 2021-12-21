#include<iostream>
#include "Player.hpp"
#include "Location.hpp"


const int numOfRooms = 3;

Player *myPlayer = new Player("Bob", numOfRooms);
Creature *Boss = new Creature("Devil");


//create world by creating a dymic arrary of locaitons 
Location *world[numOfRooms]= {
  new Location("The peaceful City Manclesester where you currently live within"), 
  new Location("Forest full of monsters"), 
  new Location("test")
  }; 


void getWorldLoc(Location *world,Player *thePlayer){
  cout << "Before moving. The Location is: ";
  cout << world->getDescription(thePlayer->getLoc())<< endl;
  cout << "After Moving. The Location is: ";
  cout << world->getDescription(thePlayer->getLoc())<< endl;

}

char getAction(Player *thePlayer,Creature *theTarget){
  char action;

  while ((action != 'f') && (action != 'b')){
    cout << "Would you like to fight or bribe?" << endl;
    cout << "To fight enter 'f'" << endl;
    cout << "To bribe enter 'b'" << endl;
    cout << "to go left enter 'move left'" << endl;
    cout << "to go right enter 'move right'" << endl;
    cin >> action;
  }
  
  return action;
    if(action == 'f'){
      thePlayer->attack(theTarget);
  }

  if(action == 'b'){
    thePlayer->bribe(*theTarget);
  }

}

void story(Player thePlayer, Creature theBoss){
  cout << "thou are sir" << thePlayer.getName() << " thou are thy brave knight who has been tasked in defeating thy evil demon" << theBoss.getName()<< " go forth with thou great chivalry and bravery to save thy day" << " if thou are stuck type help thy when a action is needed to be selected" << endl;
}

void help(){
  cout << "your goal is to get to the evil villans casle and defeat the demon in order to save the world to to move your player type in either move left or right to move, to fight when in battle press f, to bribe a monster press b. If you lose all your health it is gameover." << endl;
}

int main(){

story(*myPlayer,*Boss);

myPlayer->attack(Boss);

getWorldLoc(*world,myPlayer);
  
cout << myPlayer->getLoc() << endl;
  
myPlayer->moveRight();
  
cout << myPlayer->getLoc() << endl;
getWorldLoc(*world,myPlayer);

myPlayer->moveRight();
cout << myPlayer->getLoc() << endl;

}
