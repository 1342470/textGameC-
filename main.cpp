#include <iostream>
#include "Player.hpp"
#include "Location.hpp"

int main() {
  Player *myPlayer;

  myPlayer = new Player("Jan");

  myPlayer->bribe(10);
  myPlayer->setName("Bob");
  myPlayer->getName();

  Location *local1;
  Location *local2;
  Location *local3;

  local1 = new Location("a green grasslands");
  local2 = new Location("a dank forest");
  local3 = new Location("a castle");





  return 0;
} 