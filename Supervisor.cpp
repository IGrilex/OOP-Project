#include<iostream>

#include "Supervisor.h"

using namespace std;

Supervisor::Supervisor(string firstName,string lastName,string city,int debt,shapes maskShape):
    User(firstName,lastName,city,debt){
        this->maskShape=maskShape;
};
Supervisor::Supervisor(){};

void Supervisor::setMaskShape(shapes maskShape){
    this->maskShape=maskShape;
};

shapes Supervisor::getMaskShape(){
    return this->maskShape;
};

void Supervisor::print(){
    cout<<firstName<<" "<<lastName<<",debt="<<debt<<",maskShape=";
    switch(maskShape){
        case rectangle:
            cout<<"rectangle\n";
            break;
        case triangle:
            cout<<"triangle\n";
            break;
        case circle:
            cout<<"circle\n";
            break;
    }
}
