#ifndef Constants_h
#define Constants_h
#include "ofMain.h"

namespace constants {

const int kMainWindowWidth = 1280;
const int kMainWindowHeight = 800;

const int kSmallCenterTextSize = 15;
const int kMediumCenterTextSize = 40;
const int kLargeCenterTextSize = 80;

const int kSmallFontSize = 30;

const int kBaseFrameRate = 8;
const double kDifficultyMultiplier = 1.3;

const int kStartScreenVideoX = 0;
const int kStartScreenVideoY = 0;

const int kGameTitleCenterX = 640;
const int kGameTitleCenterCenterY = 267;

const int kStartMessageCenterX = 640;
const int kStartMessageCenterY = 330;

const int kLeftPlayerX = 120;
const int kMiddlePlayerX = 576;
const int kRightPlayerX = 998;
const int kPlayerY = 533;

const int kCarLength = 190;
const int kCarWidth = 210;

const int kLeftDisplayWordCenterX = 200;
const int kMiddleDisplayWordCenterX = 630;
const int kRightDisplayWordCenterX = 1100;
const int kDisplayWordCenterY = 760;

const int kLeftObstacleStartX = 256;
const int kMiddleObstacleStartX = 512;
const int kRightObstacleStartX = 768;

const int kTimerX = 8;
const int kWordCountX = 610;
const int kScoreX = 1000;
const int kLiveTrackerY = 50;

const int kEndMessageCenterX = 640;
const int kEndMessageCenterY = 450;

const int kEndScoreCenterX = 640;
const int kEndScoreCenterY = 600;

const int kRestartInstructionY = 700;

const int kEndImageX = 400;

const int kWordsTypedScoreWeight = 10;

const int kUserInputCenterY = 780;

const string kGameTitle = "Typing Surfer";
const string kStartMessage = "Press Spacebar To Start";
const string kRestartInstruction = "Press r To Restart";

const string kEndMessage = "Game Over";

const string kImagePath = "images";

const string kWordFile = "input.txt";

const string kTrueTypeFontType = "joystix monospace.ttf";

const string kCarImageLabel = "car";
const string kFrameImageLabel = "frame";

const int kNumLanes = 3;

const int kDownMagnitude = 34;
const int kDirectionMagnitude = 10;
const double kObstacleSpeed = 0.2;


};
#endif /* Constants_h */
