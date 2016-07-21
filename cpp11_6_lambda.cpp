/*********************************************************************************
  *Copyright(C),2011-2018,dragonfive
  *Author:  	dragonfive
  *Version:  	v1.0
  *Date:  		2016年7月21日21:51:58 
  *Description: 测试c++11的lambda表达式 
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
#include <algorithm>
using namespace std;

//输出a里面的所有元素;这里a可以接受任何的序列化输入;
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
//generate 需要第三个参数输出一个int值填入,sort需要第三个输出序列的bool值; 
void f(vector<Record>& v)
{
    vector<int> indices(v.size());
    int count = 0;
    generate(indices.begin(),indices.end(),[&count]()
    { return count++; });
	print(indices);
    // 对indices按照记录的名字域顺序进行排序
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
	std::sort(v.begin(), v.end());    // 排序时按照默认规则
	// 此时v中的数据应该是 { -30, -10, 20, 50 }
	print(v);
	// 利用Lambda表达式，按照绝对值排序
	std::sort(v.begin(), v.end(), [](int a, int b)
	{ return abs(a)<abs(b); });
	// 此时v应该是 { -10, 20, -30, 50 }
	print(v);
	string hehe="heheh*";
	print(hehe) ;
	
	//usecase 2. 
	vector<Record> p({Record("hehe"),Record("haha")});
	
	f(p);
	return 0;
}

