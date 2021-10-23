#include "data_input.h"



/*****************************************************************************
* 功能   ： 读取二进制文件并计算数据大小
* 输入参数： 文件的相对路径
* 输出参数： 无
* 返回值  ：
* 说明   ：
* 日期   ：
* 作者   ：
* 修改记录：
* 修改时间：
* 修改原因：
* ***************************************************************************/
Cbinread::Cbinread(string name, int lenth)
{
	Filename = name;
	ifstream inF(Filename, ios::binary);
	////////////////计算SIZE//////////////////////

	long l = inF.tellg();
	inF.seekg(0, ios::end);
	long m = inF.tellg();
	size = (m - l) / lenth; // 
	cout << name<<":size =" << size*2/10000000.0<<" M" << endl;
	inF.close();
}
/*****************************************************************************
* 功能   ： 返回二进制文件的有效数据大小 单位字节
* 输入参数： 无
* 输出参数： 无
* 返回值  ：
* 说明   ：
* 日期   ：
* 作者   ：
* 修改记录：
* 修改时间：
* 修改原因：
* ***************************************************************************/
long Cbinread::getDataSize()
{
	return size; 
}
/*****************************************************************************
* 函数名 ： getData
* 功能   ： 返回数据的首地址
* 输入参数： 无
* 输出参数： 无
* 返回值  ：
* 说明   ：
* 日期   ：
* 作者   ：
* 修改记录：
* 修改时间：
* 修改原因：
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