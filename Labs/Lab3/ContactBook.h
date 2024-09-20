#include <string>
#include <vector>
#include <iostream>

using namespace std;

class Contact {
  private:
    string name;
    string number;
  public:
    Contact(string name,string number);
    string getName();
    string getNumber();
    void Display();
  
};

class ContactBook {
  private:
    int max_size;
    vector<Contact*> contacts;
    unsigned int curr_size = 0; 

  public:
    ContactBook();    
    ContactBook(const int max_size,unsigned int curr_size);

    void Display();
    void Add(Contact& entry);
    Contact* Find(string input);

    void Remove(Contact& toremove);
    void AddContacts(vector<Contact*> toadd);

    void Alphabetize();

    void operator+=(Contact& single);
    void operator+=(ContactBook& book);
    ContactBook operator+(ContactBook& book1);

    void operator-=(Contact& single);
    void operator-=(ContactBook& book);
    ContactBook operator-(ContactBook& book1);

    bool operator==(ContactBook& book);
    bool operator!=(ContactBook& book);


};



  