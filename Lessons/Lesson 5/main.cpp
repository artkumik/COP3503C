#include <iostream>
#include <string>

using namespace std;




int main()
{
    int num = 1;
    int* numPtr = &num; //points to area in memory taken up by num

    cout << num << endl;
    cout << numPtr << endl;

    //changing value of num, doesnt affect pointer
    num = 2;
    numPtr = &num;
    cout << num << endl;

    //changing value of num with numPtr
    *numPtr = 10;

    cout << num << endl;
    cout << numPtr << endl;

    //empty pointer
    int* emptyPtr = nullptr;
}
