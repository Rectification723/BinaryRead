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
/////////////////////////////////////
/*ģ�庯��������.h �޷���.cpp������
�����ض����Ͷ�ȡ�ļ�
*/
	template <typename T1>
	T1 *getData()
	{
		ifstream inF(Filename, ios::binary);
		inF.open(Filename, ios::binary);
		inF.clear();

		T1* data = new T1[size];
		inF.read(reinterpret_cast<char*>(data), sizeof(T1) * (size));
		inF.close();

		return data;
	}
////////////////////////////////////	
	
	~Cbinread();



public:
	string Filename;
	long size;
private:
	int Bw;
};


#endif

