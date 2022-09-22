// Alessandro Sisniegas
// 04-11-22
#ifndef ROAD_H
#define ROAD_H

enum Color { RED, YELLOW, GREEN };

class Road {
 private:
    int carsInLine;              // Tracks cars in line
    int carsOutLine;             // Tracks number of cars who passed through intersection
    Color light;                 // Tracks the color of the light
 public:
    Road();                      // Default ctor
    int carsWaiting();           // Returns number of cars in line
    int carsThrough();           // Returns number of cars passed through
    void carsIn(int change);     // Adds/removes cars into the line by the value of change
    void carsOut(int change);    // Removes cars from line by the value of change
    Color lightColor();          // Returns the current color of the light
    void changeLight();          // Changes the light color.
};

#endif  // ROAD_H
