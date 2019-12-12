#include "ofApp.h"
#include "Constants.h"

//--------------------------------------------------------------
void ofApp::setup(){
    vid_player.load("start-vid.mov");
    
    game_end_image.load(constants::kImagePath + "/" + "game_end.png");
    
    ofDirectory dir(constants::kImagePath);
    dir.listDir();
    for(int i = 0; i < dir.size(); ++i){
        ofImage img;
        img.load(constants::kImagePath + "/" + dir.getName(i));
        if (dir.getName(i).find(constants::kCarImageLabel) != std::string::npos) {
            car_images.push_back(img);
        }
        if (dir.getName(i).find(constants::kFrameImageLabel) != std::string::npos) {
            frame_images.push_back(img);
        }
    }
    
    player.SetImage(car_images[ofRandom(car_images.size())]);
    
    small_font.load(constants::kTrueTypeFontType, constants::kSmallFontSize);
    
    small_centered_font.load(constants::kTrueTypeFontType, constants::kSmallCenterTextSize);
    medium_centered_font.load(constants::kTrueTypeFontType, constants::kMediumCenterTextSize);
    large_centered_font.load(constants::kTrueTypeFontType, constants::kLargeCenterTextSize);
    
    user_input = "";
    
    reader.ReadWords(constants::kWordFile);
    
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
        case RUNNING:
            IncreaseDifficulty();
            vid_player.stop();
            int iterator = 0;
            for(Obstacle o : current_obstacles){
                o.SetSpeed(o.GetSpeed()+constants::kObstacleSpeed);
                UpdateObstacle(o);
                current_obstacles[iterator] = o;
                iterator++;
            }
            break;
    }
}

//--------------------------------------------------------------
void ofApp::draw(){
    
    switch (current_state) {
        case START_SCREEN:
            
            DrawGameStart();
            break;
        case RUNNING:
            DrawGameRunning();
            break;
        case ENDED:
            DrawGameEnd();
            break;
    }
    
    
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    switch (current_state) {
        case START_SCREEN:
            if(key == ' '){
                current_state = RUNNING;
            }
            break;
        case RUNNING:
            user_input += (char) key;
            if(key == OF_KEY_BACKSPACE){
                user_input.pop_back(); //removes the back space character added
                user_input.pop_back(); //removes the desired last letter
            }
            break;
        case ENDED:
            if (key == 'r') {
                Reset();
                current_state = START_SCREEN;
            }
    }
}

void ofApp::DrawGameStart(){
    vid_player.setLoopState(OF_LOOP_NORMAL);
    vid_player.play();
    vid_player.draw(constants::kStartScreenVideoX, constants::kStartScreenVideoY, constants::kMainWindowWidth, constants::kMainWindowHeight);
    
    large_centered_font.drawStringCentered(constants::kGameTitle, constants::kGameTitleCenterX, constants::kGameTitleCenterCenterY);
    medium_centered_font.drawStringCentered(constants::kStartMessage, constants::kStartMessageCenterX, constants::kStartMessageCenterY);
    
}

void ofApp::DrawGameRunning(){
    
    DrawFrames(ofRandom(constants::kNumLanes));
    UpdatePlayerPosition(player.GetLane(), player);
    DrawPlayer(player.GetLane());
    DrawRandomObstacle();
    DrawLane();
    DrawScore();
    
}

void ofApp::DrawPlayer(int lane){
    ofImage player_img = player.GetImage();
    switch (lane) {
        case 0:
            player_img.draw(constants::kLeftPlayerX,  constants::kPlayerY, constants::kCarWidth,constants::kCarLength);
            break;
        case 1:
            player_img.draw(constants::kMiddlePlayerX,  constants::kPlayerY, constants::kCarWidth, constants::kCarLength);
            break;
        case 2:
            player_img.draw(constants::kRightPlayerX, constants::kPlayerY, constants::kCarWidth,constants::kCarLength);
            break;
    }
}

void ofApp::DrawLane(){
    /*
     assign each lane a random word
     loop through each lane words
     if word == user_input then change word and change car direction
     word count: 370103
     */
    int word_count = reader.GetFileWords().size();
    
    if(lanes[0].GetWord().size() == 0){
        for(int i = 0; i<lanes.size(); ++i){
            lanes[i].SetWord(reader.GetFileWords()[ofRandom(word_count)]);
            DrawDisplayWords(i, lanes[i].GetWord());
            DrawUserInput(player.GetLane());
        }
    }else{
        for(int i = 0; i<lanes.size(); ++i){
            DrawUserInput(player.GetLane());
            DrawDisplayWords(i, lanes[i].GetWord()); //draw words user must type
            if(lanes[i].GetWord() == user_input && abs(player.GetLane() - i) < constants::kNumLanes - 1){
                user_input.clear();
                words_typed++;
                lanes[i].SetWord(reader.GetFileWords()[ofRandom(word_count)]);
                player.SetLane(i); //change car lane
            }
        }
    }
}

void ofApp::DrawDisplayWords(int lane, string word){
    ofSetColor(ofColor::black);
    switch (lane) {
        case 0:
            small_centered_font.drawStringCentered(word, constants::kLeftDisplayWordCenterX, constants::kDisplayWordCenterY);
            break;
        case 1:
            small_centered_font.drawStringCentered(word, constants::kMiddleDisplayWordCenterX, constants::kDisplayWordCenterY);
            break;
        case 2:
            small_centered_font.drawStringCentered(word, constants::kRightDisplayWordCenterX, constants::kDisplayWordCenterY);
            break;
    }
    ofSetColor(ofColor::white);
}

void ofApp::DrawUserInput(int lane){
    ofSetColor(ofColor::black);
    switch (lane) {
        case 0:
            small_centered_font.drawStringCentered(user_input, constants::kLeftDisplayWordCenterX, constants::kUserInputCenterY);
            break;
        case 1:
            small_centered_font.drawStringCentered(user_input,  constants::kMiddleDisplayWordCenterX,  constants::kUserInputCenterY);
            break;
        case 2:
            small_centered_font.drawStringCentered(user_input, constants::kRightDisplayWordCenterX, constants::kUserInputCenterY);
            break;
    }
    ofSetColor(ofColor::white);
}

void ofApp::DrawFrames(int frame){
    frame_images[frame].draw(0,0,constants::kMainWindowWidth, constants::kMainWindowHeight);
}

void ofApp::DrawObstacle(Obstacle o){
    if(o.GetPosition().x != 0){
        o.GetImage().draw(o.GetPosition(), constants::kCarWidth, constants::kCarLength);
    }
    
}

bool ofApp::Collided(Obstacle o, Player p){
    if(o.GetLane() == p.GetLane()){
        return o.GetPosition().y >= p.GetPosition().y;
    }
    return false;
}

void ofApp::DrawRandomObstacle(){
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
        
        if(Collided(o, player)){
            current_state = ENDED;
        }
        iterator++;
        
    }
    
    for(Obstacle o : current_obstacles){
        DrawObstacle(o);
    }
    
}

void ofApp::UpdateObstacle(Obstacle &o){
    int lane = o.GetLane();
    
    switch (lane) {
        case 0:
            o.SetPosition(constants::kLeftObstacleStartX - constants::kDirectionMagnitude * o.GetSpeed(), constants::kDownMagnitude * o.GetSpeed());
            break;
        case 1:
            o.SetPosition(constants::kMiddleObstacleStartX, constants::kDownMagnitude * o.GetSpeed());
            break;
        case 2:
            o.SetPosition(constants::kRightObstacleStartX + constants::kDirectionMagnitude * o.GetSpeed(), constants::kDownMagnitude * o.GetSpeed());
            break;
    }
    if(o.ReachedEnd()){
        o.SetSpeed(0);
    }
}

void ofApp::DrawScore(){
    ofSetColor(ofColor::black);
    
    small_font.drawString(to_string((int)ofGetElapsedTimef()/60) + ":" + to_string((int)ofGetElapsedTimef()), constants::kTimerX, constants::kLiveTrackerY);
    small_font.drawString(to_string(words_typed), constants::kWordCountX, constants::kLiveTrackerY);
    
    score = constants::kWordsTypedScoreWeight * words_typed + ofGetElapsedTimef();
    small_font.drawString(to_string(score), constants::kScoreX, constants::kLiveTrackerY);
    
    ofSetColor(ofColor::white);
}

void ofApp::DrawGameEnd(){
    game_end_image.draw(constants::kEndImageX ,0, game_end_image.getWidth(), game_end_image.getHeight());
    large_centered_font.drawStringCentered(constants::kEndMessage, constants::kEndMessageCenterX, constants::kEndMessageCenterY);
    large_centered_font.drawStringCentered(to_string(score), constants::kEndScoreCenterX, constants::kEndScoreCenterY);
    medium_centered_font.drawStringCentered(constants::kRestartInstruction, constants::kEndScoreCenterX, constants::kRestartInstructionY);
    
}

void ofApp::IncreaseDifficulty(){
    ofSetFrameRate( constants::kDifficultyMultiplier * ofGetElapsedTimef() + constants::kBaseFrameRate);
}

void ofApp::UpdatePlayerPosition(int lane, Player &p){
    switch (lane) {
        case 0:
            p.SetPosition(constants::kLeftPlayerX, constants::kPlayerY);
            break;
        case 1:
            player.SetPosition(constants::kMiddlePlayerX, constants::kPlayerY);
            break;
        case 2:
            player.SetPosition(constants::kRightPlayerX,constants::kPlayerY);
            break;
    }
}

void ofApp::Reset(){
    words_typed = 0;
    score = 0;
    current_obstacles.clear();
    user_input.clear();
    player.Reset();
    ofResetElapsedTimeCounter();
}
