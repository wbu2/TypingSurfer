#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    start_background.load("start.jpg");
    game_background.load("game.jpg");
    car_image.load("car.png");
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
    }
    if(current_state == RUNNING){
        user_input += (char) key;
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
    
   game_background.draw(0, 0, 1024, 768);

    font.drawStringCentered(words[0], ofGetWindowHeight(), ofGetWindowWidth()/ 2);
    font.drawStringCentered(words[1], ofGetWindowHeight() / 1.5, ofGetWindowWidth()/ 2);
    font.drawStringCentered(words[2], ofGetWindowHeight()/3.2, ofGetWindowWidth()/ 2);

    default_font.drawString(user_input, ofGetWindowWidth()/5, ofGetWindowHeight() / 2);
    
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

