#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofBackground(12, 12, 69); // niebo / sky
    ofSetFrameRate(60);

    double tmpW = ofGetWindowWidth();
    double tmpH = ofGetWindowHeight();
    liveSys = LiveSys(tmpW, tmpH);

    // gui.setup(); // most of the time you don't need a name
	// gui.add(filled.setup("fill", true));
	// gui.add(y.setup("Y", 100, 0, 10000));
	// gui.add(r.setup("R", 10, 10, 10000));
	// gui.setDefaultTextColor((55, 255, 0));

}

//--------------------------------------------------------------
void ofApp::update() {
	this->dt = ofGetElapsedTimef();
    this->liveSys.update(dt);
	ofResetElapsedTimeCounter();
}

//--------------------------------------------------------------
void ofApp::draw() {
	ofEnableDepthTest();

    // const
    // trawa / grass
    ofSetColor(4, 26, 8);
    ofDrawRectangle(0, ofGetWindowHeight()-60, ofGetWindowWidth(), 60);


    liveSys.draw();
	// gui.draw();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key) {

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

    int tmpW = 250;
    int tmpH = 20;
    liveSys.addEmiter(x-tmpW/2, y-tmpH/2, tmpW, tmpH);

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
