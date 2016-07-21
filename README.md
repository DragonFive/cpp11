# cpp11
标签（空格分隔）： c++
note and test code for cpp11


# auto
C++11中引入的auto主要有两种用途：自动类型推断和返回值占位。

## 自动类型推断
### 用处
1. 声明变量是不指明类型(但这时必须初始化)
2. 当类型名比较长的时候（比如iterator，函数指针）
3. 当变量的类型依赖于模板参数，需要编译器来推断;

### 注意事项
用auto声明的变量必须初始化  
## 返回值占位
主要用在模板函数里,用decltype来推断类型;
注意在c++11标准里需要在后面写上实际的类型，或者推断方式。而c++14则不需要

使用场景
```cpp
template<typename U, typename V>
auto foo(U u, V v) -> decltype(u*v){
    return u*v;
}
```
## 与decltype对比
如果你仅仅是想根据初始化值为一个变量推断合适的数据类型，那么使用auto是一个更加简单的选择。当你只有需要推断某个表达式的数据类型，例如某个函数调用表达式的计算结果的数据类型，而不是某个变量的数据类型时，你才真正需要delctype。

## 参考资料

[【C++11】新特性——auto的使用 - 清风小阁 ](http://blog.csdn.net/huang_xw/article/details/8760403)

[C++11初探：类型推导，auto和decltype ](http://www.cnblogs.com/npbool/p/3433360.html)

[【c++11 faq】auto – 从初始化中推断数据类型](https://wizardforcel.gitbooks.io/cpp-11-faq/content/5.html)

[【c++11 faq】decltype – 推断表达式的数据类型](https://wizardforcel.gitbooks.io/cpp-11-faq/content/9.html)
# enum
## 强类型，有类域
枚举类（enum）（“强类型枚举”）是强类型的，并且具有类域：
强类型是指不会隐式转换为int,有类域是指需要加"类名::"才能访问它的枚举值。

使用场景：
```
Color a6 = Color::blue;   // 正确
```
## 传统类型
enum 后面不加class还是表示使用的传统类型，对于c++11，c++98来说支持它转换为int,也支持它使用类名找到枚举值(c++98不允许)

需要注意的是传统enum不管是c++98还是c++11都不能通过int赋值

##可以指定枚举的底层数据类型
可以保证枚举值所占的字节大小，枚举类的底层数据类型必须是有符号或无符号的整数类型(int/short/char等)，默认情况下是int。

```
enum class Color : char { red, blue }; // 紧凑型表示(一个字节)
```
## 参考资料

[【c++11 FAQ】枚举类——具有类域和强类型的枚举](https://wizardforcel.gitbooks.io/cpp-11-faq/content/6.html)


[【c++11 cpp11-snippets】enumeration.cpp](https://github.com/daniel-j-h/cpp11-snippets/blob/master/src/enumeration.cpp)

# 类型转换

关于强制类型转换的问题，很多书都讨论过，写的最详细的是C++ 之父的《C++ 的设计和演化》。最好的解决方法就是不要使用C风格的强制类型转换，而是使用标准C++的类型转换符：static_cast, dynamic_cast。标准C++中有四个类型转换符：static_cast、dynamic_cast、reinterpret_cast、和const_cast。下面对它们一一进行介绍。
##参考资料
[c++中四种强制类型转换](http://www.360doc.com/content/12/0403/11/9140140_200439539.shtml)

[【C++专题】static_cast, dynamic_cast, const_cast探讨](http://www.cnblogs.com/chio/archive/2007/07/18/822389.html)


# 继承构造函数与父类重载函数的提升
在C++98标准里，可以将普通的重载函数从基类“晋级”到派生类里来解决当基类与派生类的同名成员不在同一个作用域内时,派生类找不到父类同名成员的问题：
而在c++11中甚至连构造函数都可以这么做
```
class A
{
public:
	A(int a):_a(a)
	{
		cout<<"A 的构造函数\n";
	}
	void print(double a)
	{
		cout<<"print in A\n";
	}
	int _a;
}; 
class B : public A
{
public:
	using A::print;
	using A::A;//这句话使得B有了一个B(int)的默认构造函数;而默认构造函数只有一个; 
	void print(int a,int b)
	{
		cout<<"print in B\n";
	}
};

int main()
{
	B b(1);
	//B c;这句话编译不通过，因为B没有这样的默认构造函数; 
	b.print(1.1);
		
	return 0;
}
```
## 参考资料
[【c++11FAQ】继承的构造函数](https://wizardforcel.gitbooks.io/cpp-11-faq/content/48.html)
#Lambda表达式

## 构成
为了描述一个lambda，你必须提供：
它的捕捉列表：即（除了形参之外）它可以使用的变量列表（”[&]” 在上面的记录比较例子中意味着“所有的局部变量都将按照引用的方式进行传递”）。如果不需要捕捉任何变量，则使用 []，[=]表示值传递。
（可选的）它的所有参数及其类型（例如： (int a, int b) ）。
组织成一个块的函数行为（例如：{ return v[a].name < v[b].name; }）。
（可选的）使用”返回值类型后置语法“来指明返回类型。但典型情况下，我们仅从return语句中去推断返回类型，如果没有返回任何值，则推断为void。

Lambda表达式与STL算法一起使用;

通过“函数体”后面的‘()’传入参数。

```
int n = [] (int x, int y) { return x + y; }(5, 4);

cout << n << endl;
```
## 参考资料
[Lambda表达式 | C++11 FAQ 中文版](https://wizardforcel.gitbooks.io/cpp-11-faq/content/18.html)
[C++11 lambda表达式 - KingsLanding ](http://www.cnblogs.com/zhuyp1015/archive/2012/04/08/2438176.html)

# 其它
##委托构造函数（Delegating constructors）

[【c++11FAQ】委托构造函数](https://wizardforcel.gitbooks.io/cpp-11-faq/content/10.html)


## constexpr 常量表达式
能看懂别人的代码就行，自己不需要用。因为这个现在看起来没什么用。

### 参考资料
[【C++11 FAQ】常量表达式（constexpr）](https://wizardforcel.gitbooks.io/cpp-11-faq/content/17.html)

##序列for循环语句

C++11中引入了序列for循环以实现区间遍历的简化。这里所谓的区间可以是任一种能用迭代器遍历的区间，例如STL中由begin()和end()定义的序列。所有的标准容器，例如std::string、 初始化列表、数组，甚至是istream，只要定义了begin()和end()就行。
这里是一个序列for循环语句的例子：
```
void f(const vector& v)
{
    for (auto x : v) cout << x << ‘n’;
    for (auto& x : v) ++x;    
    // 使用引用，方便我们修改容器中的数据
}
```
## 类成员的内部初始化
C++11的基本思想是，允许非静态（non-static）数据成员在其声明处（在其所属类内部）进行初始化。这样，在运行时，需要初始值时构造函数可以使用这个初始值。考虑下面的代码：
```
class A {
public:
    int a = 7;
};
```


