#include "ofMain.h"
#include "ofApp.h"

//========================================================================
int main( ){
    ofGLFWWindowSettings settings;
    settings.setSize(1280, 800);      // <---- Set the window dimensions.
    settings.resizable = false;       // <---- This is the setting in question.

    ofCreateWindow(settings);
    return ofRunApp(new ofApp);

}
