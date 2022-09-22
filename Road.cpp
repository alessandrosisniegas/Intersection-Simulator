// Alessandro Sisniegas
// 04-11-22
#include <iostream>
#include <string>
#include "Road.h"

using namespace std;

// ctor initializing private data members
// check Road.h for each data member's functions
Road::Road() {
carsInLine = 0;
carsOutLine = 0;
light = RED;
}

int Road::carsWaiting() {
    return carsInLine;
}

int Road::carsThrough() {
    return carsOutLine;
}

void Road::carsIn(int change) {
    carsInLine += change;
    if (carsInLine < 0) {
        carsInLine = 0;
    }
}

void Road::carsOut(int change) {
    carsOutLine += change;
    carsInLine -= change;
}

Color Road::lightColor() {
    return light;
}

void Road::changeLight() {
    if (light == RED) {
        light = GREEN;
    } else {
        light = RED;
    }
}