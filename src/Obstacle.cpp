#include <Obstacle.h>


ofVec2f Obstacle::GetPosition(){
    return position;
}
int Obstacle::GetLane(){
    return lane;
}
void Obstacle::SetLane(int num){
    lane = num;
}
void Obstacle::SetPosition(int x, int y){
    position.set(x,y);
}

ofImage Obstacle::GetImage(){
    return image;
}

void Obstacle::SetImage(ofImage img){
    image = img;
}

bool Obstacle::ReachedHalfway(){
    int halfway = ofGetWindowHeight() / 2;
    return position.y > halfway && position.y < halfway + 5;
}

bool Obstacle::ReachedEnd(){
    int end = ofGetWindowHeight();
    return position.y > end;
}

void Obstacle::SetSpeed(double num){
    speed = num;
}

double Obstacle::GetSpeed(){
    return speed;
}
