/************************************************************************
 * �����ǩ :
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

#include <iostream>
#include <functional>
#include <algorithm>
#include <array> 
using namespace std;

//������������ռ���ռλ���������ռ�; 
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
	//���Է���ռλ����ʾ����ռ�����λ���������ֺ�������ʱ�����ĵڼ������������ 
	auto f1 = bind(testBind,_1,"val2","val3");
	f1("val1");
	
	auto f2 = bind(testBind,"val1",_1,"val3");
	f2("val2");
	
	
	
	//�������funciton����,auto������ṹ���Ա����������˵��,ʹ��funciton ���е����, 
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

