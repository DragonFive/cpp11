/*************************************************************************
	> File Name: cpp11_24_mutex_try_lock.cpp
	> Author: DragonFive
	> Mail: dragonfive2013@163.com
	> Created Time: 2016年08月08日 星期一 10时59分05秒
 ************************************************************************/

#include<iostream>
#include<mutex>
#include<thread>

volatile int counter(0);//volatile表示每次访问都从内存地址里访问而不是从缓存里面来访问。避免多线程的不一致;
std::mutex mtx;//

void attempt_10k_increases()
{
    for(int i=0;i<10000;i++)
    {
        mtx.lock();//获得不到就阻塞;直到mutex可用,与condition_variable的区别是不需要被唤醒,wait需要被唤醒;
        //if(mtx.try_lock())//只有当获得mutex的时候，才进行下面的操作;
        {
            counter++;
            mtx.unlock();
        }
    }
}

int main()
{
    std::thread threads[10];
    for(int i=0;i<10;i++)
    {
        threads[i] = std::thread(attempt_10k_increases);
    }

    //for(int i=0;i<10;i++)
    for(auto th:threads)
    {
        th.join();
    }
    std::cout<<counter<<"次增加counter"<<std::endl;
    return 0;
}
