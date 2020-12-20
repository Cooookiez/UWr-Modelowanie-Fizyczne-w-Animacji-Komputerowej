#include "ofApp.h"
#include "AstrObject.h"
#include <cstdlib>
#include <math.h>

//--------------------------------------------------------------
void ofApp::setup(){
    ofBackground(0, 0, 0);
    ofSetFrameRate(60);

	double posX, posY, posZ, radius, mass, speedX, speedY, speedZ;
	bool farFromSun = false;
    ofVec3f position;
	for(int i = 0; i < this->numberOfPlanets; i++) {

		radius = ofRandom(sun.radius/5.0, sun.radius/20.0);

		do {
			posX = ofRandom(0, sun.radius*8);
			posY = ofRandom(0, sun.radius*8);
			posZ = ofRandom(0, sun.radius*8);
			posX *= ofRandom(1) > .5 ? 1:-1;
			posY *= ofRandom(1) > .5 ? 1:-1;
			posZ *= ofRandom(1) > .5 ? 1:-1;
			position = {posX, posY, posZ};

			// make init distance alweys far from sun
			if(position.length() - sun.radius*6 - radius >= 0) {
				farFromSun = true;
			} else {
				farFromSun = false;
			}

		} while(!farFromSun);
		// posZ = 0;

		mass = ofRandom(sun.mass/100000000, sun.mass/50000000) * radius;

		double speedTMP = ofRandom(AstrObject().speed_min, AstrObject().speed_max);

		double theta = atan(posY / posX);

		speedX = ofRandom(AstrObject().speed_min, AstrObject().speed_max);
		speedY = ofRandom(AstrObject().speed_min, AstrObject().speed_max);
		speedZ = ofRandom(AstrObject().speed_min, AstrObject().speed_max);
		speedX *= ofRandom(1) > .5 ? 1:-1;
		speedY *= ofRandom(1) > .5 ? 1:-1;
		speedZ *= ofRandom(1) > .5 ? 1:-1;

		planets[i] = AstrObject(1000, radius, position, {speedX, speedY, speedZ});
	}
}

//--------------------------------------------------------------
void ofApp::update() {
	deltaTime = ofGetElapsedTimef();
	ofResetElapsedTimeCounter();
	for(int i = 0; i < this->numberOfPlanets; i++) {
		planets[i].update(deltaTime);
	}
}

//--------------------------------------------------------------
void ofApp::draw() {
	camera.begin();

	this->sun.draw();

	for(int i = 0; i < this->numberOfPlanets; i++) {
		planets[i].draw();
	}

	camera.end();
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
