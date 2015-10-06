#include "ofApp.h"

//--------------------------------------------------------------

void ofApp::setup(){
	count = 1;
	tdf.loadImage("images/tdf_1972_poster.jpg");
	unsigned char *data = tdf.getPixels();
	// premier affichage 
	// calcul du nombre de px 
	int components = tdf.bpp / 8;
	
	for (int y=0; y<tdf.height; y++) 
	{
		for (int x=0; x<tdf.width; x++) 
		{

			//Read pixel (x,y) color components
			int index = components * (x + tdf.width * y);
			int red = data[ index ];
			int green = data[ index + 1 ];
			int blue = data[ index + 2 ];

			
			moyenne = moy(1,red,green,blue);
			//Set red 
			data[ index ] = moyenne ;
			//Set green 
			data[ index + 1 ] = moyenne;
			//Set blue 
			data[ index + 2 ] = moyenne;

		}
	}
	tdf.update();
	
	
}
	
//--------------------------------------------------------------
void ofApp::update(){

}

void ofApp::majUp(int mod){

	tdf.loadImage("images/tdf_1972_poster.jpg");
	unsigned char *data = tdf.getPixels();

	// calcul du nombre de px 
	int components = tdf.bpp / 8;
	
	cout << "count "+ count << endl;

	for (int y=0; y<tdf.height; y++) 
	{
		for (int x=0; x<tdf.width; x++) 
		{

			//Read pixel (x,y) color components
			int index = components * (x + tdf.width * y);

			

			int red = data[ index ];
			int green = data[ index + 1 ];
			int blue = data[ index + 2 ];
			
			int test = moy(1,red,green,blue);
			test  = test - test % count;
			//Set red 
			data[ index ] = test ;
			//Set green 
			data[ index + 1 ] = test;
			//Set blue 
			data[ index + 2 ] = test;

		}
	}
	tdf.update();
}

void ofApp::turnRed()
{
	tdf.loadImage("images/tdf_1972_poster.jpg");
	unsigned char *data = tdf.getPixels();

	// calcul du nombre de px 
	int components = tdf.bpp / 8;
	
	cout << "count "+ count << endl;

	for (int y=0; y<tdf.height; y++) 
	{
		for (int x=0; x<tdf.width; x++) 
		{

			//Read pixel (x,y) color components
			int index = components * (x + tdf.width * y);

			

			int red = data[ index ];
			int green = data[ index + 1 ];
			int blue = data[ index + 2 ];
			
			

			int test = moy(1,red,green,blue);
			test  = test - test % count;

			if(red > green && red> blue)
			{
			//cout << "passe par le if " << endl;
				
				//Set red 
				data[ index ] = red ;
				//Set green 
				data[ index + 1 ] = test;
				//Set blue 
				data[ index + 2 ] = test;
			}

			else
			{
				//Set red 
				data[ index ] = test ;
				//Set green 
				data[ index + 1 ] = test;
				//Set blue 
				data[ index + 2 ] = test;
			}

		}
	}
	tdf.update();
}

void ofApp::turnRedHSB()
{
	tdf.loadImage("images/tdf_1972_poster.jpg");
	unsigned char *data = tdf.getPixels();

	// calcul du nombre de px 
	int components = tdf.bpp / 8;
	
	cout << "count "+ count << endl;

	for (int y=0; y<tdf.height; y++) 
	{
		for (int x=0; x<tdf.width; x++) 
		{

			//Read pixel (x,y) color components
			int index = components * (x + tdf.width * y);

			

			int red = data[ index ];
			int green = data[ index + 1 ];
			int blue = data[ index + 2 ];
			

			c.set(red,green,blue);

			int h = c.getHue();
			int s = c.getSaturation();
			int b = c.getBrightness();

			/*cout << "Hue: " << h << endl;  
			cout << "Saturation: " << s << endl;  
			cout << "Brightness: " << b << endl; */
			int test = moy(1,red,green,blue);
			
			
			if(c.getHue()>0 && c.getHue() <15)
			{
				//Set red 
				data[ index ] = red ;
				//Set green 
				data[ index + 1 ] = test;
				//Set blue 
				data[ index + 2 ] = test;
			}
			else
			{
				//Set red 
				data[ index ] = test ;
				//Set green 
				data[ index + 1 ] = test;
				//Set blue 
				data[ index + 2 ] = test;
			}
				
			

		}
	}
	tdf.update();
}

int ofApp::moy( int facteur, int red, int green, int blue)
{
	//moyenne pour les niveaux de gris 
	int moy = (red + green + blue) / 3;
	return moy;
}

//--------------------------------------------------------------
void ofApp::draw(){
	
	tdf.draw(0,0);

}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){


	//switch key 
	switch (key)
	{
	case OF_KEY_UP : 
			cout << "touche UP " << endl;
			count ++ ;
			if(count>255)
			{
				count= 255;
			}

			majUp(count);
			cout << "count =  " + count << endl;

			
		break;


	case OF_KEY_DOWN : 
			cout << "touche DOWN" << endl;
			count --;
			if(count<1)
			{
				count=1;
			}
			majUp(count);
		break; 

	case OF_KEY_RIGHT : 
			cout << "touche right : turn red" << endl;
			turnRed();
			break;
	case OF_KEY_LEFT : 
	cout << "touche right : turn red with hue" << endl;
	turnRedHSB();
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
