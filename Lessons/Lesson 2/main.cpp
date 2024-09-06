#include <iostream>
#include <string>

using namespace std;

//namespace
namespace MyCode {
    int x,y,z;
    float Foo();
}
// if variable or function are the same name across namespaces, use ::

//global variables go outside of main

class Hero {
    string name;
    int strength;

};

int main()
{
    MyCode::x = 12;
    cout << MyCode::x << endl;

    //enums (enumerated list)

    cout << "Hello, World!" << endl;
    return 0;
}
