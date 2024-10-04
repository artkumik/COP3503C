#include <iostream>
#include <string>
#include <vector>

using namespace std;


template<typename T>

void print(T toprint){
    cout << toprint << endl;
}

void swapnums(int &i, int &j){
    //pass in memory adresses instead of numbers
    int temp = i;
    i = j;
    j = temp;
}

class nums{
    private:
        int value;
        int listsize;
        int* valueList;

    public:
        nums(){
            this -> value = 0;
            this -> listsize = 1;
            valueList = new int[listsize];
        }
        nums(int newvalue, int newlistsize){
            this -> value = newvalue;
            this -> listsize = newlistsize;
            valueList = new int[listsize];
        }

        ~nums(){
            value = 0;
        }

        //copy constructor
        nums(const nums &obj){
            value = obj.value;
            listsize = obj.listsize;
            valueList = new int[listsize];

            for(int i = 0; i < listsize;i+=1){
                valueList[i] = obj.valueList[i];
            }
        }

        //copy assignment
        nums operator=(const nums &obj){
            //meed
            if (this == &obj) return *this;

            value = obj.value;
            listsize = obj.listsize;
            
            //need
            delete[] valueList;

            valueList = new int[listsize];
            for(int i = 0;i < listsize;i += 1){
                valueList[i] = obj.valueList[i];
            }

            //meed
            return *this;
        }

        void stats(){
            cout << value << endl;
            cout << listsize << endl;
            
            for(int i = 0; i < listsize; i+=1){
                cout << valueList[i] << " ";
            }
            cout << endl;
        }

        void populate(int start){
            for(int i = 0; i < listsize; i += 1){
                valueList[i] = (start + i);
            }   
        }

        nums operator+(nums toadd){

            //adding values
            nums result(value + toadd.value, listsize + toadd.listsize);
            
            //adding from original
            for(int i = 0; i < listsize; i += 1){
                result.valueList[i] = valueList[i];           
            }

            //adding from toadd
            for (int i = 0; i < toadd.listsize; i += 1){
                result.valueList[listsize+i] = toadd.valueList[i];
            }
            
            return result;
        }


};

int main(){
    cout << "Sabrina Carpenter played Fein at a concert!" << endl;
    
    int first = 12;
    int* firstptr = &first;
    int second = 3;

    swapnums(first,second);
    print(first);
    print(second);

    print("\noperator overloading");
    nums n1(1,1),n2(2,2);

    n1.populate(2);
    n2.populate(3);

    nums nt = n1 + n2;
    nt.stats();

    return 0;
}