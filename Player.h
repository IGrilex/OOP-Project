#ifndef PLAYER
#define PLAYER

#include "User.h"
#include "Settings.h"
#include "Random.h"

using namespace std;

class Player : public User{
private:
    int number;
    int weight;
    bool alive;

public:
    Player(string firstName,string lastName,string city,int debt,int weight,int number);
    Player();

    void setNumber(int weight);
    void setWeight(int weight);
    void setAlive(bool alive);

    int getNumber();
    int getWeight();
    bool isAlive();

    void print();
};

#endif // PLAYER
