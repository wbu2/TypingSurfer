#pragma once

#include "ofMain.h"
#include "ofxCenteredTrueTypeFont.h"
#include "Lane.h"
#include "Player.h"
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
    int words_typed = 0;
    int score = 0;
    
    string car_image_path = "car-images" ;
    ofImage start_background;
    ofImage game_background;
    
    ofImage player_car;
    
    ofImage first_frame;
    ofImage second_frame;
    ofImage third_frame;
    
    ofTrueTypeFont default_font;
    ofTrueTypeFont small_font;
    
    ofxCenteredTrueTypeFont centered_font;
    
    vector<Lane> lanes;
    vector<ofImage> car_images;
    vector<Obstacle> current_obstacles;
    
    Player player;
    
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
    void drawPlayer(int lane);
    void drawLane();
    void drawDisplayWords(int lane, string word);
    void drawUserInput(int lane);
    void drawFrames(int frame);
    void drawObstacle(Obstacle o);
    bool Collided(Obstacle o);
    void drawRandomObstacle();
    void UpdateObstacle(Obstacle &o);
    void drawScore();
};
