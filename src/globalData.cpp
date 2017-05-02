/*
 * globalData.cpp
 *
 *  Created on: Apr 10, 2017
 *      Author: spratik
 */
#include "globalData.h"
#include "enum.h"

int GlobalData :: SplitString(char *str, char delimeter,std ::  vector <std :: string> &stringList)
{
	std :: string buffer;
	buffer.clear();
	int i = 0;

	for(i = 0; str[i] != '\0'; i++)
	{

		if(str[i]  != delimeter){

			buffer += str[i];

			if(str[ i + 1 ] == '\0'){
				stringList.push_back(buffer);
			}

		}else{
			/// if string length is zero then DO n't do any process
			if(strlen(buffer.c_str())){
				stringList.push_back(buffer);
			}
		}
	}
	return Success;
}
