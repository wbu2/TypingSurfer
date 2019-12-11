
#include "ofMain.h"

class Lane {

private:
    ofVec2f position;
    string word;

    
public:
    ofVec2f GetPosition();
    string GetWord();
    void SetWord(string input);
    
};
