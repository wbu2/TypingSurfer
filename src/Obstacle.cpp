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
