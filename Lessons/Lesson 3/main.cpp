#include <iostream>
#include "person.cpp"

using namespace std;

/*
object oriented programming
encapsulation : group data and functionality together
Create a public interface, do the "real work" in private
instance/instantiation

class definition go into the .h file
class member functions go into .cpp file*/;



int main()
{

    Person defaultp;
    defaultp.PrintInfo();

    Person myObject("John",4);
    myObject.PrintInfo();

    //errror



    return 0;
}
