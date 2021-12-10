#include<iostream>
#include <time.h>

using namespace std;

class Location
{ 
  string discription;
  int monsters;
  int treasure;

  public:
    string showDiscription();
    Location(string discription);
    ~Location();
};

Location::Location(string theDiscription){
  discription = theDiscription;
}

Location::~Location(){
  cout << "destroying room " << endl;
}

string Location::showDiscription(){
  return discription;
}