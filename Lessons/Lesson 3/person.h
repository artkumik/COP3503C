#include <iostream>
#include <string>

using namespace std;

class Person{
  string name;
  int age;
public:
  Person();
  Person(string newName, int newAge);
  void PrintInfo();
};

