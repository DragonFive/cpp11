/*************************************************************************
	> File Name: cpp11_18_tuple.cpp
	> Author: DragonFive
	> Mail: dragonfive2013@163.com
	> Created Time: 2016年07月31日 星期日 17时54分08秒
 ************************************************************************/

#include<iostream>
#include<tuple>
using namespace std;

//下面是tuple的遍历方法
template<class Tuple,std::size_t N>
struct TuplePrinter
{
    static void print(const Tuple&t)
    {
        TuplePrinter<Tuple,N-1>::print(t);//使用递归的方法,先变脸前N-1个,这里因为get<index>其中到index需要是常量,而模板在编译时可以确定;
        cout<<", "<<get<N-1>(t);
    }
};

template<class Tuple>
struct TuplePrinter<Tuple,1>//当第二个参数是1时执行着一个;
{
    static void print(const Tuple&t)
    {
        cout<<get<0>(t);
    }
};

//c++11中新支持的变长参数模型;表示不管tuple内部参数类型有多少，都可以用这个函数来进行遍历;
template<class... Args>

void printTuple(tuple<Args...>& t)
{
    TuplePrinter<decltype(t),sizeof ...(Args)>::print(t);
}




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
    //tuple_cat
    tuple<int,string> tup3 = make_pair<int,string>(18,"hello");//tuple是对pair的泛化;
    auto tup4 = tuple_cat(tup2,tup3,tup2);

    //获得tuple中元素的个数;
    int sizeTup4 = tuple_size<decltype(tup4)>::value;
    cout<<"tup4 size is "<<sizeTup4<<endl;
    
    //测试tuple的遍历;
    printTuple(tup4);
    return 0;
}
