#pragma once
#include "ofMain.h"

class Lane {

private:
    ofVec2f position;
    string word;
    bool has_obstacle;
    
public:
    ofVec2f GetPosition();
    string GetWord();
    void SetWord(string input);
    bool HasObstacle();
    void ChangeObstacle(bool b);
};
