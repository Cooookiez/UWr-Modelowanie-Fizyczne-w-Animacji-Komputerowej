#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	pointSize = 5;
	pointMass = 1;
    height = ofGetWindowHeight();
}

//--------------------------------------------------------------
void ofApp::update() {
    // deltaTime = ofGetElapsedTimef();
    // deltaTime /= 10;
    deltaTime = .025; // jedyna warto gdzie sie ni psuło

    // Points (Gravity)
    for (auto& point : points) {
        point->updateForces(g, height);
    }

    // Lines
    for (auto& connection : connections) {
        connection->update(420, points);
    }

    // Points (Velocity)
    for (auto& point : points) {
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

    int curSize = points.size();

    float dx = ofRandom(50, 60);
    dx *= ofRandom(1) > .5 ? 1:-1;
    float dy = ofRandom(-10, 20);

    points.push_back(new Point(point_last_id++, x, y, pointSize, pointMass, true));
    for (int i = 1; i < numberOfPoints; i++) {
        points.push_back(new Point(point_last_id++, x + (i*dx), y - (i*dy), pointSize, pointMass, false));
    }


    for (int i = 0; i < numberOfPoints-1; i++) {
        connections.push_back(new Connection(curSize + i, curSize + 1 + i, points));
    }

}
