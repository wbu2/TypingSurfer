#include "ofMain.h"
#include "ofApp.h"

//========================================================================
int main( ){
	ofGLFWWindowSettings settings;
    settings.setSize(1280, 800);      // <---- Set the window dimensions.
    settings.resizable = false;       // <---- This is the setting in question.

    shared_ptr<ofAppBaseWindow> window = ofCreateWindow(settings);
    shared_ptr<ofApp> app(new ofApp());

    ofRunApp(window, app);
    ofRunMainLoop();

}
