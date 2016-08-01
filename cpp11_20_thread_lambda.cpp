/************************************************************************
 * 代码标签 : thread mutex sleep_for 
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

#include <thread>
#include <iostream>
#include <mutex>
using namespace std; 

int main()
{
	mutex coutlock; 
    thread t1([&coutlock]()
    {
        std::this_thread::sleep_for (chrono::seconds(1)); //线程停止10秒 
        for(int i=0;i<10;i++) 
         {     
         	coutlock.lock();
            cout <<  "In t1 ThreadID : " << std::this_thread::get_id() << ":" << i << endl;     //this_thread::get_id获取当前线程的id ,
            coutlock.unlock();
        } 
    } );
    thread t2([&coutlock]() 
    {          
        std::this_thread::sleep_for (chrono::seconds(1)); 
        for(int i=0;i<10;i++) 
        {         
        	coutlock.lock();
            cout <<  "In t2 ThreadID : " << std::this_thread::get_id() << ":" << i << endl;   
			coutlock.unlock();      
        } 
    } ); 
    t1.join();     //等待线程t1结束后往下运行 
    t2.join();     
    cout<<"Main Thread:"<<std::this_thread::get_id()  <<endl;
    return 0;

}
