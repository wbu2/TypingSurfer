#include "Lane.h"

Lane::Lane(){
    
}

bool Lane::ReachedEnd(){
    return true;
}

ofVec2f Lane::GetPosition(){
    return position;
}

string Lane::GetWord(){
    return word;
}

void Lane::SetWord(string input){
    word = input;
}
