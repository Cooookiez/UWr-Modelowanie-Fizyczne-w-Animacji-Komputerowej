#pragma once

#include "ofMain.h"
#include "AstrObject.h"

class ofApp : public ofBaseApp{
private:
	const static int numberOfPlanets = 20;
	
public:
	AstrObject sun;
	AstrObject planets[numberOfPlanets];

	double deltaTime;

	ofEasyCam camera;
	
	//--------------------------------------------------------------

	void setup();
	void update();
	void draw();
	
	void keyPressed  (int key);
	void keyReleased(int key);
	void mouseMoved(int x, int y );
	void mouseDragged(int x, int y, int button);
	void mousePressed(int x, int y, int button);
	void mouseReleased(int x, int y, int button);
	void mouseEntered(int x, int y);
	void mouseExited(int x, int y);
	void windowResized(int w, int h);
	void dragEvent(ofDragInfo dragInfo);
	void gotMessage(ofMessage msg);
	
};
