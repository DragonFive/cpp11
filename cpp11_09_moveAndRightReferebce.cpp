/*************************************************************************
	> File Name: cpp11_9_moveAndRightReferebce.cpp
	> Author: DragonFive
	> Mail: dragonfive2013@163.com
	> Created Time: 2016年07月22日 星期五 14时52分39秒
 ************************************************************************/

#include<iostream>
#include<algorithm>
using namespace std;

class Fruit
{
public:
    Fruit(string& label_) : label(label_) 
    {  
        cout<<"left reference"<<endl;
    }
    Fruit(string&& label_) : label(move(label_)) 
    {  
        cout<<"right reference"<<endl;
    }

    /* copy constructor*/
    Fruit(const Fruit& other) : label(other.label) 
    {
        cout << "copy constructor" << endl;
        
    }

    /* copy assign */
    Fruit& operator=(Fruit& other) 
    {
        cout << "copy assign" << endl;

        label = other.label;
        return *this;
            
    }
    //move(x)意味着你可以把x当作右值;
    //有move构造函数到类才能被move
    /* move constructor */
    Fruit(Fruit&& other) : label(move(other.label)) 
    {
        cout << "move constructor" << endl;
            
    }

    /* move assign */
    Fruit& operator=(Fruit&& other) 
    {
         cout << "move assign" << endl;

         label = move(other.label);
         return *this;
            
    }

    string getLabel() { return label;  }

private:
    string label;

};

//下面是第一个换值的函数
template<class T>
void swapT(T& A,T&B)
{
    T temp=move(A);
    A=move(B);
    B=move(temp);
}

void swapAuto(auto & A, auto & B)
{
    auto temp = move(A);
    A = move(B);
    B = move(temp);
}

//需要注意到是行参里面使用auto在c++11里面是不行到,在c++14之后是可以的;
void printList(auto a)
{
    for(auto item : a)
    {
        cout<<item<<" ";
    }
    cout<<endl;
}
int main()
{
    //usecase 1 这里测试移动函数;
    string a = "abc";
    string b = "ABC";
    //swapT(a,b);
    swapAuto(a,b);
    printList(a);
    printList(b);
   
    //usecase 2 这里测试右值引用和移动构造;
    Fruit firstFruit("apple");//调用到是右值引用;被右值引用后那个临时变量名就没有了，很合理呀;
    string strFruit2="banana";
    Fruit secondFruit(strFruit2);//调用到是左值引用;
       
    Fruit thirdFruit(firstFruit);//复制构造函数;
    Fruit ForthFruit(move(secondFruit));
    
    cout<<"FirstFruit:"<<firstFruit.getLabel()<<endl;
    cout<<"secondFruit:"<<secondFruit.getLabel()<<endl;
    cout<<"ThirdFruit:"<<thirdFruit.getLabel()<<endl;
    cout<<"ForthFruit:"<<ForthFruit.getLabel()<<endl;
    return 0;
}
