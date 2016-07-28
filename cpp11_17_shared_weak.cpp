/************************************************************************
 * �����ǩ : ����shared_ptr��weak_ptr 
 * �������� :
 * �� �� �� :  
 * �� �� �� :  v1.0
 * ˵    �� :  
 * ��    �� :  dragonfive
 * ����ʱ�� :  
 * ����ʱ�� :  
************************************************************************
 * Copyright @dragonfive 2016 . All rights reserved.
************************************************************************/


#include <memory>
#include <iostream>

using namespace std;

int main()
{
    //shared_ptr<string> sp1(make_shared<string>("Hello"));//make_shared��һ������(������ָ��Ŷ)����һ��sharedָ����ڴ�������; 
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
    //cout << "*wp.lock():" << *wp.lock() << endl;  //! ����ʱ�����
    return 0;
}
