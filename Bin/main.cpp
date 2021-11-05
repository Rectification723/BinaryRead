#include "data_input.h"
#include <iomanip>






int main(void)
{
	int i = 0;
	float *datafloat;
	int16_t *dataint;
	float Max=0;
	Cbinread     Test("mat0.bin", float32);
	//返回特定类型的数据
	datafloat = Test.getData<float>();
	dataint= Test.getData<int16_t>();
	cout << Test.getDataSize() << endl;
	
	for (i=0; i < Test.getDataSize(); i++)
	{
		
		//cout << fixed << *(datafloat + i + 41)<<endl ;
		if (Max < *(datafloat + i + 41))
		{
			Max = *(datafloat + i + 41);
		}
			
	}
	cout << Max << endl;
	


	system("pause");
	return 0;

}
