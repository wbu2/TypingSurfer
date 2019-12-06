#pragma once
#include "ofMain.h"

class Lane {

private:
    ofVec2f position;
    string word;
    
public:
    bool ReachedEnd();
    ofVec2f GetPosition();
    string GetWord();
    void SetWord(string input);
};
