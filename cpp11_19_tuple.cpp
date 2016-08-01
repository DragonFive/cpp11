/*************************************************************************
	> File Name: cpp11_18_tuple.cpp
	> Author: DragonFive
	> Mail: dragonfive2013@163.com
	> Created Time: 2016��07��31�� ������ 17ʱ54��08��
 ************************************************************************/

#include<iostream>
#include<tuple>
using namespace std;

//������tuple�ı�������
//������ʵ�ǿɱ�ģ����������Եݹ�ķ�ʽչ��������;
//�����Ǳ���������е�Ԫ��;
template<class Tuple,std::size_t N>
struct TuplePrinter
{
    static void print(const Tuple&t)
    {
        TuplePrinter<Tuple,N-1>::print(t);//ʹ�õݹ�ķ���,�ȱ���ǰN-1��,������Ϊget<index>���е�index��Ҫ�ǳ���,��ģ���ڱ���ʱ����ȷ��;
        cout<<", "<<get<N-1>(t);
    }
};

template<class Tuple>
struct TuplePrinter<Tuple,1>//���ڶ���������1ʱִ����һ��;
{
    static void print(const Tuple&t)
    {
        cout<<get<0>(t);
    }
};

//c++11����֧�ֵı䳤����ģ��;��ʾ����tuple�ڲ����������ж��٣���������������������б���;
template<class... Args>

void printTuple(tuple<Args...>& t)
{
    TuplePrinter<decltype(t),sizeof ...(Args)>::print(t);
    cout<<endl;
}


//�����Ǹ���tupleԪ�ػ�ȡ���Ӧ������λ��;
template<class Tuple,class T,int I>//T��ʾ����Ԫ�ص�����;
struct find_index
{
    static int find(Tuple &tup,T &&val)
    {
        return get<I-1>(tup)==val?I-1:find_index<decltype(tup),T,I-1>::find(tup,std::forward<T>(val));
    }
};
template<class Tuple,class T>//T��ʾ����Ԫ�ص�����;
struct find_index<Tuple,T,1>
{
    static int find(Tuple &tup,T&&val)
    {
        return get<0>(tup)==val?0:-1;
    }
};

template<class T,class... Args>
int tuple_find_index(tuple<Args...> const & tup, T &&val)
{
    return find_index<decltype(tup),T,sizeof...(Args)>::find(tup,move(val));//�����move��forward<T>һ�� 
}




int main()
{
    auto tup =make_tuple(string("hehe"),10,1.23);
    cout<<get<0>(tup)<<endl;
    string str;
    int intNum;
    double douNum;
    
    //������tie��������ʽ�ӵ����;ֻ�Ǹ���
    tie(str,intNum,douNum)=tup;
    cout<<str<<" "<<intNum<<" "<<douNum<<endl;
    intNum = 12;
    get<2>(tup)=2.4;
    cout<<get<2>(tup)<<" "<<douNum<<endl;

    //������tie��������ʽ�ӵ��ұ�;������
    
    
    auto tup2 = std::tie(str,intNum,douNum);//����tup2ʵ�ʵ�����Ϊ: std::tuple<int&,string&,double&>;
    cout<<get<0>(tup2)<<" "<<get<1>(tup2)<<" "<<get<2>(tup2)<<endl;
    intNum = 14;
    get<2>(tup2)=3.4;
    
    cout<<get<0>(tup2)<<" "<<get<1>(tup2)<<" "<<get<2>(tup2)<<endl;
    
    get<1>(tup2)=16;
    cout<<intNum<<endl;
    //tuple_cat
    tuple<int,string> tup3 = make_pair<int,string>(18,"hello");//tuple�Ƕ�pair�ķ���;
    auto tup4 = tuple_cat(tup2,tup3,tup2);

    //���tuple��Ԫ�صĸ���;
    int sizeTup4 = tuple_size<decltype(tup4)>::value;
    cout<<"tup4 size is "<<sizeTup4<<endl;
    
    //����tuple�ı���;
    printTuple(tup4);

    //����tuple�����Ĳ�ѯ;
    auto tup5=make_tuple(13,16,19);
    
    cout<<"find 16 at:"<<tuple_find_index(tup5,16)<<endl;
    return 0;
}
