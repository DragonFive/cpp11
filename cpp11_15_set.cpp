/************************************************************************
 * �����ǩ : ����setֵ 
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
#include <set>

using namespace std;

int main()
{
    set<int> s;
    s.insert(1);
    s.insert(2);
    s.insert(3);
    s.insert(1);
    cout<<"set �� size ֵΪ ��"<<s.size()<<endl;
    cout<<"set �� maxsize��ֵΪ ��"<<s.max_size()<<endl;
    cout<<"set �еĵ�һ��Ԫ���� ��"<<*s.begin()<<endl;
    cout<<"set �е����һ��Ԫ����:"<<*s.end()<<endl;
    s.clear();
    if(s.empty())
    {
        cout<<"set Ϊ�� ������"<<endl;
    }
    cout<<"set �� size ֵΪ ��"<<s.size()<<endl;
    cout<<"set �� maxsize��ֵΪ ��"<<s.max_size()<<endl;
    return 0;
}

