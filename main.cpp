#include<iostream>
#include "Player.hpp"
#include "Location.hpp"
#include <stdio.h>    



const int numOfRooms = 6;

Player *myPlayer = new Player("Bob", numOfRooms);
Creature *Boss = new Creature("Devil");
Creature *Troll = new Creature("Forest troll");
Creature *shopKeeper = new Creature("shopKeeper");

//create world by creating a dymic arrary of locaitons 
Location *world[numOfRooms]= {
  new Location("The peaceful City Manclesester where you currently live within before you leave you may want to visit the store from the right path exit where you may find some items with you that may help you on your jurney"),
  new Location("In the bazzar you see two shopKeepers one calls out exclaming that they have many healing potions that may come handy.The second Keeper seems to be selling strenth potions however it seems like these potions are quite expensive"), 
  new Location("You are in a deep Forest full of large towering oak trees, due to the mass number of trees around you the light is faint however you are able to see in front of you a monster is blocking the path ahead, the monster spots you and starts to sprint towards you get ready for battle."), 
  new Location("A safe area which has a cave surrounded by two large fields of flowers. By the cave you see a man near a campfire, he looks like he has a huge backback full of wares"),
  new Location("Finaly after your jurney you have reached the lare of the demon king around you are great paintings of the previous leaders as well as a winding long carpet that leads to a fork before the path splits their are a number of creatures before you"),
  new Location("In the demon kings thrown room you see the demon king at the end of the room sat in a great thrown with ")
  }; 

struct item{
  string type;
  int numberOf;
}health, strenth;

//doesn't curenntly move to next location in arrary for come reason
void getWorldLoc(Location *world[],Player *thePlayer){
  cout << "thou is currently at: ";
  cout << world[thePlayer->getLoc()]->getDescription() << endl;
  cout << "what will thou do?" << endl;
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
    cout << " thank you for playing " <<endl;
  }
  }
}


string getMovement(Player *thePlayer){
  string action;
  while ((action != "left") && (action != "right")){
    cout << "which path shall thy taketh?" << endl;
    // cout << "There are two paths on leading to the right and one to the left" << endl;
    cin >> action;
  
    if(action == "left"){
      thePlayer->moveLeft();
      return action;
  }

    if(action == "right"){
      thePlayer->moveRight();
      getWorldLoc(world,myPlayer);
      return action;
  }else{cout << "i dont knoweth yond action" << endl; return action;}

  }
}

void help(){
  cout << "your goal is to get to the evil villans castle and defeat the demon in order to save the world to to move your player type in either move left or right to move, to fight when in battle type fight, to bribe a monster type bribe. If you lose all your health it is gameover." << endl;
}

void battle(Player *thePlayer,Creature *theTarget){
  string action;  
    while ((action != "fight") && (action != "bribe") && (action != "item")){ 
    cout << "Would thy like to Tussle or bribe?" << endl;
    cout << "To Tussle thy must enter fight" << endl;
    cout << "To bribe thy must enter bribe" << endl;
    cout << "to use a item thy must enter item" << endl;
    cin >> action;
    if(action == "item"){
      string itemAction;
      while ((itemAction != "strenth") && (itemAction != "health") && (itemAction != "back")){
        cout << "what will you use strenth or health potion?" << endl;
        cout << "to use a strenth potion enter strenth" << endl;
        cout << "to use a health potion enter health" << endl;
        cout << "if you change your mind enter back" << endl;
        cin >> itemAction;
        if(itemAction == "back"){
          action = "next";
        }else if(itemAction == "health"){
          if(thePlayer->getHealthItem() >0){
            thePlayer->useHealthItem();
            cout << "you use the health potion you now have " << thePlayer->getHealth() << " health left " << endl;
            action = "next";
          }else if(thePlayer->getHealthItem() == 0){
            cout << "you don't have enough potions for that" << endl;
            action = "next";
          }
        }
         if(itemAction == "strenth"){
          if(thePlayer->getStrenthItem() >0){
            thePlayer->useStrenthItem();
            cout << "you use the Strenth potion you now have " << thePlayer->getStrenth() << " Strenth" << endl;
            action = "next";
          }else if(thePlayer->getStrenthItem() == 0){
            cout << "you don't have enough potions for that" << endl;
            action = "next";
          }
        }
      }
    }
    if(action == "fight"){
      thePlayer->attack(theTarget);
      thePlayer->getHealth();
      if(theTarget->getHealth() >=0){
        thePlayer->decreaseHealth(theTarget->attack());
        cout << theTarget->getName() << " striketh backeth thee anon has't " << thePlayer->getHealth() << " health hath left" ;
      }
      if(thePlayer->getHealth() <= 0){
        gameOver(thePlayer);
      }else if(theTarget->getHealth() <= 0){
      theTarget->~Creature();
      cout << "sir  " << thePlayer->getName() << " thee has't did gain exp'rience "  << theTarget->getStrenth()+ 10 << endl ;
      thePlayer->setExp(theTarget->getStrenth()+ 10);
      cout << "thee anon has't " << thePlayer->getExp() <<  " exp'rience" << endl;
      if(thePlayer->getExp() >= 25){
        thePlayer->levelUp();
      }
      
    }
    else{
      action = "next";
      }
    } 

  if(action == "bribe"){
    thePlayer->bribe(*theTarget);
    action = "next";
  }if(action == "help"){
    help();
    action = "next";
  }
    }
  }



 

void story(Player thePlayer, Creature theBoss){

  cout << "thou are sir " << thePlayer.getName() << " thou are thy brave knight who has been tasked in defeating thy evil demon " << theBoss.getName()<< " go forth with thou great chivalry and bravery to save thy day" << " if thou are stuck type help thy when a action is needed to be selected" << endl;
}

void getName(Player *thePlayer){
  string theName;
  string response;
  string correct = "no";
  cout <<  "bef're we beginneth thee might not but ent'r thy nameth" << endl;

  while(correct !="yes"){
    cout << "Your name" << endl;
    cin >> theName;
    cout << "so thy nameth is " << theName <<  " c'rrect?" << endl;
    cin >> response;
    if(response == "yes"){
      thePlayer->setName(theName);
      correct = "yes";
      story(*thePlayer,*Boss);
    }else{
      cout << "s'rry a gods hearing can receiveth mufffl'd when thy omnipresent" << endl; correct = "no";
    }
  }
} 



void darkWoods(){
  getWorldLoc(world,myPlayer);
  battle(myPlayer,Troll);
  
}





void bazar(){
  while (myPlayer->getHealth() > 0){
    if(myPlayer->getLoc() == 1){
      string action;
      while ((action != "talk") && (action != "right") && (action !="help")){
        cout << "you can either 'talk' to the shopkeppers or go 'right' to head out of town" << endl;
      cin >> action;
      if(action == "right"){
      myPlayer->moveRight();
      darkWoods();
    }else if(action == "help"){
    help();
    action = "next";
  }
    else if(action == "talk"){
      string itemAction;
      while ((itemAction != "health") && (itemAction != "health") && (itemAction != "back")){
         cout << "which shopkeeper will you speak to you can either talk to the 'health' shopkeeper or the 'strenth' shopkeeper? If you deside you don't want anything go 'back' to the bazar hub" << endl;
        cin >> itemAction;
        if(itemAction == "back"){
          action = "next";
        }else if(itemAction == "health"){
          string responce;
          while ((responce != "yes") && (itemAction != "no")){
            cout << "Hello their good sir would you like to buy a health potion it will cost you 5 Gold" << endl; 
            cin >> responce;
            if(responce == "yes" && myPlayer->getMoney() > 4){
              cout << "The shopkeeper replys: thanketh thee f'r thy purchaseth" << endl;
              myPlayer->addHealthItem();
              myPlayer->minusMoney(5);
              cout << " After buying a health potion you now have " << myPlayer->getHealthItem() << " health potions and have " << myPlayer->getMoney() << " gold left" <<endl;
              action = "next";
          }else if(responce == "yes" && myPlayer->getMoney() <= 4) {
            cout << "s'rry thee dont has't enow wage i cannot do free giveaways";
            action = "next";
          }else if(responce == "no"){
            cout << "fine suiteth thy self" << endl;
            itemAction = "no";
            action = "next";
            
            }
          }
        }
         if(itemAction == "strenth"){
          string responce;
          while ((responce != "yes") && (itemAction != "no")){
            cout << "Hello their good sir would you like to buy a strenth potion it will cost you 15 Gold" << endl; 
            cin >> responce;
            if(responce == "yes" && myPlayer->getMoney() > 15){
              cout << "The shopkeeper replys: thanketh thee f'r thy purchaseth" << endl;
              myPlayer->addStrenthItem();
              myPlayer->minusMoney(15);
              cout << " After buying a Strenth potion you now have " << myPlayer->getStrenthItem() << " strenth potions and have "  << myPlayer->getMoney() << " gold left" <<endl;
              action = "next";
          }else if(responce == "yes" && myPlayer->getMoney() < 14) {
            cout << "s'rry thee dont has't enow wage i cannot do free giveaways";
            action = "next";
          }else if(responce == "no"){
            cout << "fine suiteth thy self";
            action = "next";
          }

        }
          }
        
      }
    }

    else{
      action = "next";
      }
    } 
    }
    }
  }
  
    

  


void homeTown(){
  while (myPlayer->getHealth() > 0){
     if(myPlayer->getLoc() == 0){
        getWorldLoc(world,myPlayer);
        getMovement(myPlayer);
        if(myPlayer->getLoc() == 1){
          bazar();
        }
     }
  }
}

void game(){
  homeTown();
}

int main(){
  
  Boss->printInfo();
  Troll->printInfo();
  getName(myPlayer);
  game();

return 0;
}

