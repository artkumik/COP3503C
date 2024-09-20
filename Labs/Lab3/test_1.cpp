// FREEZE CODE BEGIN
#include <iostream>
#include <vector>
#include "ContactBook.h"

int main() {

    Contact test1("Roland", "456-789-0123");
    Contact test2("Andres", "987-654-3210");
    Contact test3("George", "234-567-8901");
    Contact test4("Lily", "345-678-9012");
    Contact test5("Justin", "123-456-7890");

    int option;
    std::cin >> option;

    if (option == 1) {         
        ContactBook ContactBook1;
        ContactBook1.Add(test1);
        ContactBook1.Add(test2);
        ContactBook1.Add(test3);
        ContactBook1.Add(test4);
        ContactBook1.Add(test5);

        ContactBook1.Display();
        std::cout << std::endl;

        if (ContactBook1.Find("987-654-3210") == &test2) {
          std::cout << "987-654-3210 found!" << std::endl;
        } 
        else {
          std::cout << "fail" << std::endl;
        }
        if (ContactBook1.Find("George") == &test3) {
          std::cout << "George found!" << std::endl;
        }
        else {
          std::cout << "fail" << std::endl;
        }
        if (ContactBook1.Find("Doesnt-Exist") == nullptr) {
          std::cout << "Doesnt-Exist not found!" << std::endl;
        }
        else {
          std::cout << "fail" << std::endl;
        }
    }
    if (option == 2) {
      ContactBook c;
      c.Add(test5);
      c.Add(test3);
      c.Add(test1);
      c.Display();
      std::cout << std::endl;
      if (c.Find("Andres") != nullptr) {
        std::cout << "Andres found?" << std::endl;
      }
      else {
        std:: cout << "Andres not found!" << std::endl;
      }
    }

    return 0;
}
// FREEZE CODE END