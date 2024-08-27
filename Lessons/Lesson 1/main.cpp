#include <iostream>
#include <string>
#include "functions.cpp"

using namespace std;

int score ;
int players ;
string name = "Mark";

int round(float num);

int main()
{
    cout << "Type a score : ";
    cin >> score;

    cout << "Your score is ";
    cout << score << endl;

    cout << "Type the number of players : ";
    cin >> players;

    cout << "The number of players is : ";
    cout << score << endl;

    cout << "The points per player is on average ";
    std::cout << PointsPerPlayer(score,players) << std::endl;
    std::cout << "Hello " + name << std::endl;

    return 0;
}



