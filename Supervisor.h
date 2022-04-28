#ifndef SUPERVISOR
#define SUPERVISOR

#include "User.h"
#include "Player.h"
#include "Settings.h"
#include "Random.h"

using namespace std;

class Supervisor : public User{
private:
    shapes maskShape;

public:
    Supervisor(string firstName,string lastName,string city,int debt,shapes maskShape);
    Supervisor();

    void setMaskShape(shapes maskShape);
    shapes getMaskShape();

    void print();
};

#endif // SUPERVISOR
