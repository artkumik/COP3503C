#include "ContactBook.h"
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

Contact::Contact(string name, string number){
  this -> name = name;
  this -> number = number;
}

string Contact::getName(){
  return name;
}

string Contact::getNumber(){
  return number;
}

void Contact::Display(){
  cout << name << ", " << number << endl;
}

//contact book
ContactBook::ContactBook(){
  this -> max_size = 100;
  this -> curr_size = 0;
}

ContactBook::ContactBook(int max_size,unsigned int curr_size){
  this -> max_size = max_size;
  this -> curr_size = curr_size;
} 

void ContactBook::Display(){
  for(int i = 0; i < contacts.size(); i += 1){
    contacts[i]->Display(); //accessing stuff from pointer, not value so no derefence
  }
}

void ContactBook::Add (Contact& entry){
  if (curr_size < max_size) {
    contacts.push_back(&entry); //why is this?
    curr_size++;
  }
  else{
    cout << "Contact Book is full" << endl;
  }
  
} 

//stupid
Contact* ContactBook::Find(string input){
  for(int i = 0; i < contacts.size(); i += 1){
    if (contacts[i] -> getName() == input || contacts[i] -> getNumber() == input){
      return contacts[i];
    }
    else{
      //temp print
      //cout << "Not in " << i << endl;
    }
  }
  return nullptr;
};

void ContactBook::Remove(Contact& toremove){
  for(int i = 0; i < contacts.size(); i += 1){
    if (contacts[i]->getName() == toremove.getName() && contacts[i]->getNumber() == toremove.getNumber()){
      contacts.erase(contacts.begin() + i);
    }
  }
};

void ContactBook::AddContacts(vector<Contact*> toadd){
  for(int i = 0; i < toadd.size(); i += 1){
    contacts.push_back(toadd[i]);
  }
}

void ContactBook::Alphabetize() {
  //how does this work
    sort(contacts.begin(), contacts.end(), [](Contact* a, Contact* b) {
      return a->getName() < b->getName();
    });
}


void ContactBook::operator+=(Contact& single){
  ContactBook::Add(single);
};

void ContactBook::operator+=(ContactBook& book){
  ContactBook::AddContacts(book.contacts);
};

ContactBook ContactBook::operator+(ContactBook& book1){
  ContactBook temp = *this;
    for (int i = 0; i < book1.contacts.size(); i++) {
      temp.Add(*book1.contacts[i]);
    }
    return temp;
};

void ContactBook::operator-=(Contact& single){
  ContactBook::Remove(single);
};

void ContactBook::operator-=(ContactBook& book){
  for (int i = 0; i < book.contacts.size(); i++) {
    ContactBook::Remove(*book.contacts[i]);
  }
};

ContactBook ContactBook::operator-(ContactBook& book1){
  ContactBook temp = *this;
    for (int i = 0; i < book1.contacts.size(); i++) {
      temp.Remove(*book1.contacts[i]);
    }
    return temp;
};

bool ContactBook::operator==(ContactBook& book){
  if(contacts.size() == book.contacts.size()){
    for(int i = 0; i < contacts.size(); i++){
      if (book.Find(contacts[i] -> getName()) == nullptr){
        return false;
      }
    }
    return true;
  }
}

bool ContactBook::operator!=(ContactBook& book){
  if(contacts.size() == book.contacts.size()){
    for(int i = 0; i < contacts.size(); i++){
      if (book.Find(contacts[i] -> getName()) == nullptr){
        return true;
      }
    }
    return false;
  }
}