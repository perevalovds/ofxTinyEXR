#pragma once

#include "ofMain.h"

// Example demonstrates reading motion vectors from "RSMB" (ReelSmart Motion Blur) in openFrameworks
// To test it, please put some EXR file(s) bin/data

class ofApp : public ofBaseApp {

public:
	void setup();
	void update();
	void draw();

	void keyPressed(int key);
	void keyReleased(int key);
	void mouseMoved(int x, int y);
	void mouseDragged(int x, int y, int button);
	void mousePressed(int x, int y, int button);
	void mouseReleased(int x, int y, int button);
	void mouseEntered(int x, int y);
	void mouseExited(int x, int y);
	void windowResized(int w, int h);
	void dragEvent(ofDragInfo dragInfo);
	void gotMessage(ofMessage msg);
	
	vector<ofFloatPixels> motionPixels;

	int frame_ = 0;
};
