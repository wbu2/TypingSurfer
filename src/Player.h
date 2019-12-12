#pragma once
#include "ofMain.h"

class Player{
private:
    //0 = left, 1= middle, 2 = right
    //player starts in the middle lane
    int lane = 1;
    ofVec2f position;
    ofImage image;
public:
    int GetLane();
    void SetLane(int num);
    ofVec2f GetPosition();
    void SetPosition(int x, int y);
    ofImage GetImage();
    void SetImage(ofImage image);
    void Reset();
};
