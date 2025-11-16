#include <iostream>
#include "Car.h"
#include <cstdlib>
#include <deque>
#include <ctime>
#include <vector>
using namespace std;    

 const int NUM_LANES = 4;
 const int INITIAL_CARS = 2;
 const int PROB_PAY = 46;              
 const int PROB_JOIN = 39;             
 const int PROB_SWITCH = 15; 


int main() {

    srand(time(0));

    deque<Car> lanes[NUM_LANES];

        for (int i = 0; i < NUM_LANES; i++) {
        for (int j = 0; j < INITIAL_CARS; j++) {
            lanes[i].push_back(Car());
        }
    }

    cout << "Initial queue:\n";
    for (int i = 0; i < NUM_LANES; i++) {
        cout << "Lane " << i + 1 << ":\n";
        for (Car &c : lanes[i]) c.print();
        cout << endl;
    }

        for (int timeStep = 1; timeStep <= 20; timeStep++) {

        cout << "Time: " << timeStep << ":\n";

        vector<string> operations;

        for (int lane = 0; lane < NUM_LANES; lane++) {

            int roll = rand() % 100;

          if (roll < PROB_PAY) {
                if (!lanes[lane].empty()) {
                    Car leaving = lanes[lane].front();
                    lanes[lane].pop_front();

                    operations.push_back("Lane " + to_string(lane + 1) + " Paid: " +
                                         "[" + to_string(leaving.getYear()) + " " +
                                         leaving.getMake() + " (" +
                                         to_string(leaving.getTransponder()) + ")]");
                }
            }

            else if (roll < PROB_PAY + PROB_JOIN) {
                Car newcomer;
                lanes[lane].push_back(newcomer);
                operations.push_back("Lane " + to_string(lane + 1) + " Joined: " +
                                     "[" + to_string(newcomer.getYear()) + " " +
                                     newcomer.getMake() + " (" +
                                     to_string(newcomer.getTransponder()) + ")]");
            }

            else {
                if (!lanes[lane].empty()) {
                    int targetLane = rand() % NUM_LANES;

                    // ensure switch lane is different
                    while (targetLane == lane) {
                        targetLane = rand() % NUM_LANES;
                    }

                    Car switching = lanes[lane].back();
                    lanes[lane].pop_back();
                    lanes[targetLane].push_back(switching);

                    operations.push_back(
                        "Lane " + to_string(lane + 1) + " Switched to Lane " +
                        to_string(targetLane + 1) + ": [" +
                        to_string(switching.getYear()) + " " +
                        switching.getMake() + " (" +
                        to_string(switching.getTransponder()) + ")]");
                }
            }
        }

                for (string &o : operations) 
                cout << o << endl;

        // Print full plaza state after operations
        for (int lane = 0; lane < NUM_LANES; lane++) {
            cout << "Lane " << lane + 1 << " Queue:\n";

            if (lanes[lane].empty()) {
                cout << "  empty\n";
            } else {
                for (Car &c : lanes[lane]) c.print();
            }
            cout << endl;
        }
return 0;
}
