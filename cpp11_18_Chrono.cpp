/************************************************************************
 * 代码标签 : chrono中的duration和tine_point结构; 
 * 功能描述 :
 * 类 名 称 :  
 * 版 本 号 :  v1.0
 * 说    明 :  
 * 作    者 :  dragonfive
 * 创建时间 :  
 * 更新时间 :  
************************************************************************
 * Copyright @dragonfive 2016 . All rights reserved.
************************************************************************/

#include <chrono>  
#include <iostream> 
using namespace std;
using namespace chrono;

int main()
{
	auto start = system_clock::now();//这个是chrono的time_point类型; 
	// do something...
	int sum=0;
	for(int i=0;i<10000000;i++)
	{
		sum+=i;
	}
	auto end   = system_clock::now();
	auto duration = duration_cast<microseconds>(end - start);
	cout <<  "花费了" 
	     << duration.count() 
	     << "微秒" << endl;
	     
	return 0;
}


