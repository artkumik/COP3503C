#include <iostream>
#include <array>

using namespace std;

template<typename T>

void printArray(T arrayOutput[], int arraySize){
    cout << "The size of the array is " << arraySize << endl;
    for (int i = 0; i < arraySize; i += 1){
        cout << arrayOutput[i] << endl;
    }
}

int main(){
    int testarray[5] = {1, 2, 3, 4, 5}; // array of 5 integers
    int sum = 0;

    printArray(testarray,5);

    for(int i = 0; i < size(testarray) ; i+=1){
        sum = sum + testarray[i];
    }

    cout << "The sum of the array is " << sum << endl;

    //  g++.\main.cpp
    //  .\a.exe 2
    return 0;
}
