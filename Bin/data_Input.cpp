#include "data_input.h"



/*****************************************************************************
* ����   �� ��ȡ�������ļ����������ݴ�С
* ��������� �ļ������·��
* ��������� ��
* ����ֵ  ��
* ˵��   ��
* ����   ��
* ����   ��
* �޸ļ�¼��
* �޸�ʱ�䣺
* �޸�ԭ��
* ***************************************************************************/
Cbinread::Cbinread(string name, int lenth)
{
	Filename = name;
	ifstream inF(Filename, ios::binary);
	////////////////����SIZE//////////////////////

	long l = inF.tellg();
	inF.seekg(0, ios::end);
	long m = inF.tellg();
	size = (m - l) / lenth; // 
	cout << name<<":size =" << size*2/10000000.0<<" M" << endl;
	inF.close();
}
/*****************************************************************************
* ����   �� ���ض������ļ�����Ч���ݴ�С ��λ�ֽ�
* ��������� ��
* ��������� ��
* ����ֵ  ��
* ˵��   ��
* ����   ��
* ����   ��
* �޸ļ�¼��
* �޸�ʱ�䣺
* �޸�ԭ��
* ***************************************************************************/
long Cbinread::getDataSize()
{
	return size; 
}
/*****************************************************************************
* ������ �� getData
* ����   �� �������ݵ��׵�ַ
* ��������� ��
* ��������� ��
* ����ֵ  ��
* ˵��   ��
* ����   ��
* ����   ��
* �޸ļ�¼��
* �޸�ʱ�䣺
* �޸�ԭ��
* ***************************************************************************/

float * Cbinread::getDatafloat()
{
	ifstream inF(Filename, ios::binary);
	inF.open(Filename, ios::binary);
	inF.clear();
	
	float* data = new float[size];
	inF.read(reinterpret_cast<char*>(data), sizeof(float) * (size));
	inF.close();

	return data;
}
unsigned int * Cbinread::getDatauint()
{
	ifstream inF(Filename, ios::binary);
	inF.open(Filename, ios::binary);
	inF.clear();

	unsigned int* data = new unsigned int[size];
	inF.read(reinterpret_cast<char*>(data), sizeof(unsigned int) * (size));
	inF.close();

	return data;
}


Cbinread::~Cbinread()
{


}