#include <iostream>
#include "Car.h"
#include <cstdlib>
#include <deque>
#include <ctime>
using namespace std;    

 const int NUM_LANES = 4;
 const int INITIAL_CARS = 2;
 const int PROB_PAY = 46;              
 const int PROB_JOIN = 39;             
 const int PROB_SWITCH = 15; 



    int main() {

    srand(time(0));

    deque<Car> lanes[NUM_LANES];

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

    int timeStep = 0;

     
    while (!lane.empty()) {
        ++timeStep;
        int roll = rand() % 100;

                if (roll < PAY_PROBABILITY) {
            cout << "Time: " << timeStep << " Operation: Car paid: ";
            lane.front().print();
            cout << endl;

            lane.pop_front();
        } else {
            Car newCar;
            cout << "Time: " << timeStep << " Operation: Joined lane: ";
            newCar.print();
            cout << endl;

            lane.push_back(newCar);
        }

     // Print queue
        cout << "Queue:\n";
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
}
return 0;
}
