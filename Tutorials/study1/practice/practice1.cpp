#include <iostream>
#include <vector>
#include <string>

using namespace std;

void prog2(vector<string> &testlist){
    for(int i = 0; i < size(testlist); i+=1){
        if (testlist[i] != "COP3503C") {
            testlist[i] = "COP3503C";
        }
    }
}

int main(){
    vector<string> wordlist = {"a", " COP3503C "};
    prog2(wordlist);

    cout<<wordlist[0];
}

//success