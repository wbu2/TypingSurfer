
#include "ofMain.h"

class Obstacle{
private:
    ofVec2f position;
    int lane;
    ofImage image;
    double speed;
public:
    ofVec2f GetPosition();
    int GetLane();
    void SetLane(int num);
    void SetPosition(int x, int y);
    ofImage GetImage();
    void SetImage(ofImage image);
    bool ReachedHalfway();
    bool ReachedEnd();
    void SetSpeed(double num);
    double GetSpeed();
};
