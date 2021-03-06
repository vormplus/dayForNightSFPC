
#include "anastasisRileyScene.h"

#define MIN_THICKNESS 1
#define LINE_DISTANCE 10
#define MAX_THICKNESS 7
#define MAX_ALPHA 0.6

void anastasisRileyScene::setup(){  
    param.set("frequency", 0.025, 0.0125, 0.1);
    parameters.add(param);
    loadCode("anastasisRileyScene/exampleCode.cpp");
    ofEnableAlphaBlending();

}

void anastasisRileyScene::update(){
    
}

void anastasisRileyScene::draw(){
    ofBackground(247, 250, 255);
    
    int numberOfLines = dimensions.height/LINE_DISTANCE;
    int peakRedLine = numberOfLines*0.6;

    for (int i = -1; i < numberOfLines+1; i++) {
        float alpha = MAX_ALPHA*(1-abs(peakRedLine-i)/float(peakRedLine));
        for (int j = 0; j < dimensions.width; j++) {
            float y = i*LINE_DISTANCE+sin(j*param-i*PI/8)*LINE_DISTANCE;
            float thickness = abs(sin(j*param*0.5-i*PI/16)*(MAX_THICKNESS-MIN_THICKNESS))+MIN_THICKNESS;
            ofSetColor(77, 72, 104);
            ofDrawRectangle(j, y, 1, thickness);
            ofSetColor(255, 0, 0, alpha*255);
            ofDrawRectangle(j, y, 1, thickness/2);
        }
    }
}
