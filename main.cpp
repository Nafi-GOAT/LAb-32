#include <iostream>
#include "Car.h"
#include <cstdlib>
#include <ctime>
using namespace std;    

int main () {
    const int NUM_CARS = 2;
    const int PAY_PROBABILITY = 55;

    srand(time(0));

    deque<Car> lane;

    for (int i = 1; i < NUM_CARS; ++i){
        lane.push_back(Car());
    }
}
