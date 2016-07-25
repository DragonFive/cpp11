/************************************************************************
 * 代码标签 :
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

#include <iostream>
#include <functional>
#include <algorithm>
#include <array> 
using namespace std;

//下面这个命名空间是占位符的命名空间; 
using namespace std::placeholders;

void testBind(string val1,string val2,string val3)
{
	cout<<"val1="<<val1<<"  val2="<<val2<<"  val3="<<val3<<endl;
}

struct intAdd{   
        int operator() (int x, int y) const
             { return x+y ;};
};

int main()
{
	//测试发现占位符表示的是占的这个位子在新名字函数调用时用它的第几个参数来填充 
	auto f1 = bind(testBind,_1,"val2","val3");
	f1("val1");
	
	auto f2 = bind(testBind,"val1",_1,"val3");
	f2("val2");
	
	
	
	//下面测试funciton函数,auto函数与结构体成员函数，所以说啊,使用funciton 是有道理的, 
	function<int(int,int)>  f = intAdd();
	auto af = intAdd();
	cout<<f(4,2)<<endl;
	cout<<intAdd()(4,2)<<endl;
	cout<<af(4,2)<<endl;
	array<int,4> intAr{8,4,2,2};
	cout<<accumulate(intAr.begin(),intAr.end(),1,f)<<endl; 
	cout<<accumulate(intAr.begin(),intAr.end(),1,intAdd())<<endl; 
	cout<<accumulate(intAr.begin(),intAr.end(),1,af)<<endl;

	
	
	return 0;
}

