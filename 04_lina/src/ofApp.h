#pragma once

#include "ofMain.h"
#include "Point.h"
#include "Connections.h"
#include <ofVec2f.h>

class ofApp : public ofBaseApp{
private:
	
public:

	vector<Point*> points;
	vector<Connection*> connections;
	float g = 9.81;
	int point_last_id = 0;
	float pointSize;
	float pointMass;
	float height;
	float deltaTime;

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

	void createLine(float x, float y, int numberOfPoints);
	
};
