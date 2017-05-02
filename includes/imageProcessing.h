/*
 * imageProcessing.h
 *
 *  Created on: Apr 29, 2017
 *      Author: spratik
 */

#ifndef IMAGEPROCESSING_H_
#define IMAGEPROCESSING_H_
#include <opencv2/opencv.hpp>
class ImageProcess
{

	uchar *blue;
	uchar *green;
	uchar *red;
	int size ;
	int *grayDataBuffer;
	int col;
	int row;

public:
	ImageProcess(){
		blue = NULL;
		green = NULL;
		red = NULL;
		size = 0;
		grayDataBuffer = NULL;
		col = 0;
		row = 0;
	}
	~ImageProcess(){}
	int allocate(cv :: Mat image);
	int processImage(cv :: Mat image, std :: string imageName);
	void getGrayImage(cv :: Mat image, int  *grayDataBuffer);
	int   writePGM(char *fname, int *data);


};

#endif /* IMAGEPROCESSING_H_ */
