#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup() {

	ofSetFrameRate(30);
	ofBackground(39);
	ofSetWindowTitle("Insta");

	ofNoFill();
	ofSetColor(239, 39, 39, 139);
	// ofSetColor(39, 239, 39, 139);
	// ofSetColor(39, 39, 239, 139);

	ofEnableBlendMode(ofBlendMode::OF_BLENDMODE_ADD);
}

//--------------------------------------------------------------
void ofApp::update() {

}

//--------------------------------------------------------------
void ofApp::draw() {

	ofTranslate(ofGetWidth() / 2, ofGetHeight() / 2);

	float radius = 200;
	for (int deg_param = 0; deg_param < 360 * 2; deg_param += 1) {

		float deg = deg_param + 0.5;
		float x = radius * cos(deg * DEG_TO_RAD);
		float y = radius * sin(deg * DEG_TO_RAD);

		ofPushMatrix();
		ofTranslate(x, y);

		ofBeginShape();
		float line_y = 0;
		while (line_y > -ofGetHeight() / 2 - y) {

			float noise_value = ofNoise(x * 0.005, y * 0.005, line_y * 0.0005 + ofGetFrameNum() * 0.005);
			if (noise_value < 0.45) {

				break;
			}

			float line_x = ofMap(noise_value, 0, 1, -ofGetWidth(), ofGetWidth());
			if (line_y == 0) {

				ofTranslate(-line_x, 0);
			}

			ofVertex(ofPoint(line_x, line_y));

			line_y -= ofMap(noise_value, 0, 1, 0, 1.5);
		}
		ofEndShape();
		ofPopMatrix();
	}

}

//--------------------------------------------------------------
int main() {

	ofSetupOpenGL(720, 720, OF_WINDOW);
	ofRunApp(new ofApp());
}