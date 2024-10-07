#include <iostream>
#include <cstdlib>
#include <string>

using namespace std;

int main(){
    cout << "say hello to mr lion" << endl;
    string lionbuffer;
    cin >> lionbuffer;

    if (lionbuffer == "hello"){
        system("start lioncool.jpg");
    }
}