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

    return 0;
}
