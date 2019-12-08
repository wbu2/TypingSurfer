#include "ofApp.h"
#include "Constants.h"

//--------------------------------------------------------------
void ofApp::setup(){
    vid_player.load("start-vid.mov");
 
    start_background.load("start.jpg");
    game_background.load("game.jpg");
    
    player_car.load("romeo.png");
    
    ofDirectory dir(constants::kCarImagePath);
    dir.listDir();
    for(int i = 0; i<dir.size(); ++i){
        ofImage img;
        img.load(constants::kCarImagePath + "/" + dir.getName(i));
        car_images.push_back(img);
    }

    first_frame.load("frame-1.jpg");
    second_frame.load("frame-2.jpg");
    third_frame.load("frame-3.jpg");
    
    default_font.load("joystix monospace.ttf", 70);
    small_font.load("joystix monospace.ttf", 30);
    centered_font.load("joystix monospace.ttf", 10);
    
    user_input = "";
    
    reader.ReadWords("input.txt");
    
    for(int i = 0; i< constants::kNumLanes; ++i){
        Lane l;
        lanes.push_back(l);
    }
    
    
    
}

//--------------------------------------------------------------
void ofApp::update(){
    switch (current_state) {
        case START_SCREEN:
            vid_player.update();
            break;
    }
    if(current_state == RUNNING){
        vid_player.stop();
        int iterator = 0;
        for(Obstacle o : current_obstacles){
            o.SetSpeed(o.GetSpeed()+0.2);
            UpdateObstacle(o);
            current_obstacles[iterator] = o;
            iterator++;
            
        }
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
    vid_player.setLoopState(OF_LOOP_NORMAL);
    vid_player.play();
    vid_player.draw(0, 0, ofGetWindowWidth(), ofGetWindowHeight());
    //start_background.draw(0, 0, ofGetWindowWidth(), ofGetWindowHeight());
    
    default_font.drawString("Type Race", ofGetWindowWidth() / 6, ofGetWindowHeight() / 5);
    small_font.drawString("Press 1 to Start", ofGetWindowWidth() / 6, ofGetWindowHeight() / 4);
    
}

void ofApp::drawGameRunning(){
    
    drawFrames(ofRandom(constants::kNumLanes));

    drawPlayer(player.GetLane());
    drawLane();
    drawRandomObstacle();
    drawScore();
    
}

void ofApp::drawPlayer(int lane){
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
            if(lanes[i].GetWord() == user_input && abs(player.GetLane() - i) < constants::kNumLanes - 1){
                user_input.clear();
                words_typed++;
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

void ofApp::drawRandomObstacle(){
    /*
     if current_obstale.size == 0
     add obstacle to random lane
     
     if reached halfway
     add new random obstacle
     else
     draw current obstacles
     */
    
    if(current_obstacles.empty()){
        Obstacle o;
        o.SetLane(ofRandom(constants::kNumLanes));
        o.SetImage(car_images[ofRandom(car_images.size())]);
        current_obstacles.push_back(o);
    }
    
    int iterator = 0;
    for(Obstacle o : current_obstacles){
        if(o.ReachedHalfway()){
            Obstacle l;
            l.SetLane(ofRandom(constants::kNumLanes));
            l.SetSpeed(0);
            l.SetImage(car_images[ofRandom(car_images.size())]);
            current_obstacles.push_back(l);
        }
        
        if(o.ReachedEnd()){
            current_obstacles.erase(current_obstacles.begin() + iterator);
        }
        
        if(Collided(o)){
            current_state = ENDED;
        }
        iterator++;

    }
    for(Obstacle o : current_obstacles){
        drawObstacle(o);
    }
    
}

void ofApp::UpdateObstacle(Obstacle &o){
    int lane = o.GetLane();
    
    int down_magnitude;
    int direction_magnitude;
    
    double x_coord;
    double y_coord;
    
    switch (lane) {
        case 0:
            down_magnitude = 34;
            direction_magnitude = 10;
            
            x_coord = ofGetWindowWidth() / 5 - direction_magnitude * o.GetSpeed();
            y_coord = down_magnitude * o.GetSpeed();
            o.SetPosition(x_coord, y_coord);
            
            if(o.ReachedEnd()){
                lanes[lane-1].ChangeObstacle(false);
                o.SetSpeed(0);
            }
            
            lanes[lane].ChangeObstacle(true);
            break;
        case 1:
            down_magnitude = 34;
            direction_magnitude = 0;
            
            x_coord = 2 * ofGetWindowWidth() / 5;
            y_coord = down_magnitude * o.GetSpeed();
            
            o.SetPosition(x_coord, y_coord);
            
            if(o.ReachedEnd()){
                lanes[lane-1].ChangeObstacle(false);
                o.SetSpeed(0);
            }
            lanes[lane].ChangeObstacle(true);
            break;
        case 2:
            down_magnitude = 34;
            direction_magnitude = 10;
            
            x_coord = 3 * ofGetWindowWidth() / 5 + direction_magnitude * o.GetSpeed();
            y_coord = down_magnitude * o.GetSpeed();
            
            o.SetPosition(x_coord, y_coord);
            
            if(o.ReachedEnd()){
                lanes[lane-1].ChangeObstacle(false);
                o.SetSpeed(0);
            }
            lanes[lane].ChangeObstacle(true);
            break;
    }
}

void ofApp::drawScore(){
    ofSetColor(0, 0, 0);
    small_font.drawString(to_string((int)ofGetElapsedTimef()/60) + "M:" + to_string((int)ofGetElapsedTimef()) + "S", 15, 30);
    small_font.drawString(to_string(words_typed) + "WORDS" , 15, 60);
    score = 10 * words_typed + ofGetElapsedTimef();
    small_font.drawString("SCORE" + to_string(score), 15, 90);
    ofSetColor(255,255,255);
}
