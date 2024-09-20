#include <iostream>
#include <vector>
using namespace std;

#include "Dealership.h"
#include "Showroom.h"
#include "Vehicle.h"

Dealership::Dealership(string name, unsigned int capacity){
  this -> name = name;
  this -> capacity = capacity;
}

void Dealership::AddShowroom(Showroom s){
  if(showrooms.size() == capacity){
    cout << "Dealership is full, can't add another showroom!" << endl;
  }
  else{
    showrooms.push_back(s);
  }
}

float Dealership::GetAveragePrice(){
  float TotValue = 0;
  float TotSize = 0;
  for(int i = 0; i < showrooms.size();i+= 1){
    TotValue += showrooms[i].GetInventoryValue();

    //get amount of cars in each dealership
    TotSize += showrooms[i].GetVehicleList().size();
  }

  float AvgValue;
  if (showrooms.size() == 0) {
    AvgValue = 0;
  }
  else{
    AvgValue = TotValue/TotSize;
  }

  return AvgValue;
}

void Dealership::ShowInventory(){
  if (showrooms.size() == 0) {
    cout << name << " is empty!" << endl;
  }
  else{
    for(int i = 0; i < showrooms.size();i+= 1){
    showrooms[i].ShowInventory();
    cout << endl;
    }
  }

  cout << "Average car price: $" << GetAveragePrice();

}