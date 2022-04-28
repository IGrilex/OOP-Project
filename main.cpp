#include <iostream>

#include "Games.h"

using namespace std;

template <class X>
void printSomething(X x){
    cout<<"\nInput is of ";
    if(sizeof(X)==sizeof(int)){
        cout<<"integer type\n";
    }else if(sizeof(X)==sizeof(char)){
        cout<<"character type\n";
    }
}

int main(void)
{
    Games squidGame;
    squidGame.viewWiner();

    printSomething<int>(10);
    printSomething<char>('c');

}
