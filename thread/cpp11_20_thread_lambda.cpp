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
struct myData
{
    int data = 0;
    myData(int m):data{m}{}
    myData(myData & m):data{m.data}
    {
        cout<<"���캯��������"<<endl;
    }
};

void testRef(myData & trans)
{
    cout<<"�յ���ֵ��"<<trans.data<<endl;
}
int main()
{
	mutex coutlock; 
    thread t1([&coutlock]()
    {
        std::this_thread::sleep_for (chrono::seconds(1)); //�߳�ֹͣ10�� 
        for(int i=0;i<10;i++) 
         {     
         	coutlock.lock();
            cout <<  "In t1 ThreadID : " << std::this_thread::get_id() << ":" << i << endl;     //this_thread::get_id��ȡ��ǰ�̵߳�id ,
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
    t1.join();     //�ȴ��߳�t1�������������� 
    t2.join();     
    cout<<"Main Thread:"<<std::this_thread::get_id()  <<endl;
    
    //������Դ��ݲ���ʱ��ֵ���������ô���;
    myData dthrans(100);
    thread t3(testRef,std::ref(dthrans));//��仰��������仰��ͬ,�ڴ������õ�ʱ��һ��Ҫʹ�����refѽ;
    //thread t3(bind(testRef,ref(dthrans)));
    t3.join();
    
    return 0;

}
