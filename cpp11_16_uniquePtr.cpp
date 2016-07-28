/************************************************************************
 * 代码标签 : 使用unique_ptr 
 * 功能描述 :
 * 类 名 称 :  
 * 版 本 号 :  v1.0
 * 说    明 :  
 * 作    者 :  dragonfive
 * 创建时间 :  
 * 更新时间 :  
************************************************************************
 * Copyright @dragonfive 2016 . All rights reserved.
************************************************************************/

#include <memory>
#include <iostream>

using namespace std;

int main()
{
    unique_ptr<int> up1(new int(11));
    //unique_ptr<int> up2 = up1;   //不能进行复制操作 

    cout << *up1 << endl;
    unique_ptr<int> up3 = move(up1);  //智能进行移动操作 
    cout << *up3 << endl;
    if (up1)//这里up1已经无效;里面地址写的是0 
        cout << *up1 << endl;

    up3.reset();  //释放智能指针管理对象和指向的对象; 
    up1.reset();

    return 0;
}
//编译命令： g++ -std=c++11 test-1.cpp

