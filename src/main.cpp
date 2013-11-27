#include "ofMain.h"
#include "testApp.h"

//========================================================================
int main(int argc, char *argv[]){
	ofSetupOpenGL(1024,768,OF_WINDOW);			// <-------- setup the GL context

	ofxArgs *args = new ofxArgs(argc, argv);
	ofRunApp(new testApp(args));
	
	delete args;
}
