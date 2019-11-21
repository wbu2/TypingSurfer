#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    
    start_background.load("start.jpg");
    game_background.load("game.jpg");
    default_font.loadFont("joystix monospace.ttf", 70);
    small_font.loadFont("joystix monospace.ttf", 40);
    font.loadFont("joystix monospace.ttf", 20);
    
    gui.setup();
    slider.setup("position", 500, 0, 100);
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
    start_background.draw(0, 0, 1024, 768);
    
    default_font.drawString("Type Race", ofGetWindowWidth() / 6, ofGetWindowHeight() / 5);
    small_font.drawString("Press 1 to Start", ofGetWindowWidth() / 6, ofGetWindowHeight() / 4);
}

void ofApp::drawGameRunning(){
    //game_background.draw(0, 0, 1024, 768);
    
    font.drawStringCentered("Table", ofGetWindowHeight()/4, ofGetWindowWidth()/ 3);
}
