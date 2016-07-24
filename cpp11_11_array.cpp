/*************************************************************************
	> File Name: cpp11_11_array.cpp
	> Author: DragonFive
	> Mail: dragonfive2013@163.com
	> Created Time: 2016年07月24日 星期日 19时02分56秒
 ************************************************************************/

#include<iostream>
#include<algorithm>
#include<array>
using namespace std;

void print(auto list)
{
    for(auto item:list)
    {
        cout<<item<<" ";
    }
    cout<<endl;
}

template<typename C> typename C::value_type sum(const C& list)
{
    //auto sumResult=NULL;
    //for(auto item:list)
    //{
    //    sumResult+=item;
    //}
    //return sumResult;
    return accumulate(list.begin(),list.end(),0);
}

int main()
{
    array<int,6> ar={1,2,3};
    print(ar);
    cout<<sum(ar)<<endl;
    return 0;
}
