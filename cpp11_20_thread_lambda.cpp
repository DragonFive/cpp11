/************************************************************************
 * �����ǩ : thread mutex sleep_for 
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

#include <thread>
#include <iostream>
#include <mutex>
using namespace std; 

int main()
{
    thread t1([]()
    {
        std::this_thread::sleep_for (chrono::seconds(2)); //�߳�ֹͣ10�� 
        for(int i=0;i<10;i++) 
         {     
            cout <<  "In t1 ThreadID : " << std::this_thread::get_id() << ":" << i << endl;     //this_thread::get_id��ȡ��ǰ�̵߳�id ,
        } 
    } );
    thread t2([]() 
    {          
        std::this_thread::sleep_for (chrono::seconds(1)); 
        for(int i=0;i<10;i++) 
        {         
            cout <<  "In t2 ThreadID : " << std::this_thread::get_id() << ":" << i << endl;         
        } 
    } ); 
    t1.join();     //�ȴ��߳�t1�������������� 
    t2.join();     
    cout<<"Main Thread:"<<std::this_thread::get_id()  <<endl;
    return 0;

}
