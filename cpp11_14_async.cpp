/************************************************************************
 * 代码标签 : async_task 
 * 功能描述 : 测试async
 * 类 名 称 :  
 * 版 本 号 :  v1.0
 * 说    明 :  
 * 作    者 :  dragonfive
 * 创建时间 :  2016年7月26日 17:16:37
 * 更新时间 :  
************************************************************************
 * Copyright @dragonfive 2016 . All rights reserved.
************************************************************************/


#include <cmath>
#include <chrono>
#include <future>
#include <iostream>


int main(int argc, const char *argv[])
{
    auto begin = std::chrono::steady_clock::now();//cpp11的时间工具; 

        //std::future<double> 
    //下面用到了 lambda表达式、 多线程、时间工具 
    auto f(std::async(std::launch::async,
				[](int n)
				{
			            std::cout << std::this_thread::get_id()
			            << " start computing..." << std::endl;
			
			            double ret = 0;
			            for (int i = 0; i <= n; i++) {
			                ret += std::sin(i);
			            }
						
						//下面获得当前线程的ID， 
			            std::cout << std::this_thread::get_id()<< " finished computing..." << std::endl; //使用git_id的方法获得当前ID 
			            return ret;
			        }
		        	,100000000
				)
	        	
			);


        while(f.wait_for(std::chrono::seconds(1))
            != std::future_status::ready) 
		{
                std::cout << "task is running...\n";
        }


    auto end = std::chrono::steady_clock::now();

    auto diff = end - begin;

    std::cout << "async_task result: "<<f.get() << std::endl;
    std::cout << std::chrono::duration <double, std::milli> (diff).count() << " ms" << std::endl;

    return 0;
}
//constexpr int square(int x) {
//  return x * x;
//}

