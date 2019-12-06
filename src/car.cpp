//
//  car.cpp
//  fantastic-finale-wbu2
//
//  Created by William Bu on 11/30/19.
//

#include "car.h"

int Car::GetLane(){
    return lane;
}

void Car::SetLane(int num){
    lane = num;
}

ofVec2f Car::GetPosition(){
    return position;
}

void Car::SetPosition(int x, int y){
    position.set(x, y);
}
