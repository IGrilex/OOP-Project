#include<iostream>

#include "User.h"

using namespace std;

User::User(string firstName,string lastName,string city,int debt){
    this->firstName=firstName;
    this->lastName=lastName;
    this->city=city;
    this->debt=debt;
};
User::User(){};

void User::setFirstName(string firstName){
    this->firstName=firstName;
};
void User::setLastName(string lastName){
    this->lastName=lastName;
};
void User::setCity(string city){
    this->city=city;
};
void User::setDebt(int debt){
    this->debt=debt;
};

string User::getFirstName(){
    return this->firstName=firstName;
};
string User::getLastName(){
    return this->lastName=lastName;
};
string User::getCity(){
    return this->city=city;
};
int User::getDebt(){
    return this->debt=debt;
};
