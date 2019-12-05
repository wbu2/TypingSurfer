#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    start_background.load("start.jpg");
    game_background.load("game.jpg");
    car_image.load("car.png");
    first_frame.load("first-frame.png");
    second_frame.load("second-frame.png");
    third_frame.load("third-frame.png");
    default_font.load("joystix monospace.ttf", 70);
    small_font.load("joystix monospace.ttf", 40);
    centered_font.load("joystix monospace.ttf", 10);
    
    user_input = "";
    
    reader.ReadWords("input.txt");
    
}

//--------------------------------------------------------------
void ofApp::update(){
    
}

//--------------------------------------------------------------
void ofApp::draw(){
    if(current_state == START_SCREEN){
        drawGameStart();
    }
    if(current_state == RUNNING){
        drawGameRunning();
    }
    
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    if(current_state == START_SCREEN && key == '1'){
        current_state = RUNNING;
    }else if(current_state == RUNNING){
        user_input += (char) key;
        if(key == OF_KEY_BACKSPACE){
            if(!user_input.empty()){
                user_input.pop_back();
            }
            user_input.pop_back();
        }
    }
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){
    
}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){
    
}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){
    
}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){
    
}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){
    
}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){
    
}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){
    
}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){
    
}

//--------------------------------------------------------------

void ofApp::drawGameStart(){
    start_background.draw(0, 0, ofGetWindowWidth(), ofGetWindowHeight());
    
    default_font.drawString("Type Race", ofGetWindowWidth() / 6, ofGetWindowHeight() / 5);
    small_font.drawString("Press 1 to Start", ofGetWindowWidth() / 6, ofGetWindowHeight() / 4);
    
}

void ofApp::drawGameRunning(){
    if(frame_counter == 2){
        frame_counter = 0;
    }else{
        frame_counter++;
    }
    cout << frame_counter << endl;
    drawFrames(frame_counter);

    ofDrawLine(ofGetWindowWidth()/3, 0 , ofGetWindowWidth()/3, ofGetWindowHeight());
    ofDrawLine(2 * (ofGetWindowWidth()/ 3), 0, 2 * (ofGetWindowWidth()/3), ofGetWindowHeight());
    
    drawLane();
    drawCar(player.GetLane());
    
    
    
    cout << "end" << endl;
}


void ofApp::drawCar(int lane){
    switch (lane) {
        case 1:
            car_image.draw(ofGetWindowWidth()/10,  6* ofGetWindowHeight()/7 , ofGetWindowWidth()/8,ofGetWindowWidth()/10);
            break;
        case 2:
            car_image.draw(4.5 * (ofGetWindowWidth()/10),  6* ofGetWindowHeight()/7 , ofGetWindowWidth()/8,ofGetWindowWidth()/10);
            break;
        case 3:
            car_image.draw(7.8 * (ofGetWindowWidth()/10),  6* ofGetWindowHeight()/7 , ofGetWindowWidth()/8,ofGetWindowWidth()/10);
            break;
    }
    
}
void ofApp::drawLane(){
    /*
     assign each lane a random word
     loop through each lane words
     if word == user_input then change word and change car direction
     word count: 370103
     */
    int Random;
    
    if(lanes[0].GetWord().size() == 0){
        for(int i = 0; i<lanes.size(); ++i){
            Random = std::rand() % reader.GetFileWords().size();
            lanes[i].SetWord(reader.GetFileWords()[Random]);
            drawDisplayWords(i+1, lanes[i].GetWord());
            drawUserInput(player.GetLane());
        }
    }else{
        for(int i = 0; i<lanes.size(); ++i){
            drawUserInput(player.GetLane());
            drawDisplayWords(i, lanes[i].GetWord()); //draw words user must type
            if(lanes[i].GetWord() == user_input){
                user_input.clear();
                Random = std::rand() % reader.GetFileWords().size();
                lanes[i].SetWord(reader.GetFileWords()[Random]);
                player.SetLane(i+1); //change car lane
            }
        }
    }
}

void ofApp::drawDisplayWords(int lane, string word){
    switch (lane) {
        case 0:
            centered_font.drawStringCentered(word, ofGetWindowWidth() / 6, 3 * (ofGetWindowHeight() / 4));
            break;
        case 1:
            centered_font.drawStringCentered(word, 3 * (ofGetWindowWidth() / 6), 3 * (ofGetWindowHeight() / 4));
            break;
        case 2:
            centered_font.drawStringCentered(word, 5 * (ofGetWindowWidth() / 6), 3 * (ofGetWindowHeight() / 4));
            break;
    }
}

void ofApp::drawUserInput(int lane){
    switch (lane) {
        case 1:
            centered_font.drawStringCentered(user_input, ofGetWindowWidth() / 6, 2 * (ofGetWindowHeight() / 3));
            break;
        case 2:
            centered_font.drawStringCentered(user_input,  3 * (ofGetWindowWidth() / 6), 2 * (ofGetWindowHeight() / 3));
            break;
        case 3:
            centered_font.drawStringCentered(user_input, 5 * (ofGetWindowWidth() / 6), 2 * (ofGetWindowHeight() / 3));
            break;
    }
}

void ofApp::drawFrames(int frame){
    switch (frame) {
        case 0:
            first_frame.draw(0,0,ofGetWindowWidth(), ofGetWindowHeight());
            break;
        case 1:
            second_frame.draw(0,0,ofGetWindowWidth(), ofGetWindowHeight());
            break;
        case 2:
            third_frame.draw(0,0,ofGetWindowWidth(), ofGetWindowHeight());
            break;
    }
}

