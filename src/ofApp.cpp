#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    start_background.load("start.jpg");
    game_background.load("game.jpg");
    
    player_car.load("romeo.png");
    car_gt.load("gt.png");
    car_romeo.load("romeo.png");
    car_beamer.load("beamer.png");
    car_sonata.load("sonata.png");
    car_corvette.load("corvette.png");
    
    car_images.push_back(car_gt);
    car_images.push_back(car_romeo);
    car_images.push_back(car_beamer);
    car_images.push_back(car_sonata);
    car_images.push_back(car_corvette);
    
    first_frame.load("frame-1.jpg");
    second_frame.load("frame-2.jpg");
    third_frame.load("frame-3.jpg");
    
    default_font.load("joystix monospace.ttf", 70);
    small_font.load("joystix monospace.ttf", 30);
    centered_font.load("joystix monospace.ttf", 10);
    
    user_input = "";
    
    reader.ReadWords("input.txt");
    
    
    
    for(int i = 0; i< kNumLanes; ++i){
        Lane l;
        lanes.push_back(l);
    }
    
    
    
}

//--------------------------------------------------------------
void ofApp::update(){
    if(current_state == RUNNING){
        obstacle_speed += 0.2;
        
    }
}

//--------------------------------------------------------------
void ofApp::draw(){
    
    switch (current_state) {
        case START_SCREEN:
            
            drawGameStart();
            break;
        case RUNNING:
            drawGameRunning();
            break;
        case ENDED:
            
            break;
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
    
    drawFrames(frame_counter);
    
    ofDrawLine(ofGetWindowWidth()/3, 0 , ofGetWindowWidth()/3, ofGetWindowHeight());
    ofDrawLine(2 * (ofGetWindowWidth()/ 3), 0, 2 * (ofGetWindowWidth()/3), ofGetWindowHeight());
    
    drawLane();
    drawCar(player.GetLane());
    
    for(int i = 1; i <= obstacles.size(); ++i){
        drawObstacles(i, obstacle_speed, car_beamer);
        if(obstacles[i-1].GetPosition().y > player.GetPosition().y){
            current_state = ENDED;
        }
        cout << obstacles[i-1].GetPosition().y << endl;
        cout << player.GetPosition().y << endl;
    }
    
    for(int i = 1; i<= kNumLanes; ++i){
        drawObstacles(i, obstacle_speed, car_gt);
        if(ObstacleIntersects()){
            current_state = ENDED;
        }
    }
    /*drawObstacles(1, obstacle_speed, car_beamer);
    drawObstacles(2, obstacle_speed, car_gt);
    drawObstacles(3, obstacle_speed, car_corvette);*/
    
    
}

void ofApp::drawCar(int lane){
    switch (lane) {
        case 0:
            player.SetPosition(ofGetWindowWidth()/10, 5* ofGetWindowHeight()/7);
            player_car.draw(ofGetWindowWidth()/10,  5* ofGetWindowHeight()/7 , ofGetWindowWidth()/5,ofGetWindowWidth()/5);
            break;
        case 1:
            player.SetPosition(4.5 * (ofGetWindowWidth()/10), 5* ofGetWindowHeight()/7);
            player_car.draw(4.5 * (ofGetWindowWidth()/10),  5* ofGetWindowHeight()/7 , ofGetWindowWidth()/5,ofGetWindowWidth()/5);
            break;
        case 2:
            player.SetPosition(7.8 * (ofGetWindowWidth()/10),5* ofGetWindowHeight()/7);
            player_car.draw(7.8 * (ofGetWindowWidth()/10),  5* ofGetWindowHeight()/7 , ofGetWindowWidth()/5,ofGetWindowWidth()/5);
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
    int rng = ofRandom(reader.GetFileWords().size());
    
    if(lanes[0].GetWord().size() == 0){
        for(int i = 0; i<lanes.size(); ++i){
            lanes[i].SetWord(reader.GetFileWords()[ofRandom(reader.GetFileWords().size())]);
            drawDisplayWords(i+1, lanes[i].GetWord());
            drawUserInput(player.GetLane());
        }
    }else{
        for(int i = 0; i<lanes.size(); ++i){
            drawUserInput(player.GetLane());
            drawDisplayWords(i, lanes[i].GetWord()); //draw words user must type
            if(lanes[i].GetWord() == user_input){
                user_input.clear();
                lanes[i].SetWord(reader.GetFileWords()[ofRandom(reader.GetFileWords().size())]);
                player.SetLane(i); //change car lane
            }
        }
    }
}

void ofApp::drawDisplayWords(int lane, string word){
    ofSetColor(0, 0, 0);
    switch (lane) {
        case 0:
            centered_font.drawStringCentered(word, ofGetWindowWidth() / 6, ofGetWindowHeight() - 15);
            break;
        case 1:
            centered_font.drawStringCentered(word, 3 * (ofGetWindowWidth() / 6), ofGetWindowHeight() - 15);
            break;
        case 2:
            centered_font.drawStringCentered(word, 5 * (ofGetWindowWidth() / 6), ofGetWindowHeight() - 15);
            break;
    }
    ofSetColor(255,255,255);
}

void ofApp::drawUserInput(int lane){
    ofSetColor(0, 0, 0);
    switch (lane) {
        case 0:
            centered_font.drawStringCentered(user_input, ofGetWindowWidth() / 6, ofGetWindowHeight() - 30);
            break;
        case 1:
            centered_font.drawStringCentered(user_input,  3 * (ofGetWindowWidth() / 6), ofGetWindowHeight() - 30);
            break;
        case 2:
            centered_font.drawStringCentered(user_input, 5 * (ofGetWindowWidth() / 6), ofGetWindowHeight() - 30);
            break;
    }
    ofSetColor(255,255,255);
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

void ofApp::drawObstacle(Obstacle o){
    if(o.GetPosition().x != 0){
        o.GetImage().draw(o.GetPosition(), ofGetWindowHeight()/5, ofGetWindowHeight()/5);
    }
    
}

bool ofApp::Collided(Obstacle o){
    if(o.GetLane() == player.GetLane()){
        return o.GetPosition().y > player.GetPosition().y;
    }
    return false;
}

