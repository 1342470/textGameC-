#include <iostream>
#include "Player.hpp"

int main() {
  Player *myPlayer;

  myPlayer = new Player("Jan");

  myPlayer->bribe(10);
  myPlayer->setName("Bob");
  myPlayer->getName();

  

  return 0;
} 