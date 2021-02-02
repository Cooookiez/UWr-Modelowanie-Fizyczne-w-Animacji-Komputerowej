#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	pointSize = 10;
	pointMass = 1;
    height = 750;
}

//--------------------------------------------------------------
void ofApp::update() {
    deltaTime = ofGetElapsedTimef();
    for (auto& point : points) {
        point->updateForces(g, height);
        point->updateWithVelocity(deltaTime);
    }
}

//--------------------------------------------------------------
void ofApp::draw() {
    // draw points
    for (auto const& point : points) {
        ofSetColor(point->getColor());
        ofDrawCircle(point->posNow, point->size);
    }
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
	createLine(x, y, 10);
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


//--------------------------------------------------------------
void ofApp::createLine(float x, float y, int numberOfPoints) {
    points.push_back(new Point(point_last_id++, x, y, pointSize, pointMass, true));
    for (int i = 1; i < numberOfPoints; i++) {
        points.push_back(new Point(point_last_id++, x + (i*50), y - (i*10), pointSize, pointMass, false));
    }
}
