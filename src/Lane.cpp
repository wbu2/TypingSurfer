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
