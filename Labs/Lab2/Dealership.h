#include <iostream>
#include <vector>
using namespace std;

class Vehicle;
class Showroom;

class Dealership{
  string name;
  unsigned int capacity;
  vector<Showroom> showrooms;

  public:
    Dealership(string name = "Generic Dealership", unsigned int capacity = 0);

    void AddShowroom(Showroom a);
    float GetAveragePrice();
    void ShowInventory();
};