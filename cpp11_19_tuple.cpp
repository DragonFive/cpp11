/*************************************************************************
	> File Name: cpp11_18_tuple.cpp
	> Author: DragonFive
	> Mail: dragonfive2013@163.com
	> Created Time: 2016年07月31日 星期日 17时54分08秒
 ************************************************************************/

#include<iostream>
#include<tuple>
using namespace std;

int main()
{
    auto tup =make_tuple(string("hehe"),10,1.23);
    cout<<get<0>(tup)<<endl;
    string str;
    int intNum;
    double douNum;
    
    //下面是tie函数用在式子的左边;只是复制
    tie(str,intNum,douNum)=tup;
    cout<<str<<" "<<intNum<<" "<<douNum<<endl;
    intNum = 12;
    get<2>(tup)=2.4;
    cout<<get<2>(tup)<<" "<<douNum<<endl;

    //下面是tie函数用在式子的右边;是引用
    
    
    auto tup2 = std::tie(str,intNum,douNum);//这里tup2实际到类型为: std::tuple<int&,string&,double&>;
    cout<<get<0>(tup2)<<" "<<get<1>(tup2)<<" "<<get<2>(tup2)<<endl;
    intNum = 14;
    get<2>(tup2)=3.4;
    
    cout<<get<0>(tup2)<<" "<<get<1>(tup2)<<" "<<get<2>(tup2)<<endl;
    
    get<1>(tup2)=16;
    cout<<intNum<<endl;

    return 0;
}
