#include "Player.h"

int Player::GetLane(){
    return lane;
}

void Player::SetLane(int num){
    lane = num;
}

ofVec2f Player::GetPosition(){
    return position;
}

void Player::SetPosition(int x, int y){
    position.set(x, y);
}

ofImage Player::GetImage(){
    return image;
}

void Player::SetImage(ofImage img){
    image = img;
}
