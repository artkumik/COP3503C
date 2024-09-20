#include <iostream>
#include <vector>
using namespace std;

class Vehicle;

class Showroom{
  string name;
  vector<Vehicle> vehicles;
  int capacity;

public:
  Showroom(string name = "Unnamed Showroom", unsigned int capacity = 0);

  vector<Vehicle> GetVehicleList(); 

  void AddVehicle(Vehicle v);
  void ShowInventory();
  float GetInventoryValue();
  
};