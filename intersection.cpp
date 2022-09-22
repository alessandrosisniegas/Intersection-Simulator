// Alessandro Sisniegas
// 04-11-22
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include "Road.h"

using namespace std;

int main() {
    Road north;
    Road south;
    Road east;
    Road west;
    string Ticks;
    string userFile;
    ifstream file;
    int numTicks = 0;
    unsigned int i = 0;

    // extracting and opening file
    // converting first string in file to an int and storing in numticks
    cin >> userFile;
    file.open(userFile);
    getline(file, Ticks);
    numTicks = stoi(Ticks);

    // where all other file data after first line will be stored
    // each line in file will correspond to the same number of index
    vector<string> fileTicks(numTicks);

    north.changeLight();
    south.changeLight();

    // first loop iterates per second
    // extracts file data and stored in vector at 'i'
    // each digit in the 4 digit number will correspond to it's one class (nesw)
    // digit will be added to cars in line for its correct class
    for (i = 0; i < numTicks; ++i) {
        getline(file, fileTicks.at(i));
        north.carsIn(((fileTicks.at(i)).at(0)) - '0');
        east.carsIn(((fileTicks.at(i)).at(1)) - '0');
        south.carsIn(((fileTicks.at(i)).at(2)) - '0');
        west.carsIn(((fileTicks.at(i)).at(3)) - '0');
        // all lights change to opposite light color every 5 seconds
        // other two roads will begin letting cars out for the next 5 seconds
        if (i % 5 == 0) {
            north.changeLight();
            south.changeLight();
            east.changeLight();
            west.changeLight();
        }
        // one car will be let out per second
        if (north.lightColor() == GREEN) {
            north.carsOut(1);
            south.carsOut(1);
        } else {
            east.carsOut(1);
            west.carsOut(1);
        }
    }

    // displaying end results for each road
    cout << "The amount of cars still waiting after " << numTicks << " ticks:" << endl;
    cout << "North: " << north.carsWaiting() << endl;
    cout << "East: " << east.carsWaiting() << endl;
    cout << "South: " << south.carsWaiting() << endl;
    cout << "West: " << west.carsWaiting() << endl;

    cout << "The amount of cars through after " << numTicks << " ticks:" << endl;
    cout << "North: " << north.carsThrough() << endl;
    cout << "East: " << east.carsThrough() << endl;
    cout << "South: " << south.carsThrough() << endl;
    cout << "West: " << west.carsThrough() << endl;

    file.close();

    return 0;
}