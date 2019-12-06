#pragma once
#include "ofMain.h"

class Obstacle{
private:
    ofVec2f position;
    int lane;
public:
    ofVec2f GetPosition();
    int GetLane();
    void SetLane();
    
};
