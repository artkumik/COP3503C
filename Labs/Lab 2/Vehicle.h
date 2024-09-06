#include <iostream>
#include <vector>
using namespace std;


class Vehicle{
  string make;
  string model;
  int year;
  float price;
  int miles;

public:
  Vehicle();
  Vehicle(string make, string model, int year, float price, int mileage);

  void Display();
  string GetYearMakeModel();
  float GetPrice();
};

