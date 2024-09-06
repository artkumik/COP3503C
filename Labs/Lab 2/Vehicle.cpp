#include <iostream>
#include <vector>
using namespace std;
#include "Vehicle.h"

Vehicle::Vehicle(){
  Vehicle::make = "COP3503";
  Vehicle::model = "Rust Bucket";
  Vehicle::year = 1900;
  Vehicle::price = 0;
  Vehicle::miles = 0;
}

Vehicle::Vehicle(string make, string model, int year, float price, int miles){
  this -> make = make;
  this -> model = model;
  this -> year = year;
  this -> price = price;
  this -> miles = miles;

}

void Vehicle::Display(){
  cout << Vehicle::year << " " ;
  cout << Vehicle::make << " " ;
  cout << Vehicle::model << " " ;
  cout << "$" << Vehicle::price << " " ;
  cout << Vehicle::miles << endl ;
}

string Vehicle::GetYearMakeModel(){

  return to_string(Vehicle::year) + " " + Vehicle::make + " " + Vehicle::model;
};

float Vehicle::GetPrice(){
  return Vehicle::price;
}

