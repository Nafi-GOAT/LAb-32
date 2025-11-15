#include <iostream>
#include "Car.h"
#include <cstdlib>
#include <ctime>
using namespace std;    

int main () {
    const int INITIAL_CARS = 2;
    const int PAY_PROBABILITY = 55;

    srand(time(0));

    deque<Car> lane;

    for (int i = 0; i < INITIAL_CARS; ++i){
        lane.push_back(Car());
    }

    cout << "Initial queue:\n";
    if (lane.empty()) {
        cout << "Empty\n";
    } else {
        for (Car &c : lane) {
            cout << "    ";
            c.print();
            cout << endl;
        }
    }
    cout << endl;

    int time = 0;

     
    while (!lane.empty()) {
    +++ timeStep = 1;

    int roll = rand() % 100;
}
