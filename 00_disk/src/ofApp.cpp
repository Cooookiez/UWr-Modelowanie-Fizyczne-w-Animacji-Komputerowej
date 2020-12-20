#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){

	g = 9.81 * 30; // Skala AKA Inna Planeta
	deltaTime = 0;

}

//--------------------------------------------------------------
void ofApp::update() {
	deltaTime = ofGetElapsedTimef();
	ofResetElapsedTimeCounter();
	for (int i = 0; i < this->NumberOfDiscs; i++) {
		this->disc[i].update(g, deltaTime);
	}
}

//--------------------------------------------------------------
void ofApp::draw() {

	for (int i = 0; i < this->NumberOfDiscs; i++) {
		this->disc[i].draw();
	}

	ofSetColor(54, 198, 255, 100);
	ofDrawRectangle(0, ofGetWindowHeight()/2, ofGetWindowWidth(), ofGetWindowHeight()/2);

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
