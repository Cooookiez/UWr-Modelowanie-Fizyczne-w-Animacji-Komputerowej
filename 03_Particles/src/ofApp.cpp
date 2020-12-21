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
    liveSys.draw();

    // const

    // Domek
    double w, h, x, y;
    h = 160;
    w = 200;
    x = ofGetWindowWidth()/2;
    y = ofGetWindowHeight() - this->grass_height/2 - h;
    // okno
    h = 60;
    w = 40;
    ofSetColor(255, 255, 0);
    ofDrawRectangle(x+w, y+40, w, h);
    // "Ciało"
    h = 160;
    w = 200;
    x = ofGetWindowWidth()/2;
    y = ofGetWindowHeight() - this->grass_height/2 - h;
    ofSetColor(31, 15, 0);
    ofDrawRectangle(x, y, w, h);
    // dach
    ofSetColor(41, 13, 1);
    ofDrawTriangle(x-50, y, x+w+50, y, x+w/2, y-h/2);
    
    // trawa / grass
    ofSetColor(4, 26, 8);
    ofDrawRectangle(0, ofGetWindowHeight()-this->grass_height, ofGetWindowWidth(), this->grass_height);


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
