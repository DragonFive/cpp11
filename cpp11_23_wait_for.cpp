/*************************************************************************
	> File Name: cpp11_23_wait_for.cpp
	> Author: DragonFive
	> Mail: dragonfive2013@163.com
	> Created Time: 2016年08月02日 星期二 22时03分45秒
 ************************************************************************/

#include<iostream>
#include<mutex>
#include<thread>
#include<condition_variable>
#include<chrono>
std::mutex mtx;
std::condition_variable cv;

int inputNum;
//一个输入线程接受输入,一个输出点到线程，等待一秒，如果是因为超时被唤醒就输出一个点;

void input()
{
    std::cin>>inputNum;
    cv.notify_one();
}


int main()
{
    std::cout<<"please input a num ,or I will output dots!"<<std::endl;
    std::thread inputTh(input);
    std::unique_lock<std::mutex> lck(mtx);
    while(cv.wait_for(lck,std::chrono::seconds(1))==std::cv_status::timeout)
    {
        std::cout<<".";
        std::cout.flush();//清空输出缓存区;
    }
    std::cout<<"\nyour entered :"<<inputNum<<std::endl;
    inputTh.join();

    return 0;    
}
