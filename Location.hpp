#include<iostream>
#include<string>
using namespace std;
 

class Location
{
  private:
    string description;
    int treasure;
  public:
    Location(string description);
    //void getLocation();
    string getDescription(int location);
    int getTreasure(); 
};

Location::Location(string description){
    this->description = description;
}

string Location::getDescription(int location){
  return this->description;
}

int Location::getTreasure(){
  return this->treasure;
}