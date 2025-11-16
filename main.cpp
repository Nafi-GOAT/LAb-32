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
                    lanes[lane].push_front();

                    operations.push_back(
                        "Lane " + to_string(lane + 1) + " Paid: " +
                        "[" + to_string(leaving.year) + " " + leaving.manufacturer +
                        " (" + to_string(leaving.id) + ")]"
                    );
                }
            }

                        else if (roll < PROB_PAY + PROB_JOIN) {
                Car newcomer;
                lanes[lane].push_back(newcomer);

                operations.push_back(
                    "Lane " + to_string(lane + 1) + " Joined: " +
                    "[" + to_string(newcomer.year) + " " + newcomer.manufacturer +
                    " (" + to_string(newcomer.id) + ")]"
                );
            }
else {
                if (lane < NUM_LANES - 1 && !lanes[lane].empty()) {
                    Car switchingCar = lanes[lane].back();
                    lanes[lane].pop_back();
                    lanes[lane + 1].push_back(switchingCar);

                    operations.push_back(
                        "Lane " + to_string(lane + 1) + " to Lane " +
                        to_string(lane + 2) + " Switched: " +
                        "[" + to_string(switchingCar.year) + " " +
                        switchingCar.manufacturer + " (" +
                        to_string(switchingCar.id) + ")]"
                    );
                }
            }
        }

                for (const string &op : operations) {
            cout << op << endl;
        }

        cout << "\nQueues after time " << timeStep << ":\n";
        for (int i = 0; i < NUM_LANES; i++) {
            cout << "Lane " << i + 1 << ":\n";
            for (Car &c : lanes[i]) c.print();
            cout << endl;
        }

}
return 0;
}
