/*********************************************************************************
  *Copyright(C),2011-2018,dragonfive
  *Author:   	dragonfive
  *Version:  	v1.0
  *Date:        2016��7��21��20:35:42 
  *Description: ��֤ 
  *Others:  //��������˵��
  *Function List:  //��Ҫ�����б�ÿ����¼Ӧ���������������ܼ�Ҫ˵��
     1.��������
     2.��������
  *History:  //�޸���ʷ��¼�б�ÿ���޸ļ�¼Ӧ�����޸����ڡ��޸��߼��޸����ݼ��
     1.Date:
       Author:
       Modification:
     2.��������
**********************************************************************************/
#include <iostream>
using namespace std;
class A
{
public:
	A(int a):_a(a)
	{
		cout<<"A �Ĺ��캯��\n";
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
	using A::A;//��仰ʹ��B����һ��B(int)��Ĭ�Ϲ��캯��;��Ĭ�Ϲ��캯��ֻ��һ��; 
	void print(int a,int b)
	{
		cout<<"print in B\n";
	}
};

int main()
{
	B b(1);
	//B c;��仰���벻ͨ������ΪBû��������Ĭ�Ϲ��캯��; 
	b.print(1.1);
		
	return 0;
}

