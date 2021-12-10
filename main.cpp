#include <iostream>
#include "Player.hpp"


int main() {
  Player *myPlayer;
  const int numOfRooms = 3;

  myPlayer = new Player("Jan", numOfRooms);

  myPlayer->bribe(10);
  myPlayer->setName("Bob");
  myPlayer->getName();

  //Location *local1;
  //Location *local2;
  //Location *local3;

  Location local1 = Location("a green grasslands");
  Location local2 = Location("a dank forest"); 
  Location local3 = Location("a dank forest");

  Location world[]={local1, local2, local3};
  //world[0] = new Location("a green grasslands");
 // world[1] = new Location("a dank forest");
  //world[2] = new Location("a dank forest");
  
  //world[1]->showDiscription();
   myPlayer->showPos(world);
   myPlayer->moveRight();
   myPlayer->showPos(world);



 // myPlayer
  return 0;
} 