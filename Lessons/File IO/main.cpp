#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main(){
    cout << "Enter some info" << endl;
    
    string input;
    cin >> input;

    ofstream file("foods.txt");
    file << input;
    file.close();
    cout << "You wrote " << input << endl;

    ifstream outputfile("foods.txt");
    string output;
    outputfile >> output;
    outputfile.close();

    cout << "You received " << output << endl;


    cout << "Program has finished running" << endl;
    return 0;

}