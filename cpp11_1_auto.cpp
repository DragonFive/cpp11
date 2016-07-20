#include <iostream>
using namespace std; 


template<typename U, typename V>
auto multiplyUV(U u, V v)->decltype(u*v)
{
    return u*v;
}
auto addNum(int a,int b)->decltype(a+b)
{
	return a+b;
}
int main()
{
	auto a = 2;
	auto b=2.2;
	auto func = addNum;
	cout<<func(a,b)<<endl;
	return 0;
}
