#include <iostream>
using namespace std;


int main()
{
    std::cout << "Hello, World!" << std::endl;
    return 0;
}

//shallow copy - 5 copied has 5 memory locations
//deep copy - 5 copied has 10 memory locations total
//create space for array, then for loop that copies from first to second array

class LineItem
{
    string _name;
    string _description;
    int _quantity;
    float _price;
public:
    LineItem(const LineItem& otherObject);
    LineItem& operator=(const LineItem& otherObject);
    ~LineItem(); //Destructor, need to figure out

};

LineItem::LineItem(const LineItem& otherObject)
{
    //copy constructor
}

LineItem& LineItem::operator=(const LineItem& otherObject)
{
    //copy assignment constructor
    _name = otherObject._name;
    _description = otherObject._description;
    _quantity = otherObject._quantity;
    _price = otherObject._price;

    return *this;
}

LineItem::~LineItem()
{
    delete _name;
}


