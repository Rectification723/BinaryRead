#include "data_input.h"







int main(void)
{
	int i = 0;
	float *data;
	Cbinread     Test("zkb.bin", float32);
	data = Test.getDatafloat();
	cout << Test.getDataSize() << endl;
	for (i=0; i < Test.getDataSize(); i++)
	{
		cout << *(data+i)<<endl;
	}
	


	system("pause");
	return 0;

}
