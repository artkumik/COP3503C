#include "person.h"
#include <iostream>
#include <string>

using namespace std;

Person::Person(){
    name = "Joe";
    age = 0;
}

Person::Person(string name, int age) {
    this -> name = name;
    this -> age = age;
}

void Person::PrintInfo(){
    cout<<"Name: "<< Person::name <<endl;
    cout<<"Age: "<< Person::age <<endl;
}



