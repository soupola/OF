#pragma once

#include "ofMain.h"
#include <stdio.h>
#include <string>
#include "ofxGui.h"
#include <iostream>

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();
		void restore(int seuil);
		void zoom();
		void gray();
		void display(ofImage image,  int posx, int posy,int posWX, int posWY, int red, int green, int blue);

		void cropImg();
		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);


		ofImage image;
		int gx;
		int gy;
		int seuil;
		ofColor c;
		ofPixels p;

		ofxPanel gui;
		ofxIntSlider slider;
		bool affiche;
		
};
