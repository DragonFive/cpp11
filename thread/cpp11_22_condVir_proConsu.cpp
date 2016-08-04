/************************************************************************
 * �����ǩ : ��condition_variable ʵ��������������ģ��; 
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

#include <iostream>
#include <thread>
#include <mutex>		// std::mutex, std::unique_lock
#include <condition_variable> 


std::mutex mtx;
std::condition_variable cv;
int cargo = 0;  //���������ߺ������߹���ı�����Ӧ���ڹؼ���(unique_lock��������)���ʺ��޸�; 


void consumer(int id)
{
	//std::this_thread::yield();
	std::unique_lock<std::mutex> lck(mtx);	//�Դ˽���ؼ�����ֱ��lck���ͷ�; 
	if (cargo==0)  							//������while����Ῠס; 
		cv.wait(lck);						//wait֮��lck���ͷţ��߳����������̱߳����Ѻ�lck���±���ס; 
	
	std::cout<<"consumer: "<<id<<" got the cargo: "<<cargo<<std::endl;
	cargo=0;
	
}

void producer(int id)
{
	//std::this_thread::yield();
	std::unique_lock<std::mutex> lck(mtx);	//��Ϊ�����޸��˹���ı���cargo;����Ҫ����;
	cargo=id;
	cv.notify_one(); 
}


int main()
{
	const int maxThread = 100;
	std::thread consumers[maxThread], producers[maxThread];//maxThread��������,maxThread��������;
	
	for(int i=0;i<maxThread;i++)
	{
		producers[i] = std::thread(producer,i+1);
		consumers[i] = std::thread(consumer,i+1);
		
	} 

	//�ȴ��������߳�������;
	for(int i=0;i<maxThread;i++)
	{
		producers[i].join();
		consumers[i].join();
	} 
	return 0;
}

