/************************************************************************
 * 代码标签 : 用condition_variable 实现生产者消费者模型; 
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

#include <iostream>
#include <thread>
#include <mutex>		// std::mutex, std::unique_lock
#include <condition_variable> 


std::mutex mtx;
std::condition_variable cv;
int cargo = 0;  //这是消费者和生产者共享的变量，应该在关键区(unique_lock的作用域)访问和修改; 


void consumer(int id)
{
	//std::this_thread::yield();
	std::unique_lock<std::mutex> lck(mtx);	//自此进入关键区，直到lck被释放; 
	if (cargo==0)  							//不能用while否则会卡住; 
		cv.wait(lck);						//wait之后lck被释放，线程阻塞，当线程被唤醒后，lck重新被锁住; 
	
	std::cout<<"consumer: "<<id<<" got the cargo: "<<cargo<<std::endl;
	cargo=0;
	
}

void producer(int id)
{
	//std::this_thread::yield();
	std::unique_lock<std::mutex> lck(mtx);	//因为这里修改了共享的变量cargo;所以要加锁;
	cargo=id;
	cv.notify_one(); 
}


int main()
{
	const int maxThread = 100;
	std::thread consumers[maxThread], producers[maxThread];//maxThread个生产者,maxThread个消费者;
	
	for(int i=0;i<maxThread;i++)
	{
		producers[i] = std::thread(producer,i+1);
		consumers[i] = std::thread(consumer,i+1);
		
	} 

	//等待各个子线程运行完;
	for(int i=0;i<maxThread;i++)
	{
		producers[i].join();
		consumers[i].join();
	} 
	return 0;
}

