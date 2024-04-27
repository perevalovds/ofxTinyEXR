

#pragma once

#include "ofMain.h"
#include <iostream>

class ofxTinyEXR {
    
public:
    
    static bool loadImage(ofFloatPixels & img, string filepath);
    //static bool loadImageExp(ofFloatImage & img, string filepath);
    
    static bool saveImage( const ofFloatPixels & img, string filepath);
    
    static bool saveHDRImage( const ofFloatPixels & img, string filepath);
};


