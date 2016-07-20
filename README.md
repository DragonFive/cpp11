# cpp11

note and test code for cpp11


# auto
C++11中引入的auto主要有两种用途：自动类型推断和返回值占位。

## 自动类型推断
### 用处
1. 声明变量是不指明类型(但这时必须初始化)
2. 当类型名比较长的时候（比如iterator）
3. 当变量的类型依赖于模板参数，需要编译器来推断;

### 注意事项
用auto声明的变量必须初始化  
## 返回值占位
主要用在模板函数里,用decltype来推断类型;
注意在c++11标准里需要在后面写上实际的类型，或者推断方式。而c++14则不需要


### 参考资料

[【C++11】新特性——auto的使用 - 清风小阁 ](http://blog.csdn.net/huang_xw/article/details/8760403)

[C++11初探：类型推导，auto和decltype ](http://www.cnblogs.com/npbool/p/3433360.html)
