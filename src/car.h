#pragma once
#include "ofMain.h"

class Car{
private:
    int lane = 2; //1 = left, 2= middle, 3 = right
    ofVec2f position;
public:
    int GetLane();
    void SetLane(int num);
    ofVec2f GetPosition();

};
