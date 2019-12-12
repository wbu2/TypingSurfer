#include <Obstacle.h>
#include <Constants.h>

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
    int halfway = constants::kMainWindowHeight / 2;
    return position.y > halfway && position.y < halfway + 5;
}

bool Obstacle::ReachedEnd(){
    int end = constants::kMainWindowHeight;
    return position.y > end;
}

void Obstacle::SetSpeed(double num){
    speed = num;
}

double Obstacle::GetSpeed(){
    return speed;
}
