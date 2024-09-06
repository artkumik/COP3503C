#include <iostream>
#include <string>
using namespace std;

//stack
//first in last out, basically list but the last thing you put in is what you take out
//add (push) or remove(pop)
//running out of memory on stack -> stack overflow, will prob not happen tho

//dynamically allocate
//need to use delete sometimes to prevent memory leak

//notes on heap! Help

void demo()
{
    // static variable
    static int count = 0;
    cout << count << " ";

    // value is updated and will be carried to next function calls
    // could maybe be used for counting the amount of time a function is called?

    count++;
}

int main()
{
    for (int i = 0; i < 5; i++)
        demo();
    return 0;
}
