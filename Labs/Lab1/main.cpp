#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
using namespace std;

int main(){
   cout << "Enter a title for the data:" << endl;
   string title;
   getline(cin,title);
   cout << "You entered: " + title << endl;

   cout << "Enter the column 1 header:" << endl;
   string col1;
   getline(cin,col1);
   cout << "You entered: " + col1 <<endl;

   cout << "Enter the column 2 header:" << endl;
   string col2;
   getline(cin,col2);
   cout << "You entered: " + col2 <<endl;

  vector<string> names;
  vector<int> number;

  string input;

  int i = 0;
  while(i == 0){
    cout << "Enter a data point (-1 to stop input):" << endl;
    getline(cin,input);

    if(input == "-1"){
      i+=1;
    }

    else{
      string dstring = "";
      string dinteger = "";

      for(int len = 0;len < input.size()-1; len+=1){
        if(input[len] == ','){
            //grab everything before this
            dstring = input.substr(0,len);
            dinteger = input.substr(len+1);

            if (dinteger.find(',') != string::npos){
              cout << "Error: Too many commas in input." << endl;
              break;
            }else if(dinteger.find(',') == string::npos){
                try{
                  int temp = stoi(dinteger);

                  names.push_back(dstring);
                  number.push_back(temp);

                  cout << "Data string: " << dstring << endl;
                  cout << "Data integer: " <<  temp << endl;

                }catch(...){
                  cout << "Error: Comma not followed by an integer." << endl;
                }
            }
        }
      }
      if (input.find(',')==string::npos){
        cout << "Error: No comma in string." << endl;
      }
    }
  }

  cout<<endl;

  //table
  cout << right << setw(33) << title << endl;
  cout << left << setw(20) << col1 << "|" << setw(23) << right << col2 << endl;
  cout << "--------------------------------------------" << endl;
  for(int chars = 0; chars <= number.size()-1; chars+=1){
    cout << left << setw(20) << names[chars]  << "|" << setw(23) << right << number[chars] << endl;
  }

  cout << endl;

  //formatted histogram

  for(int chars = 0; chars <= names.size()-1; chars+=1){
    cout << right << setw(20) << names[chars] << " " << string(number[chars], '*') << endl;
  }

  return 0;
}

//F, Scott Fitzgerald, 8
//F. Scott, Fitzgerald, 8
//F. Scott Fitzgerald, 8