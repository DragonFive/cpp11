/*********************************************************************************
  *Copyright(C),2011-2018,dragonfive
  *Author:   	dragonfive
  *Version:  	v1.0
  *Date:        2016年7月21日20:35:42 
  *Description: 验证 
  *Others:  //其他内容说明
  *Function List:  //主要函数列表，每条记录应包含函数名及功能简要说明
     1.…………
     2.…………
  *History:  //修改历史记录列表，每条修改记录应包含修改日期、修改者及修改内容简介
     1.Date:
       Author:
       Modification:
     2.…………
**********************************************************************************/
#include <iostream>
using namespace std;
class A
{
public:
	A(int a):_a(a)
	{
		cout<<"A 的构造函数\n";
	}
	void print(double a)
	{
		cout<<"print in A\n";
	}
	int _a;
}; 
class B : public A
{
public:
	using A::print;
	using A::A;//这句话使得B有了一个B(int)的默认构造函数;而默认构造函数只有一个; 
	void print(int a,int b)
	{
		cout<<"print in B\n";
	}
};

int main()
{
	B b(1);
	//B c;这句话编译不通过，因为B没有这样的默认构造函数; 
	b.print(1.1);
		
	return 0;
}

