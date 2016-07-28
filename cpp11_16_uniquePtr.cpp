/************************************************************************
 * �����ǩ : ʹ��unique_ptr 
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
    unique_ptr<int> up1(new int(11));
    //unique_ptr<int> up2 = up1;   //���ܽ��и��Ʋ��� 

    cout << *up1 << endl;
    unique_ptr<int> up3 = move(up1);  //���ܽ����ƶ����� 
    cout << *up3 << endl;
    if (up1)//����up1�Ѿ���Ч;�����ַд����0 
        cout << *up1 << endl;

    up3.reset();  //�ͷ�����ָ���������ָ��Ķ���; 
    up1.reset();

    return 0;
}
//������� g++ -std=c++11 test-1.cpp

