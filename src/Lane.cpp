#include "Lane.h"

ofVec2f Lane::GetPosition(){
    return position;
}

string Lane::GetWord(){
    return word;
}

void Lane::SetWord(string input){
    word = input;
}

bool Lane::HasObstacle(){
    return has_obstacle;
}

void Lane::ChangeObstacle(bool b){
    has_obstacle = b;
}
