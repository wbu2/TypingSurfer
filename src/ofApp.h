
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
    int words_typed = 0;
    int score = 0;
    
    ofImage game_end_image;
    
    ofVideoPlayer vid_player;
    
    ofTrueTypeFont small_font;
    
    ofxCenteredTrueTypeFont small_centered_font;
    ofxCenteredTrueTypeFont large_centered_font;
    ofxCenteredTrueTypeFont medium_centered_font;
    
    vector<Lane> lanes;
    vector<ofImage> car_images;
    vector<Obstacle> current_obstacles;
    vector<ofImage> frame_images;
    
    Player player;
    
    string user_input;
    
    FileReader reader;
    
    
    
    
public:
    void setup();
    void update();
    void draw();
    void keyPressed(int key);
    
    void DrawGameStart();
    void DrawGameRunning();
    void DrawPlayer(int lane);
    void DrawLane();
    void DrawDisplayWords(int lane, string word);
    void DrawUserInput(int lane);
    void DrawFrames(int frame);
    void DrawObstacle(Obstacle o);
    bool Collided(Obstacle o, Player p);
    void DrawRandomObstacle();
    void UpdateObstacle(Obstacle &o);
    void DrawScore();
    void DrawGameEnd();
    void IncreaseDifficulty();
    void UpdatePlayerPosition(int lane, Player &p);
    void Reset();
};
