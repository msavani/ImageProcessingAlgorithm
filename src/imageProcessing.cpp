/*
 * imageProcessing.cpp
 *
 *  Created on: Apr 29, 2017
 *      Author: spratik
 */
#include "imageProcessing.h"
#include "enum.h"

#define _DEBUG_IMAGE_ 1
#define BUFFER_SIZE 256

int ImageProcess :: allocate(cv :: Mat image)
{
	row = image.rows;
	col = image.cols;

	size = image.rows * image.cols;

	grayDataBuffer = (int *)calloc(size + 1, sizeof(int));
	if(grayDataBuffer == NULL ){
		std :: cout << "Memory is not allocate" << std :: endl;
		return MemoryOverFlow;
	}

	return Success;
}
void ImageProcess :: getGrayImage(cv :: Mat image, int  *grayDataBuffer)
{
	cv :: Mat channel[3];

	cv :: split(image, channel);

	blue = channel[0].data;
	green = channel[1].data;
	red = channel[2].data;
	int threshould = 0;
	int mean = 0;
	int count = 0;

	for(int index = 0 ; index < size; index++){
		grayDataBuffer[index] = ( (blue[index] + green[index] + red[index]) / 3);
		mean += grayDataBuffer[index] ;
		count++;
	}
	threshould = mean  / count ;
	std :: cout << "THRESHOULD :: " << threshould << std :: endl;
	for(int index = 0; index < size ; index++){

		if(	grayDataBuffer[index] > threshould){
			grayDataBuffer[index] = 255;
		}else{
			grayDataBuffer[index] = 0;
		}
	}

}

int  ImageProcess ::   writePGM(char *fname, int *data)
{
	std :: ofstream file;
	int index;
	file.open (fname, std :: ios::out);

	if(file.is_open()){

		file << "P2" << std :: endl;
		file << col << " " << row << std :: endl;
		file << "255" << std :: endl;

		for(int r = 0; r < row;  r++){

			for(int c = 0; c < col;  c++){

				index  = c + r  * col;

				file << data[index] << " ";

			}

			file << std :: endl;

		}

	}else{
		std :: cout << "file is not open" << std :: endl;
		return FILEERROR;
	}
	file.close();

	return Success;
}

int ImageProcess :: processImage(cv :: Mat image, std :: string imageName)
{

	getGrayImage(image, grayDataBuffer);

#if _DEBUG_IMAGE_
	char fName[BUFFER_SIZE];
	sprintf(fName, "%s_Gray_image.pgm", imageName.c_str());
	writePGM(fName, grayDataBuffer);
#endif

	return Success;
}
