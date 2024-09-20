#include <iostream>
#include <vector>
#include "ContactBook.h"

// FREEZE CODE BEGIN
int main() {
    std::vector<Contact*> contacts;
    Contact John("John", "123-456-7890");
    contacts.push_back(&John);
    Contact Jane("Jane", "987-654-3210");
    contacts.push_back(&Jane);
    Contact Mary("Mary", "234-567-8901");
    contacts.push_back(&Mary);
    Contact Peter("Peter", "345-678-9012");
    contacts.push_back(&Peter);
    Contact Linda("Linda", "456-789-0123");
    contacts.push_back(&Linda);
    Contact Susan("Susan", "567-890-1234");
    contacts.push_back(&Susan);
    Contact David("David", "678-901-2345");
    contacts.push_back(&David);
    Contact Johnny("Johnny", "789-012-3456");
    contacts.push_back(&Johnny);
    Contact Johnathan("Johnathon", "890-123-4567");
    contacts.push_back(&Johnathan);
    Contact Johnfart("Johnfart", "901-234-5678");
    contacts.push_back(&Johnfart);
    Contact Xander("Xander", "012-345-6789");
    contacts.push_back(&Xander);
    Contact Johnson("Johnson", "123-456-7890");
    contacts.push_back(&Johnson);
    Contact Albert("Albert", "234-567-8901");
    contacts.push_back(&Albert);
    Contact Alberta("Alberta", "345-678-9012");
    contacts.push_back(&Alberta);
    Contact Fredrickson("Fredrickson", "456-789-0123");
    contacts.push_back(&Fredrickson);
    Contact Goose("Goose", "567-890-1234");
    contacts.push_back(&Goose);
    Contact Ronald("Ronald", "678-901-2345");
    contacts.push_back(&Ronald);
    Contact Bill("Bill", "789-012-3456");
    contacts.push_back(&Bill);
    Contact Theodore("Theodore", "890-123-4567");
    contacts.push_back(&Theodore);
    Contact Simpleton("Simpleton", "901-234-5678");
    contacts.push_back(&Simpleton);
    
    Contact test1("Roland", "456-789-0123");
    Contact test2("Andres", "987-654-3210");
    Contact test3("George", "234-567-8901");
    Contact test4("Lily", "345-678-9012");
    Contact test5("Justin", "123-456-7890");

    int option;
    std::cin >> option;
    // FREEZE CODE END
    if (option == 0) {
        //your own testing 
        //you can use the above example contacts
    }
    // FREEZE CODE BEGIN
    else if (option == 1) {          //testing Add, Display, Find
        ContactBook ContactBook1;
        ContactBook1.Add(test1);
        ContactBook1.Add(test2);
        ContactBook1.Add(test3);
        ContactBook1.Add(test4);
        ContactBook1.Add(test5);
        ContactBook1.Display();
        if (ContactBook1.Find("987-654-3210") == &test2) {
          std::cout << "sucess" << std::endl;
        } 
        if (ContactBook1.Find("George") == &test3) {
          std::cout << "sucess" << std::endl;
        }
        if (ContactBook1.Find("Doesnt-Exist") == nullptr) {
          std::cout << "sucess" << std::endl;
        }
      
    }
    else if (option == 2) {         //testing Add, Remove, Display
        ContactBook ContactBook1;
        ContactBook1.Add(test1);
        ContactBook1.Add(test2);
        ContactBook1.Add(test3);
        ContactBook1.Add(test4);
        ContactBook1.Add(test5);
        ContactBook1.Remove(test1);
        ContactBook1.Remove(test3);
        ContactBook1.Remove(test5);
        ContactBook1.Display();
    }
    else if (option == 3) {         //testing AddContacts, Display
        ContactBook ContactBook1;
        ContactBook1.AddContacts(contacts);
        ContactBook1.Display(); 
    }
    else if (option == 4) {         //testing Alphabetize (simple), Display
        ContactBook ContactBook1;
        ContactBook1.Add(test1);
        ContactBook1.Add(test2);
        ContactBook1.Add(test3);
        ContactBook1.Add(test4);
        ContactBook1.Add(test5);
        ContactBook1.Alphabetize();
        ContactBook1.Display();
    }
    else if (option == 5) {         //testing Alphabetize (hard), Display 
        ContactBook ContactBook1;
        ContactBook1.AddContacts(contacts);
        ContactBook1.Alphabetize();
        ContactBook1.Display();
    }
    else if (option == 6) {         //testing addition operators, Display
        ContactBook ContactBook1;
        ContactBook ContactBook2;
        ContactBook ContactBook3;
        ContactBook ContactBook4;

        ContactBook1+=test1;
        ContactBook1+=test2;
        ContactBook1+=test3;        //this should be easy enough to follow along 
        ContactBook1.Display();
        
        ContactBook2+=test4;
        ContactBook2+=test5;
        ContactBook2.Display();

        ContactBook3 = ContactBook1 + ContactBook2;
        ContactBook3.Display();

        ContactBook4 += ContactBook1;
        ContactBook4 += ContactBook2;
        ContactBook4.Display();
    }
    else if (option == 7) {         //testing subtraction operators Display
        ContactBook ContactBook1;
        ContactBook FullBook;
        ContactBook ContactBook2;
        ContactBook ContactBook3;

        FullBook.Add(test1);
        FullBook.Add(test2);
        FullBook.Add(test3);
        FullBook.Add(test4);
        FullBook.Add(test5);

        ContactBook1 = FullBook;
        ContactBook2 = FullBook;

        ContactBook1-=test1;
        ContactBook1-=test3;
        ContactBook1-=test5;
        ContactBook1.Display();

        ContactBook2 = FullBook - ContactBook1;
        ContactBook2.Display(); 

        ContactBook3 = FullBook;
        ContactBook3 -= ContactBook1;
        ContactBook3.Display();
    }
    else if (option == 8) {         //testing equality operators Display
        ContactBook ContactBook1;
        ContactBook ContactBook2;
        ContactBook1.AddContacts(contacts);
        ContactBook1.Alphabetize();
        ContactBook2.AddContacts(contacts);

        if (ContactBook1 == ContactBook2) 
            std::cout << "Equal" << std::endl;
        else 
            std::cout << "Not Equal" << std::endl;

        if (ContactBook1 != ContactBook2) 
            std::cout << "Not Equal" << std::endl;
        else 
            std::cout << "Equal" << std::endl;


        ContactBook1.Remove(Alberta);

        if (ContactBook1 == ContactBook2) 
            std::cout << "Equal" << std::endl;
        else 
            std::cout << "Not Equal" << std::endl;

        if (ContactBook1 != ContactBook2) 
            std::cout << "Not Equal" << std::endl;
        else 
            std::cout << "Equal" << std::endl;
    }
    return 0;
}
// FREEZE CODE END