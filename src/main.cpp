/*
 * main.cpp
 *
 *  Created on: Aug 29, 2017
 *      Author: solanki pratik
 */

#include "enum.h"
#include <opencv2/opencv.hpp>
#include <stdlib.h>
#include <string.h>
#include "imageProcessing.h"

std :: string  GetImageFileName(char *imageFilePath)
{
	std :: string imageName;
	std :: string pngImage;

	for(int  index = 0; imageFilePath[index] != '\0'; index++ ){

		if(imageFilePath[index]  !=  '.' ){

			imageName += imageFilePath[index];

		}else {

			if(imageFilePath[++index] == '/'){
				continue;
			}else{
				break;
			}


		}
	}

	return imageName;

}
int main(int argc , char **argv)
{

	if(argc != 2){
		std :: cout << "EXE INPUT_IMAGE" << std ::  endl;
		return 0;
	}

	std :: string imageName = GetImageFileName(argv[1]);

	//std :: cout << imageName << std :: endl;

	cv ::  Mat  image =  cv :: imread(argv[1], 1);

	if( !image.data){
		std :: cout << "IMAGE READ ERROR" << std :: endl;
		return IMAGEREADERROR;
	}

	ImageProcess *ip = new ImageProcess() ;

	if(ip != NULL){

			if(ip->allocate(image) == Success){

					ip->processImage(image, imageName);

			}else{
				std :: cout  << "allocation function fail" << std :: endl;
				return ALLOCATIONFUNCTIONFAIL;
			}


	}else{
		std :: cout << "Image Processing object is not created" << std :: endl;
		return OBJECTCREATIONERROR;
	}



}

