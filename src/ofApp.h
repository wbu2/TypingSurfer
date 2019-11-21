#pragma once

#include "ofMain.h"
#include "ofxCenteredTrueTypeFont.h"
#inclue "ofxControlPlanel.h"

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
    
    ofTrueTypeFont default_font;
    ofTrueTypeFont small_font;
    
    ofxCenteredTrueTypeFont font;
    
    string user_input;

    
    
    

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
		
};
