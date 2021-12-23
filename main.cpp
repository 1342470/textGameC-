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


//doesn't curenntly move to next location in arrary for come reason
void getWorldLoc(Location *world,Player *thePlayer){
  cout << "Before thy hast moved thou is currently at: ";
  cout << world[thePlayer->getLoc()].getDescription() << endl;
  cout << "After Moving. thou is currently at: ";
  cout << world[thePlayer->getLoc()].getDescription() << endl;
}

//function that when the player loses all of their health it will end the game 
void gameOver(Player *thePlayer){
  cout << "Sir " << thePlayer->getName() << " thou hath died your score was " << thePlayer->getScore() << " and thou hath reached level " << thePlayer->getLevel() << "would you like to try again " << endl;
  string again;
  while(again != "yes"|| again !="Yes" || again!="No" || again!="no" ){
  cin >> again;
  if(again == "yes" || again == "Yes"){
    std::exit(42);
  }
  else if(again == "no" || again == "No"){
    std::exit(0);
  }
  }
}


string getAction(Player *thePlayer,Creature *theTarget){
  string action;
  while ((action != "fight") && (action != "bribe")){
    cout << "Would thy like to Tussle or bribe?" << endl;
    cout << "To Tussle thy must enter fight" << endl;
    cout << "To bribe thy must enter bribe" << endl;
    cin >> action;
    
    if(action == "fight"){
      thePlayer->attack(theTarget);
      thePlayer->getHealth();
      thePlayer->decreaseHealth(theTarget->attack());
  }

  if(action == "bribe"){
    thePlayer->bribe(*theTarget);
  }

  }

}

string getMovement(Player *thePlayer){
  string action;
  while ((action != "left") && (action != "right")){
    cout << "Which path will thy take?" << endl;
    cout << "There are two paths on leading to the right and one to the left" << endl;
    cin >> action;
  }

  return action;
    if(action == "left"){
      thePlayer->moveLeft();
  }

    if(action == "right"){
      thePlayer->moveRight();
  }
}

//signal: illegal instruction (core dumped) on fight and bribe
void battle(Player *thePlayer,Creature *theTarget){
getAction(thePlayer,theTarget);
  while ((thePlayer->getHealth() != 0) && (theTarget->getHealth() !=0)){
    if(thePlayer->getHealth() == 0){
      gameOver(thePlayer);
    }else{
    getAction(thePlayer,theTarget);
    if(theTarget->getHealth() == 0){
      theTarget->~Creature();
      thePlayer->setExp(theTarget->getStrenth()+ 10);
      if(thePlayer->getExp() == 100){
        thePlayer->levelUp();
        thePlayer->setHealth(thePlayer->getHealth() + thePlayer->getLevel() * 1);
        thePlayer->setStrenth(thePlayer->getStrenth() + thePlayer->getLevel() * 1);
      }
      
    }
    }
  }
}
 

void story(Player thePlayer, Creature theBoss){
  cout << "thou are sir " << thePlayer.getName() << " thou are thy brave knight who has been tasked in defeating thy evil demon" << theBoss.getName()<< " go forth with thou great chivalry and bravery to save thy day" << " if thou are stuck type help thy when a action is needed to be selected" << endl;
}

void help(){
  cout << "your goal is to get to the evil villans casle and defeat the demon in order to save the world to to move your player type in either move left or right to move, to fight when in battle press f, to bribe a monster press b. If you lose all your health it is gameover." << endl;
}

int main(){
story(*myPlayer,*Boss);
battle(myPlayer,Boss );
getMovement(myPlayer);

}
