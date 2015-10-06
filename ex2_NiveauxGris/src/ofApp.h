#pragma once

#include "ofMain.h"


class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

		void majUp(int mod);
		void turnRed();
		void turnRedHSB();

		int moy(int facteur, int red, int green, int blue);

		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);
		
		ofImage tdf;

		ofPixels p;
		ofColor c;
		ofTexture t;
		int count;
		int moyenne;




};
