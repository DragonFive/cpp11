/************************************************************************
 * �����ǩ : chrono�е�duration��tine_point�ṹ; 
 * �������� :
 * �� �� �� :  
 * �� �� �� :  v1.0
 * ˵    �� :  
 * ��    �� :  dragonfive
 * ����ʱ�� :  
 * ����ʱ�� :  
************************************************************************
 * Copyright @dragonfive 2016 . All rights reserved.
************************************************************************/

#include <chrono>  
#include <iostream> 
using namespace std;
using namespace chrono;

int main()
{
	auto start = system_clock::now();//�����chrono��time_point����; 
	// do something...
	int sum=0;
	for(int i=0;i<10000000;i++)
	{
		sum+=i;
	}
	auto end   = system_clock::now();
	auto duration = duration_cast<microseconds>(end - start);
	cout <<  "������" 
	     << duration.count() 
	     << "΢��" << endl;
	     
	return 0;
}


