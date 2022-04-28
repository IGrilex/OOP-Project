#include<iostream>

#include "Player.h"
#include "Random.h"

using namespace std;

Player::Player(string firstName,string lastName,string city,int debt,int weight,int number):
    User(firstName,lastName,city,debt){
    this->weight=weight;
    this->number=number;
    this->alive=true;
};
Player::Player(){};

void Player::setNumber(int number){
    this->number=number;
};
void Player::setWeight(int weight){
    this->weight=weight;
};
void Player::setAlive(bool alive){
    this->alive=alive;
};

int Player::getNumber(){
    return this->number;
};
int Player::getWeight(){
    return this->weight;
};
bool Player::isAlive(){
    return this->alive;
};

void Player::print(){
    cout<<firstName<<" "<<lastName<<",debt="<<debt<<",weight="<<weight<<",number="<<number;
    if(alive)
        cout<<",alive\n";
    else
        cout<<",dead\n";
};
