/************************************************************************
 * �����ǩ : async_task 
 * �������� : ����async
 * �� �� �� :  
 * �� �� �� :  v1.0
 * ˵    �� :  
 * ��    �� :  dragonfive
 * ����ʱ�� :  2016��7��26�� 17:16:37
 * ����ʱ�� :  
************************************************************************
 * Copyright @dragonfive 2016 . All rights reserved.
************************************************************************/


#include <cmath>
#include <chrono>
#include <future>
#include <iostream>


int main(int argc, const char *argv[])
{
    auto begin = std::chrono::steady_clock::now();//cpp11��ʱ�乤��; 

        //std::future<double> 
    //�����õ��� lambda���ʽ�� ���̡߳�ʱ�乤�� 
    auto f(std::async(std::launch::async,
				[](int n)
				{
			            std::cout << std::this_thread::get_id()
			            << " start computing..." << std::endl;
			
			            double ret = 0;
			            for (int i = 0; i <= n; i++) {
			                ret += std::sin(i);
			            }
						
						//�����õ�ǰ�̵߳�ID�� 
			            std::cout << std::this_thread::get_id()<< " finished computing..." << std::endl; //ʹ��git_id�ķ�����õ�ǰID 
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

