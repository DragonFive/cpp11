/************************************************************************
 * 代码标签 :
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
#include <vector>

using namespace std;

int main() {
  vector<int> v({1, 2, 3});//vector竟然可以这样初始化，对，这个叫做初始化列表; 

  for(auto x : v)
    cout << x << endl;

  /* see also for_each(v.begin(), v.end(), func) */
}

