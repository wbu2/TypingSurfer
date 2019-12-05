#pragma once

#include "ofMain.h"
#include "ofxCenteredTrueTypeFont.h"
#include "ofxControlPanel.h"
#include "Lane.h"
#include "car.h"
#include "FileReader.h"

class ofApp : public ofBaseApp{
    
    enum GameState{
        START_SCREEN = 0,
        RUNNING,
        ENDED
    };
    
private:
    GameState current_state = START_SCREEN;
    
    ofImage start_background;
    ofImage game_background;
    ofImage car_image;
    
    ofTrueTypeFont default_font;
    ofTrueTypeFont small_font;
    
    ofxCenteredTrueTypeFont centered_font;
    
    
    vector<Lane> lanes  = {left_lane, middle_lane, right_lane};
    Lane left_lane;
    Lane middle_lane;
    Lane right_lane;
    
    Car player;
    
    string user_input;
    
    FileReader reader;
    
public:
		void setup();
		void update();
		void draw();

		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void mouseEntered(int x, int y);
		void mouseExited(int x, int y);
		void windowResized(int w, int h);
    void drawGameStart();
    void drawGameRunning();
    void drawLaneMarkers();
    void drawCar(int lane);
    void drawLane();
    void drawDisplayWords(int lane, string word);
    void drawUserInput(int lane);
};
