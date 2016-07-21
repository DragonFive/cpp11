/*********************************************************************************
  *Copyright(C),2011-2018,dragonfive
  *Author:  	dragonfive
  *Version:  	v1.0
  *Date:  		2016��7��21��21:51:58 
  *Description: ����c++11��lambda���ʽ 
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
#include <algorithm>
using namespace std;

//���a���������Ԫ��;����a���Խ����κε����л�����;
void print(auto a)
{
	for(auto b:a)
	{
		cout<<b<<" ";
	}
	cout<<endl;
}
struct Record
{
	string name;
	Record(string _name):name(_name){
	}
	
};
//generate ��Ҫ�������������һ��intֵ����,sort��Ҫ������������е�boolֵ; 
void f(vector<Record>& v)
{
    vector<int> indices(v.size());
    int count = 0;
    generate(indices.begin(),indices.end(),[&count]()
    { return count++; });
	print(indices);
    // ��indices���ռ�¼��������˳���������
    std::sort(indices.begin(), indices.end(), [&](int a, int b)
    { return v[a].name<v[b].name; });
    print(indices);
    // ...
}

int main()
{
	//usecase 1.
	vector<int> v = {50, -10, 20, -30};
	print(v);
	std::sort(v.begin(), v.end());    // ����ʱ����Ĭ�Ϲ���
	// ��ʱv�е�����Ӧ���� { -30, -10, 20, 50 }
	print(v);
	// ����Lambda���ʽ�����վ���ֵ����
	std::sort(v.begin(), v.end(), [](int a, int b)
	{ return abs(a)<abs(b); });
	// ��ʱvӦ���� { -10, 20, -30, 50 }
	print(v);
	string hehe="heheh*";
	print(hehe) ;
	
	//usecase 2. 
	vector<Record> p({Record("hehe"),Record("haha")});
	
	f(p);
	return 0;
}

