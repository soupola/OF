#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	seuil = 127;
	affiche = false;
	
	gray();
	gui.setup();
	gui.add(slider.setup( "Seuil", 127, 0, 255 ));

}

//--------------------------------------------------------------
void ofApp::update(){

}

void ofApp::gray(){
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

			
			 int moy = (red + green + blue)/3;
			
			//Set red 
			data[ index ] = moy ;
			//Set green 
			data[ index + 1 ] = moy;
			//Set blue 
			data[ index + 2 ] = moy;

		}
	}
	image.update();
	
}
void ofApp::cropImg()
{
	image.crop(image.width/2-75,(image.height/2)-60,200,50);

}

void ofApp::zoom()
{
	image.resize(500,500);
}



void ofApp::restore(int seuil)
{
	//image.loadImage("images/tdf_1972_poster.jpg");

	gray();
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

			red = (red < seuil)? red=0 : red = 255;
			green = (green < seuil)? green=0 : green = 255;
			blue = (blue < seuil)? blue=0 : blue = 255;

			
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
	int a = 40;
	int b = 100;
	image.draw(a,b);
	if(affiche)
	{
		gui.draw();
		restore(slider);
	}
	display(image,gx,gy,a,b,c.r,c.g,c.b);
	
}

void ofApp::display(ofImage image,  int posx, int posy,int posWX, int posWY, int red, int green, int blue)
{
	posx = posx-posWX  ;
	posy = posy-posWY  ;
	if(posx > image.width || posy >image.height)
	{
		posx = 0;
		posy=0;
	}

	if(posx > image.width || posy > image.height )
	{
		red = 0;
		green = 0;
		blue = 0;
	}
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
			affiche=false;
			break; 
			

	case OF_KEY_DOWN : 
		affiche = true;
		restore(slider);
		break;

	case OF_KEY_RIGHT :

		break;

	case OF_KEY_LEFT :
	
	break;

	default:
			cout << "Mauvaise touche" << endl;
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
