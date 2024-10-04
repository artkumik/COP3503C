#include <iostream>

using namespace std;

int* checker(int* num){
    if(*num % 3 == 0){
        return num;
    }
    else if(*num % 5 == 0){
        *num = 10;
        return num;
    }
    else{
        num = nullptr;
        return num;
    }
}

int main(){
    int value = 8;
    int* valueptr = &value;
    std::cout << *checker(valueptr);

}