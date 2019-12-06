#pragma once

#include "ofMain.h"
#include "ofxCenteredTrueTypeFont.h"
#include "Lane.h"
#include "car.h"
#include "FileReader.h"
#include "Obstacle.h"

class ofApp : public ofBaseApp{
    
    enum GameState{
        START_SCREEN = 0,
        RUNNING,
        ENDED
    };
    
private:
    GameState current_state = START_SCREEN;
    
    int kNumLanes = 3;
    
    double obstacle_speed;
    
    ofImage start_background;
    ofImage game_background;
    
    ofImage player_car;
    ofImage car_beamer;
    ofImage car_corvette;
    ofImage car_gt;
    ofImage car_romeo;
    ofImage car_sonata;
    
    ofImage first_frame;
    ofImage second_frame;
    ofImage third_frame;
    
    ofTrueTypeFont default_font;
    ofTrueTypeFont small_font;
    
    ofxCenteredTrueTypeFont centered_font;
    
    Lane left_lane;
    Lane middle_lane;
    Lane right_lane;
    
    Obstacle left_obstacle;
    Obstacle middle_obstacle;
    Obstacle right_obstacle;
    
    vector<Lane> lanes  = {left_lane, middle_lane, right_lane};
    vector<ofImage> car_images = {car_beamer, car_corvette, car_gt, car_romeo, car_sonata};
    vector<Obstacle> obstacles = {left_obstacle, middle_obstacle, right_obstacle};
    
    Car player;
    
    string user_input;
    
    FileReader reader;
    
    int frame_counter;
    
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
    void drawFrames(int frame);
    void drawObstacles(int lane, double speed, ofImage image);
    bool ObstacleIntersects();
};
