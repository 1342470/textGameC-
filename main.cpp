#include <iostream>
#include "Player.hpp"
#include "Location.hpp"

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

  //local1 = 
  //local2 = 
  //local3 = 

  Location *world[numOfRooms];
  world[0] = new Location("a green grasslands");
  world[1] = new Location("a dank forest");
  world[2] = new Location("a castle");
 
 // myPlayer
  return 0;
} 