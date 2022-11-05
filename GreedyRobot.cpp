#include "GreedyRobot.h"

GreedyRobot::GreedyRobot() {
    eCount = 0;
    nCount = 0;
    wCount = 0;
    sCount = 0;
    x = 0;
    y = 0;
}

GreedyRobot::GreedyRobot(int x, int y) {
    eCount = 0;
    nCount = 0;
    this->x = x;
    this->y = y;
}

GreedyRobot::~GreedyRobot() {}

string GreedyRobot::findPaths(int x, int y) {
    //direction count of current step
    int e = eCount;
    int n = nCount;
    int s = sCount;
    int w = wCount;
    //Base case
    //If the treasure is reached then return
    //the path.
    if (x == this->x && y == this->y) {
       cout << path << endl;
    }
    /*
    In each case, a direction is incremented
    and all other direction counts are set to 0.
    Then, the direction letter is added to the path
    string and a recursive call is made with an x or y
    value being modified in parameter.

    When recursion is returning the path string back to the 
    original recursive call, the count integers are 
    set to the count from the time of that specific 
    recursive call. This allows for the robot to 
    change directions and try other possible paths.
    */
    //Moving east
    if (x > this->x && e < 2) {
        //east count incremented
        ++eCount;
        nCount = 0;
        wCount = 0;
        sCount = 0;
        path+="E";
        //recursive call made with x-1
        findPaths(x-1, y);
        path = path.substr(0, path.length()-1);
        //Reset to prior count.
        eCount = e;
        nCount = n;
        sCount = s;
        wCount = w;
    }
    //Moving north
    if (y > this->y && n < 2) {
        //North count incremented.
        ++nCount;
        eCount = 0;
        wCount = 0;
        sCount = 0;
        //North letter added to path.
        path+="N";
        findPaths(x, y-1);
        path = path.substr(0, path.length()-1);
        //Reset to prior count.
        nCount = n;
        eCount = e;
        wCount = w;
        sCount = s;
    }
    //Moving west
    if (x < this->x && w < 2) {
        //West count incremented.
        ++wCount;
        eCount = 0;
        nCount = 0;
        sCount = 0;
        //West letter added to path.
        path+="W";
        findPaths(x+1, y);
        path = path.substr(0, path.length()-1);
        //Reset to prior count.
        nCount = n;
        eCount = e;
        wCount = w;
        sCount = s;
    }
    //Moving south
    if (y < this->y && s < 2) {
        //South count incremented.
        ++sCount;
        eCount = 0;
        wCount = 0;
        nCount = 0;
        //South letter added to path.
        path+="S";
        findPaths(x, y+1);
        path = path.substr(0, path.length()-1);
        //Reset to prior count.
        nCount = n;
        eCount = e;
        wCount = w;
        sCount = s;
    }
    return path;
}
void GreedyRobot::setCoordinates(int x, int y) {
    this->x = x;
    this->y = y;
}
int GreedyRobot::getX() const {
    return x;
}

int GreedyRobot::getY() const {
    return y;
}

int main() {
    //Main for testing
    GreedyRobot g1;
    cout << "||GreedyRobot Treasure Finder||" << endl;
    cout << "Enter four integers" << endl;
    cout << "The first two numbers will be the starting coordinates" << endl;
    cout << "The last two will be the treasure's location" << endl;
    cout << "(Ex. 1 2 3 4 means start at (1, 2) and find treasure at (3, 4))" << endl;
    int a, b, c, d;
    cin >> a >> b >> c >> d;;
    g1.setCoordinates(a, b);
    cout << endl;
    cout << "GreedyRobot's paths: " << endl;
    cout << g1.findPaths(c, d) << endl;

}

