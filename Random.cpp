#include <iostream>
#include <algorithm>
#include <array>
#include <random>
#include <chrono>
#include <bits/stdc++.h>

#include "Random.h"

using namespace std;

void Random::shuffleNumbers(int numbers[], int length){

    unsigned seed = chrono::system_clock::now().time_since_epoch().count();

    shuffle(numbers, numbers + length, default_random_engine(seed));
}

int Random::randomNumber(int minNumber,int maxNumber){
    return rand()%(maxNumber-minNumber + 1) + minNumber;
}
