/*
Author: Oliver Schwab
Class: CSS 342 C
Professor: Dong Si
Assignment: Lab 2
Program Description:
GreedyRobot receives coordinates from the user 
and then seeks all possible paths to another set 
of coordinates using recursion.
*/


#ifndef GREEDY_ROBOT
#define GREEDY_ROBOT
#include <string>
#include <iostream>

using namespace std;

class GreedyRobot {
    unsigned int nCount;
    unsigned int eCount;
    unsigned int wCount;
    unsigned int sCount;
    string path;
    int x;
    int y;

public:
    //Default constructor places robot at 0,0.
    GreedyRobot();
    //Parameterized constructor places robot at coordinates.
    GreedyRobot(int x, int y);
    //Destructor
    ~GreedyRobot();

    //Find shortest path(s) algorithm using 
    //coordinates of treasure.
    string findPaths(int x, int y);

    //Set current coordinates of robot.
    void setCoordinates(int x, int y);

    //get x coordinate
    int getX() const;
    //get y coordinate
    int getY() const;

};

#endif //GREEDY_ROBOT