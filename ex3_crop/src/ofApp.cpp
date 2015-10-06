#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){

	restore();
	
}

//--------------------------------------------------------------
void ofApp::update(){

}
void ofApp::cropImg()
{
	image.crop(image.width/2-75,(image.height/2)-60,200,50);

}

void ofApp::zoom()
{
	image.resize(500,500);
}

void ofApp::restore()
{
	image.loadImage("images/tdf_1972_poster.jpg");

	
	unsigned char *data = image.getPixels();
	// premier affichage 
	// calcul du nombre de px 
	int components = image.bpp / 8;
	
	for (int y=0; y<image.height; y++) 
	{
		for (int x=0; x<image.width; x++) 
		{

			//Read pixel (x,y) color components
			int index = components * (x + image.width * y);
			int red = data[ index ];
			int green = data[ index + 1 ];
			int blue = data[ index + 2 ];

			
			
			//Set red 
			data[ index ] = red ;
			//Set green 
			data[ index + 1 ] = green;
			//Set blue 
			data[ index + 2 ] = blue;

		}
	}
	image.update();
}
//--------------------------------------------------------------
void ofApp::draw(){
	int a = 20;
	int b = 20;
	image.draw(a,b);
	display(image,gx,gy,a,b,c.r,c.g,c.b);
	
}

void ofApp::display(ofImage image,  int posx, int posy,int posWX, int posWY, int red, int green, int blue)
{
	posx = posx-posWX  ;
	posy = posy-posWY  ;
	string fpsStr = "pos x: "+ofToString(posx)+ " pos y: "+ofToString(posy)+ " red: "+ofToString(red)+" green: "+ofToString(green)+" blue: "+ofToString(blue);
	ofDrawBitmapStringHighlight(fpsStr, 0,image.height+25);

}


//--------------------------------------------------------------
void ofApp::keyPressed(int key){

	switch (key)
	{
	case OF_KEY_UP : 
			cout << "touche UP " << endl;
			cropImg();
			break; 
			default:
				cout << "Mauvaise touche" << endl;
		break;

	case OF_KEY_DOWN : 
		restore();
		break;

	case OF_KEY_RIGHT :
		zoom();
		break;
	}
			
		
		
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){
	gx = x;
	gy = y;
	c = image.getColor(x,y);
	
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
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
