#ifndef _DATA_INPPUT_H
#define _DATA_INPPUT_H

#include<iostream>
#include <fstream>
#include <sstream>


using namespace std;


#define float32 4
#define uint16  2
#define uchar8  1    




class Cbinread
{
public:
	Cbinread(string name,int lenth);

	long getDataSize();
	
	float *getDatafloat();
	unsigned int *getDatauint();
	
	~Cbinread();



public:
	string Filename;
	long size;
private:

};


#endif

