#include "ofApp.h"

// Example demonstrates reading motion vectors from "RSMB" (ReelSmart Motion Blur) in openFrameworks
// To test it, please put some EXR file(s) bin/data

#include "ofxTinyEXR.h"

//--------------------------------------------------------------
void ofApp::setup() {
    cout << "Reading EXR files from bin/data" << endl;
    ofDirectory dir;
    dir.allowExt("exr");
    int n = dir.listDir("");

    if (n == 0) {
        cout << "No EXR files at bin/data, please copy one or several files!" << endl;
    }

    motionPixels.resize(n);
    for (int i = 0; i < n; i++) {
        string fileName = dir.getPath(i);
        cout << "  " << i+1 << " / " << n << "  " << fileName << endl;
        bool result = ofxTinyEXR::loadImage(motionPixels[i], fileName);
        if (!result) {
            cout << "ERROR reading " << fileName << endl;
        }
    }
}

//--------------------------------------------------------------
void ofApp::update(){
    float FPS = 30;
    int n = motionPixels.size();
    if (n == 0) {
        return;
    }
    float time = ofGetElapsedTimef();
    frame_ = int(fmodf(time * FPS, n));
}

//--------------------------------------------------------------
void ofApp::draw(){
    ofBackground(0);
    if (motionPixels.empty()) {
        ofSetColor(255);
        ofDrawBitmapString("No EXR files at bin/dataError loading motion.exr. Please copy them there", 40, 40);
        return;
    }

    ofSetColor(255);
    float W = ofGetWidth();
    float H = ofGetHeight();

    auto& pix = motionPixels[frame_];
    if (!pix.isAllocated()) {
        return;
    }
    int pixW = pix.getWidth();
    int pixH = pix.getHeight();
    int nx = 100;
    int ny = nx * pixH / pixW;
    float scale = min(W / nx, H / ny);
    ofPushMatrix();
    ofScale(scale, scale);
    for (int y = 0; y < ny; y++) {
        for (int x = 0; x < nx; x++) {
            ofFloatColor vraw = pix.getColor(x * pixW / nx, y * pixH / ny);
            if (vraw.r > 0) {
                glm::vec2 v = glm::vec2(vraw.r, vraw.g);
                v -= glm::vec2(0.5, 0.5);
                v.x *= 10;// pixW;
                v.y *= 10; // pixH;
                ofDrawLine(x, y, x + v.r, y + v.g);
            }
        }
    }

    ofPopMatrix();

    ofSetColor(255);
    ofDrawBitmapString("Frame " + ofToString(frame_), 40, 40);


}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
