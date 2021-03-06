#include<iostream>
#include "Player.hpp"
#include "Location.hpp"
#include <stdio.h>    

const int numOfRooms = 6;

//create objects for the player and the creatures
Player *myPlayer = new Player("Bob", numOfRooms);
Creature *Boss = new Creature("Devil");
Creature *Troll = new Creature("Forest troll");
Creature *Troll2 = new Creature("Forest troll");
Creature *shopKeeper = new Creature("shopKeeper");
Creature *Demon = new Creature("Demon A");
Creature *Demon1 = new Creature("Demon B");
Creature *Fianl = new Creature("Demon King");

//create world by creating a dymic arrary of locaitons each location takes a string that is the discription of the location
Location *world[numOfRooms]= {
  new Location("The peaceful City Manclesester where you currently live within before you leave you may want to visit the store from the right path exit where you may find some items with you that may help you on your jurney"),
  new Location("In the bazzar you see two shopKeepers one calls out exclaming that they have many healing potions that may come handy.The second Keeper seems to be selling strenth potions however it seems like these potions are quite expensive"), 
  new Location("You are in a deep Forest full of large towering oak trees, due to the mass number of trees around you the light is faint however you are able to see in front of you a monster is blocking the path ahead, the monster spots you and starts to sprint towards you get ready for battle."), 
  new Location("A safe area which has a cave surrounded by two large fields of flowers. By the cave you see a man near a campfire, he looks like he has a huge backback full of wares. You can either 'speak' to the shopkepper sat by the campfire or go 'forward' to head out toward out into the field"),
  new Location("Finaly after your jurney you have reached the lare of the demon king around you are great paintings of the previous leaders as well as a winding long carpet that leads to a fork before the path splits their are a number of creatures before you"),
  new Location("In the demon kings thrown room you see the demon king at the end of the room sat in a great throne with a great menacing grin he bellows:")
  }; 

//store items with number of each item that can be dropped by npc
struct item{
  string type;
  int numberOf;
}health, strenth;

//function that prints out the correct location based on the players location. the pointer world that is required will be the arrary that store each location object that has a string of its desciption. the player pass will keep track on its location that will be passed into the world arrar to get the current locaitons string.
void getWorldLoc(Location *world[],Player *thePlayer){
  cout << endl;
  cout << "thou is currently at: " << endl <<endl;
  cout << world[thePlayer->getLoc()]->getDescription() << endl;
  cout << "what will thou do?" << endl << endl;
}

//function that when the player loses all of their health it will end the game. o
void gameOver(Player *thePlayer){
  // print out all player information from current session
  cout << thePlayer->getTitle() << " " << thePlayer->getName() << " thou hath died your score was " << thePlayer->getScore() << " and thou hath reached level " << thePlayer->getLevel() << "would you like to try again " << endl;
  string again;
  //while agian isn't valid ask the user if they want to play again
  while(again != "yes"|| again !="Yes" || again!="No" || again!="no" ){
  cin >> again;
  // if yes restart game
  if(again == "yes" || again == "Yes"){
    std::exit(42);
  }
  //if no thank player
  else if(again == "no" || again == "No"){
    cout << " thank you for playing " <<endl;
  }
  }
}

// function that is ran once the player has compleated the game.
void gameWin(Player *thePlayer){
  cout << endl;
  // print results
  cout << thePlayer->getTitle() << " " << thePlayer->getName() << " thou hath defeated the demon king. As so traveleth backeth to thy hometown thee rememb'r all of the tasks thee hadst to taketh in thy adventrue as well as how much thee hadst grown.  Once thee returneth to thy hometown thou art did greet by the king and did thank f'r thy eff'rts as a reward thee and thy town has't a most wondrous feast  your score was " << thePlayer->getScore() << " and thou hath reached level " << thePlayer->getLevel() << endl << " would you like to try again? " << endl;
  string again;
  //ask player if they want to play again
  while(again != "yes"|| again !="Yes" || again!="No" || again!="no" ){
  cin >> again;
  // if yes restart
  if(again == "yes" || again == "Yes"){
    std::exit(42);
  }
  // if no thank player
  else if(again == "no" || again == "No"){
    cout << " thank you for playing " <<endl;
  }
  }
}

//fucntion that takes user input to get player to a diffrent locaiton
string getMovement(Player *thePlayer){
  string action;
  // while action is invaild ask play where they want to go
  while ((action != "left") && (action != "right")){
    cout << "which path shall thy taketh?" << endl;
    cin >> action;
    // if left move run move left
    if(action == "left"){
      thePlayer->moveLeft();
      cout << endl;
      return action;
  }
    // if right move right and get location
    if(action == "right"){
      thePlayer->moveRight();
      getWorldLoc(world,myPlayer);
      cout << endl;
      return action;
  // if invaild print to user that this action is invaild
  }else{cout << "i dont knoweth yond action" << endl; return action;}

  }
}

//function that gives the user a reminder of how to play
void help(){
  cout << endl;
  cout << "your goal is to get to the evil villans castle and defeat the demon in order to save the world to to move your player type in either move left or right to move, to fight when in battle type fight, to bribe a monster type bribe. If your not sure what to do next try looking at the current locations discription to give you hints, if you see anything inside single quotes that is action that you can take. If you lose all your health it is gameover." << endl << endl;
}

// funciton that takes the player and target for their stats and fights until one of the objects hp is 0
void battle(Player *thePlayer,Creature *theTarget){
//action is a string used by the loop to detemin the users input it will check if they entered a vaild command if anything else other than the options is reutrned loop back.  
  string action;  
// while action is invaild ask player if they want to fight, bribe or use item
    while ((action != "fight") && (action != "bribe") && (action != "item")){ 
    cout << endl;
    cout << "Would thy like to Tussle or bribe?" << endl;
    cout << "To Tussle thy must enter fight" << endl;
    cout << "To bribe thy must enter bribe" << endl;
    cout << "to use a item thy must enter item" << endl;
    cin >> action;
// if action ask player what they want to use while itemaction is invaild
    if(action == "item"){
// itemaction is a string used by the loop to detemin the users input it will check if they entered a vaild command if anything else other than the options is reutrned loop back.
      string itemAction;
      while ((itemAction != "strenth") && (itemAction != "health") && (itemAction != "back")){
        cout << endl;
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
        }else if(itemAction == "strenth"){
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
// if fight fun attack funciton on the object passed into the fuction and get the health 
    if(action == "fight"){
      thePlayer->attack(theTarget);
      thePlayer->getHealth();
// if the target isn't dead allow it to attack the player and print the result
      if(theTarget->getHealth() >=0){
        thePlayer->decreaseHealth(theTarget->attack());
        cout <<endl;
        cout << theTarget->getName() << " striketh backeth thee anon has't " << thePlayer->getHealth() << " health hath left" <<endl <<endl ;
      }
// if the player has been killed run gameover
      if(thePlayer->getHealth() <= 0){
        gameOver(thePlayer);
// if target is killed run its deconstrutor and give the player their exp and gold based on the targets stats
      }else if(theTarget->getHealth() <= 0){
      theTarget->~Creature();
      cout <<endl;
      cout << thePlayer->getTitle() << " " << thePlayer->getName() << " thee hasn't did gain " << theTarget->getStrenth()+ rand() % 10 + 1 << " gold " << endl;
      thePlayer->setMoney(theTarget->getStrenth()+ rand() % 10 + 1 );
      cout << "thee anon has't " << thePlayer->getMoney() <<  " gold " << endl;
      cout << thePlayer->getTitle() << " " <<  thePlayer->getName() << " thee has't did gain " << theTarget->getStrenth()+ rand() % 10 + 1 << " exp'rience " << endl ;
      thePlayer->setExp(theTarget->getStrenth()+ 10);
      thePlayer->setScore(theTarget->getStrenth()+ 150);
      cout << "thee anon has't " << thePlayer->getExp() <<  " exp'rience" << endl;
      if(thePlayer->getExp() >= 25){
        thePlayer->levelUp();
      }
      
    }
    else{
      action = "next";
      }
    } 
// if bribe run player bribe function
  if(action == "bribe"){
    thePlayer->bribe(*theTarget);
    action = "next";
// if help run help funciton
  }if(action == "help"){
    help();
    action = "next";
  }
    }
  }



 
// prints the games story out with the players name as well as the final boss.
void story(Player thePlayer, Creature theBoss){
  cout << endl;
  cout << "thou are " << thePlayer.getTitle() << " " << thePlayer.getName() << " thou are thy brave knight who has been tasked in defeating thy evil demon " << theBoss.getName()<< " go forth with thou great chivalry and bravery to save thy day" << " if thou are stuck type help thy when a action is needed to be selected" << endl << endl;
}

//allows user to enter their title 
void getTitle(Player *thePlayer){
  string theTitle;
  string responce;
  string correct = "no";
  cout <<  "next ent'r thy title: chooseth eith'r sir 'r lady " << endl;

  while(correct !="yes"){
    cout << "Your Title" << endl;
    cin >> theTitle;
    cout << "so thy is a " << theTitle <<  " c'rrect?" << endl;
    cin >> responce;
    if(responce == "yes"){
      thePlayer->setTitle(theTitle);
      correct = "yes";
      cout << endl;
      story(*thePlayer,*Boss);
    }else{
      cout << endl;
      cout << "s'rry a gods hearing can receiveth mufffl'd when thy omnipresent" << endl; correct = "no";
    }
  }
} 

//allows player to enter their own name.
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
      cout << endl;
      getTitle(myPlayer);
    }else{
      cout << endl;
      cout << "s'rry a gods hearing can receiveth mufffl'd when thy omnipresent" << endl; correct = "no";
    }
  }
} 

void finalArea(){
  cout << endl;
  getWorldLoc(world, myPlayer);
  cout << "so ya finally made it do ya really fink 'dat ya kan stompn me well den have at it." << endl << endl;
  battle(myPlayer,Fianl);
  gameWin(myPlayer);
}

void demonCastleEntry(){
  string respose;
  string action;
  string target;
  string targetSneak;
  int sneakRng = rand() % 10;
  cout << endl;
  while((action !="sneak") && (action !="attack")){
    getWorldLoc(world, myPlayer);
    cout << "Will you try and 'attack' the creatures before or will you try and 'sneak' around" << endl;
    cin >> action;
    if(action == "attack"){
      cout << endl;
      cout << "which creature will you target first Demon 'A' or 'B'" << endl;
        cin >> target;
        if(target == "A"){
          battle(myPlayer,Demon);
          battle(myPlayer,Demon1);
          myPlayer->moveRight();
          finalArea();
        }else if(target == "B"){
          battle(myPlayer,Demon1);
          battle(myPlayer,Demon);
          myPlayer->moveRight();
          finalArea();
        }else{target = "next";}
    }else if(action == "sneak" && sneakRng == 3 ){
      cout << endl;
      cout << "thee luckly make shift to sneak 'round the creatures and headeth into the next room" <<endl;
      myPlayer->moveRight();
      finalArea();
    }else if(action == "sneak" && sneakRng !=3){
      cout << "thee tryeth to sneak 'round the creatures and headeth into the next area howev'r the creatures react to the sound of thy steps." << endl;
      while((targetSneak != "A") && (targetSneak !="B")){
        cout << endl;
        cout << "which creature will you target first Demon 'A' or 'B'" << endl;
        cin >> targetSneak;
        if(targetSneak == "A"){
          cout << "Demon A appears" << endl;
          battle(myPlayer,Demon);
          cout << "Demon B appears" << endl;
          battle(myPlayer,Demon1);
          myPlayer->moveRight();
          finalArea();
        }else if(targetSneak == "B"){
          cout << "Demon B appears" << endl;
          battle(myPlayer,Demon1);
          cout << "Demon A appears" << endl;
          battle(myPlayer,Demon);
          myPlayer->moveRight();
          finalArea();
        }else{targetSneak = "next";}
      }
    }else{action = "next";}
      

  }
  cout << Troll->getName() << " appears " << endl;
  battle(myPlayer,Troll);
  cout << endl;
}

void safeZone(){
  while (myPlayer->getHealth() > 0){
      string action;
      while ((action != "speak") && (action != "forward") && (action !="help")){
      getWorldLoc(world,myPlayer);
      cin >> action;
      if(action == "forward"){
      myPlayer->moveRight();
      demonCastleEntry();
    }else if(action == "help"){
    help();
    action = "next";
  }
    else if(action == "speak"){
      string itemAction;
      while ((itemAction != "health") && (itemAction != "strenth") && (itemAction != "back")){
        cout << endl;
        cout << "valorous day i've did get two typeth of items f'r sale wouldst thee liketh to seeth a 'health' of a 'strenth' potion If you deside you don't want anything go 'back' to the bazar hub" << endl;
        cin >> itemAction;
        if(itemAction == "back"){
          action = "next";
        }else if(itemAction == "health"){
          string responce;
          while ((responce != "yes") && (itemAction != "no")){
            cout << endl;
            cout << "Hello their good " << myPlayer->getTitle() << " would you like to buy a health potion it will cost you 9 Gold" << endl; 
            cin >> responce;
            if(responce == "yes" && myPlayer->getMoney() > 8){
              cout << endl;
              cout << "The shopkeeper replys: thanketh thee f'r thy purchaseth" << endl;
              myPlayer->addHealthItem();
              myPlayer->minusMoney(9);
              cout << " After buying a health potion you now have " << myPlayer->getHealthItem() << " health potions and have " << myPlayer->getMoney() << " gold left" <<endl;
              itemAction = "next";
          }else if(responce == "yes" && myPlayer->getMoney() <= 8) {
            cout << endl;
            cout << "s'rry thee dont has't enow wage i cannot do free giveaways";
            safeZone();
          }else if(responce == "no"){
            cout << endl;
            cout << "fine suiteth thy self" << endl;
            safeZone();
            
            }
          }
        }
         if(itemAction == "strenth"){
          string responce;
          while ((responce != "yes") && (itemAction != "no")){
            cout << endl;
            cout << "Hello their good " << myPlayer->getTitle() << " would you like to buy a strenth potion it will cost you 20 Gold" << endl; 
            cin >> responce;
            if(responce == "yes" && myPlayer->getMoney() > 19){
              cout << "The shopkeeper replys: thanketh thee f'r thy purchaseth" << endl;
              myPlayer->addStrenthItem();
              myPlayer->minusMoney(20);
              cout << " After buying a Strenth potion you now have " << myPlayer->getStrenthItem() << " strenth potions and have "  << myPlayer->getMoney() << " gold left" <<endl;
              itemAction = "next";
          }else if(responce == "yes" && myPlayer->getMoney() <= 19) {
            cout << endl;
            cout << "s'rry thee dont has't enow wage i cannot do free giveaways";
            safeZone();
          }else if(responce == "no"){
            cout << endl;
            cout << "fine suiteth thy self";
            safeZone();
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

void darkWoods(){
  cout << endl;
  string movement;
  getWorldLoc(world,myPlayer);
  cout << endl;
  cout << Troll->getName() << " appears " << endl;
  battle(myPlayer,Troll);
  cout << endl;
  cout << "after the battle with the first creature the sounds grabs the attention of one of its fellow allies, you must get ready for battle one again" << endl << endl;
  cout << Troll->getName() << " aproaches " << endl;
  battle(myPlayer,Troll2);
  cout <<endl;
  while ((movement != "left") && (movement != "center") && (movement !="right")){
    cout << "Now all creatures that plauged this area has been taken care of you see that their is a path that winds down into three paths. Some say that two of these paths is cursed and those that lead that route is doomed to wander in the lost woods for eturnaty, one path goes to the 'left', one to the 'right' and one in the 'center'. pick carefully" << endl;
        cin >> movement;
        if(movement == "left"){
            cout <<endl;
            cout << " thee picketh the hath left path howev'r thee findeth thee didn't taketh the warning of the hath lost woods thee wand'r aimlessly until thee passeth out" << endl;
            gameOver(myPlayer);
          }else if(movement == "center"){
            myPlayer->moveRight();
            safeZone();
          }else if(movement == "right"){
            cout <<endl;
            cout << " thee picketh the hath center path howev'r thee findeth thee didn't taketh the warning of the hath lost woods thee wand'r aimlessly until thee passeth out" << endl;
            gameOver(myPlayer);
          }else{ movement = "next";}
        }
     
  

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
        cout << endl;
        cout << "which shopkeeper will you speak to you can either talk to the 'health' shopkeeper or the 'strenth' shopkeeper? If you deside you don't want anything go 'back' to the bazar hub" << endl;
        cin >> itemAction;
        if(itemAction == "back"){
          action = "next";
        }else if(itemAction == "health"){
          string responce;
          while ((responce != "yes") && (itemAction != "no")){
            cout << endl;
            cout << "Hello their good " << myPlayer->getTitle() << " would you like to buy a health potion it will cost you 5 Gold" << endl; 
            cin >> responce;
            if(responce == "yes" && myPlayer->getMoney() > 4){
              cout << endl;
              cout << "The shopkeeper replys: thanketh thee f'r thy purchaseth" << endl;
              myPlayer->addHealthItem();
              myPlayer->minusMoney(5);
              cout << " After buying a health potion you now have " << myPlayer->getHealthItem() << " health potions and have " << myPlayer->getMoney() << " gold left" <<endl;
              action = "next";
          }else if(responce == "yes" && myPlayer->getMoney() <= 4) {
            cout << endl;
            cout << "s'rry thee dont has't enow wage i cannot do free giveaways";
            action = "next";
          }else if(responce == "no"){
            cout << endl;
            cout << "fine suiteth thy self" << endl;
            itemAction = "no";
            action = "next";
            
            }
          }
        }
         if(itemAction == "strenth"){
          string responce;
          while ((responce != "yes") && (itemAction != "no")){
            cout << endl;
            cout << "Hello their good " << myPlayer->getTitle() << " would you like to buy a strenth potion it will cost you 15 Gold" << endl; 
            cin >> responce;
            if(responce == "yes" && myPlayer->getMoney() > 15){
              cout << "The shopkeeper replys: thanketh thee f'r thy purchaseth" << endl;
              myPlayer->addStrenthItem();
              myPlayer->minusMoney(15);
              cout << " After buying a Strenth potion you now have " << myPlayer->getStrenthItem() << " strenth potions and have "  << myPlayer->getMoney() << " gold left" <<endl;
              action = "next";
          }else if(responce == "yes" && myPlayer->getMoney() < 14) {
            cout << endl;
            cout << "s'rry thee dont has't enow wage i cannot do free giveaways";
            action = "next";
          }else if(responce == "no"){
            cout << endl;
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
        string action;
        while ((action != "talk") && (action != "move") && (action !="help")){
        cout << "you can either 'talk' to the civilian or go 'move' to head into the bazar" << endl;
        cin >> action;
        if(action == "help"){
            help();
            action = "next";
          }else if(action == "move"){
            myPlayer->moveRight();
            getWorldLoc(world,myPlayer);
            bazar();
          }else if(action == "talk"){
            cout << endl;
            cout << "Ho traveleth'r a tipeth f'r thee, if 't be true thee ev'r headeth into the dark woods tryeth to sayeth hence from the far left path and right path. Those gents sayeth yond that those path leads into a endless path and traveleth'rs yond wend yond way art nev'r seen again." << endl << endl;
            action = "next";
          }
        }
     }
  }
}

void game(){
  homeTown();
}

int main(){
  getName(myPlayer);
  game();


return 0;
}

