/************************************************************************
 * 代码标签 : 测试shared_ptr与weak_ptr 
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
    //shared_ptr<string> sp1(make_shared<string>("Hello"));//make_shared用一个变量(而不是指针哦)生成一个shared指向的内存管理对象; 
    //shared_ptr<string> sp1(make_shared<string>(string("Hello")));
    shared_ptr<string> sp1(new string("Hello"));
    shared_ptr<string> sp2 = sp1;
    cout << "*sp1:" << *sp1 << endl;
    cout << "*sp2:" << *sp2 << endl;
    sp1.reset();
    cout << "*sp2:" << *sp2 << endl;

    weak_ptr<string> wp = sp2; 
    cout << "*wp.lock():" << *wp.lock() << endl;
    sp2.reset();
    //cout << "*wp.lock():" << *wp.lock() << endl;  //! 运行时会出错
    return 0;
}
