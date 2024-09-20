#include <iostream>
#include <vector>
using namespace std;
#include "Showroom.h"
#include "Vehicle.h"

Showroom::Showroom(string name, unsigned int capacity){
  this -> name = name;
  this -> capacity = capacity;
}

vector<Vehicle> Showroom::GetVehicleList(){
  return vehicles;
}

void Showroom::AddVehicle (Vehicle v){
  if(vehicles.size()<capacity){
    vehicles.push_back(v);
  }
  else{
    cout << "Showroom is full! Cannot add " << v.GetYearMakeModel() << endl;
  }
}

void Showroom::ShowInventory(){
  if (vehicles.size() == 0){
    cout << name << " is empty!" << endl;
  }
  else{
    cout << "Vehicles in " << name << endl;
    for(int i = 0; i <= vehicles.size()-1;i+= 1){
      vehicles[i].Display();}
  
  }
}

float Showroom::GetInventoryValue(){
  float InvValue = 0;
  for(int i = 0; i <= vehicles.size();i+= 1){
    InvValue += vehicles[i].GetPrice();
  }
}