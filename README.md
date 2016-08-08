# cpp11
标签（空格分隔）： c++
note and test code for cpp11

----------

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

[用作模板参数的局部类型 | C++11 FAQ 中文版](https://wizardforcel.gitbooks.io/cpp-11-faq/content/21.html)


# 智能指针
## unique_ptr
>为动态申请的内存提供异常安全
将动态申请内存的所有权传递给某个函数(不能给复制，只能移动)
从某个函数返回动态申请内存的所有权
在容器中保存指针

在那些要不是为了避免不安全的异常问题（以及为了保证指针所指向的对象都被正确地删除释放），我们不可以使用内建指针的情况下，我们可以在容器中保存unique_ptr以代替内建指针

## shared_ptr与weak_ptr
当 shared_ref_cnt 被减为0时，自动释放 ptr 指针所指向的对象。当 shared_ref_cnt 与 weak_ref_cnt 都变成0时，才释放 ptr_manage 对象。
如此以来，只要有相关联的 shared_ptr 存在，对象就存在。weak_ptr 不影响对象的生命周期。当用 weak_ptr 访问对象时，对象有可能已被释放了，要先 lock()。

weak_ptr可以保存一个“弱引用”，指向一个已经用shared_ptr进行管理的对象。为了访问这个对象，一个weak_ptr可以通过shared_ptr的构造函数或者是weak_ptr的成员函数lock()转化为一个shared_ptr。当最后一个指向这个对象的shared_ptr退出其生命周期并且这个对象被释放之后，将无法从指向这个对象的weak_ptr获得一个shared_ptr指针，shared_ptr的构造函数会抛出异常，而weak_ptr::lock也会返回一个空指针。

## 参考资料
[C++11中的智能指针](http://my.oschina.net/hevakelcj/blog/465978)

[【c++11FAQ】unique_ptr](https://wizardforcel.gitbooks.io/cpp-11-faq/content/12.html)


# 函数式编程
algorigthm头文件中定义了几个很有用的方法;

相应代码见: [cpp11_21_for_cppFunctionProm.cpp](https://github.com/DragonFive/cpp11/blob/master/cpp11_21_for_cppFunctionProm.cpp)

## for_each
对于一些collection(vector,list,set,map)可以对其中每个元素执行后面的函数;
```
auto lambda_echo = [](int i ) { std::cout << i << std::endl; };  
 std::vector<int> col{20,24,37,42,23,45,37};
 for_each(col,lambda_echo);
```

## transform实现map
transform。该算法用于实行容器元素的变换操作。有如下两个使用原型，一个将迭代器区间[first，last)中元素，执行一元函数对象op操作，交换后的结果放在[result，result+（last-first)）区间中。另一个将迭代器区间[first1，last1)的元素*i，依次与[first2，first2+（last-first）)的元素*j，执行二元函数操作binary_op(*i,*j)，交换结果放在[result，result+（last1-first1)
## reduce
改变来原始的容器元素

## transform实现zip
zip函数将传进来的两个参数中相应位置上的元素组成一个pair数组。如果其中一个参数元素比较长，那么多余的参数会被删掉。

## find_if实现exists 
表示判断集合中是否有某个元素符合条件; 

## remove_if和erase实现filter
和map()类似，filter()也接收一个函数和一个序列。和map()不同的是，filter()把传入的函数依次作用于每个元素，然后根据返回值是True还是False决定保留还是丢弃该元素。
remove_if()并不会实际移除序列[start, end)中的元素; 如果在一个容器上应用remove_if(), 容器的长度并不会改变(remove_if()不可能仅通过迭代器改变容器的属性), 所有的元素都还在容器里面. 实际做法是, remove_if()将所有应该移除的元素都移动到了容器尾部并返回一个分界的迭代器. 移除的所有元素仍然可以通过返回的迭代器访问到. 为了实际移除元素, 你必须对容器自行调用erase()以擦除需要移除的元素.

## 参考资料

[是不是服务端编程刚开始都得从写业务开始？ - 回答作者: itlr ](http://zhihu.com/question/25339235/answer/90183763)

[函数式编程](http://www.cnblogs.com/zhuyp1015/p/3495476.html)

[简单的程序诠释C++ STL算法系列之十八：transform](http://blog.csdn.net/jerryjbiao/article/details/7523110)

[std::remove_if ](http://blog.sina.com.cn/s/blog_68c02fb90100xhoi.html)

[scala zip函数族详解](http://www.iteblog.com/archives/1225)

[Functional programming in C++](http://blog.madhukaraphatak.com/functional-programming-in-c++/)



# 时间工具 chrono
## duration 
duration 是chrono命名空间下面的一个模板类型，它有一些实例类型如下：
```
typedef duration<long long, nano> nanoseconds; //纳秒
typedef duration<long long, micro> microseconds;//微秒
typedef duration<long long, milli> milliseconds;//毫秒
typedef duration<long long> seconds;
typedef duration<int, ratio<60> > minutes;
typedef duration<int, ratio<3600> > hours;

```
我们使用的时候可以使用它的实例化类型来创建对象
```
secons sec{128}
```
当要取得一个duration实例类型的变量的值的时候，使用count成员函数
```
sec.count()
```
当想要对duration进行单位类型转换的时候，可以使用duration_cast<duration_type>进行强制类型转换;
```
chono::minutes min = duration_cast<chono::minutes>(sec)
```


## time_point
有三种类型 steady_clock(稳定常用)
system_clock(直接读取系统时间,可能被人手动改变)
high_resolution_clock(精度更高，单在vc库里面就是system_clock())
```
std::chrono::steady_clock::time_point t1 = std::chrono::steady_clock::now();
std::cout << "Hello World\n";
std::chrono::steady_clock::time_point t2 = std::chrono::steady_clock::now();
std::cout << "Printing took "
  << std::chrono::duration_cast<std::chrono::microseconds>(t2 - t1).count()
  << "us.\n";
```


## 参考资料

[C++11 STL 的時間函式庫：chrono](https://kheresy.wordpress.com/2013/12/27/c-stl-chrono/)

[C++11 新的计时方法——std::chrono 大法好](http://blog.csdn.net/u013390476/article/details/50209603)

# tuple
可以认为tuple是一个未命名的结构体，该结构体包含了特定的tuple元素类型的数据成员。特别需要指出的是，tuple中元素是被紧密地存储的（位于连续的内存区域），而不是链式结构。元素的类型可以不一样。tuple元组定义了一个有固定数目元素的容器,其中的每个元素类型都可以不相同,这与其他容器有着本质的区别.是对pair的泛化。
可以显式地声明tuple的元素类型，也可以通过make_tuple()来推断出元素类型。另外，可以使用get()来通过索引（和C++的数组索引一样，从0而不是从1开始）来访问tuple中的元素。
## 四个常用函数 

### make_tuple
通过make_tuple()来推断出元素类型，以此来构造一个tuple，也可以显式定义一个tuple,如果只有两个元素可以使用make_part进行赋值;tuple是对pair的泛化;

### get<index>(tuple)
通过索引来 **读写** tuple中的元素
### tie()
tie函数用在式子左边，可以将变量连接到一个给定的tuple上，可以通过tie()函数的使用方便的对tuple进行“解包”操作。解包时，我们如果只想解某个位置的值时，可以用std::ignore占位符来表示不解某个位置的值。
tie函数用在式子右边，它会创建一个元组的左值引用.

### tuple_cat()函数
通过该函数可以将多个tuple连接起来形成一个tuple


关于tuple的遍历,元素个数的获取，见我的代码
[cpp11_19_tuple.cpp](https://github.com/DragonFive/cpp11/blob/master/cpp11_19_tuple.cpp)

## 参考资料
[【c++11FAQ】标准库中的元组（std::tuple）](https://wizardforcel.gitbooks.io/cpp-11-faq/content/24.html)

[C++11 tuple——KingsLanding](http://www.cnblogs.com/zhuyp1015/archive/2012/04/08/2438187.html)

[C++11改进我们的程序之简化我们的程序（七）tuple](http://www.cnblogs.com/qicosmos/p/3318070.html)

[介绍C++11标准的变长参数模板](http://www.cnblogs.com/zenny-chen/archive/2013/02/03/2890917.html)

[泛化之美--C++11可变模版参数的妙用](http://www.cnblogs.com/qicosmos/p/4325949.html)

# 线程
C++11提供了新头文件 ```<thread>、<mutex>、<atomic>、<future>```等用于支持多线程。
## async
async()函数是一个简单任务的”启动”（launcher）函数。
代码见：[cpp11_14_async.cpp](https://github.com/DragonFive/cpp11/blob/master/cpp11_14_async.cpp)



## thread 


join()保证了在t1和t2完成后程序才会终结。这里”join”的意思是等待线程返回后再往下执行。
通常我们需要在执行完一个任务后得到返回的结果。对于那些简单的对返回值没有概念的，我建议使用std::future。另一种方法是，我们可以给任务传递一个参数，从而这个任务可以把结果存在这个参数中。
通过this_thrad::get_id()得到线程id发现main函数的id是1，其它线程id依次递增。
使用mutex可以进行关键区的互斥访问 
见代码：[cpp11_20_thread_lambda.cpp](https://github.com/DragonFive/cpp11/blob/master/cpp11_20_thread_lambda.cpp)
```
#include<thread>
#include<iostream>
using namespace std;

void f(vector<double>&, double* res);    // 将结果存在res中

struct F {
    vector<double>& v;
    double* res;
    F(vector<double>& vv, double* p) :v{vv}, res{p} { }
    void operator()();    //将结果存在res中
};

int main()
{
    double res1;
    double res2;

    // f(some_vec,&res1) 在一个单独的线程中执行
    std::thread t1{std::bind(f,some_vec,&res1)};    
    // F(some_vec,&res2)() 在一个单独的线程中执行
    std::thread t2{F(some_vec,&res2)};        

    t1.join();
    t2.join();

    std::cout << res1 << " " << res2 << ‘\n’;
}
```
## mutex 
**lock()**，调用线程将锁住该互斥量。线程调用该函数会发生下面 3 种情况：
1. 如果该互斥量当前没有被锁住，则调用线程将该互斥量锁住，直到调用 unlock之前，该线程一直拥有该锁。
2. 如果当前互斥量被其他线程锁住，则当前的调用线程被**阻塞住**。
3. 如果当前互斥量被当前调用线程锁住，则会产生死锁(deadlock)。

**unlock()**， 解锁，释放对互斥量的所有权。

**try_lock()**，尝试锁住互斥量，如果互斥量被其他线程占有，则当前线程也不会被阻塞。线程调用该函数也会出现下面 3 种情况，

1. 如果当前互斥量没有被其他线程占有，则该线程锁住互斥量，直到该线程调用 unlock 释放互斥量。
2. 如果当前互斥量被其他线程锁住，则当前调用线程返回 false，而**并不会被阻塞掉**。
3. 如果当前互斥量被当前调用线程锁住，则会产生死锁(deadlock)。

[volatile关键字](http://www.cnblogs.com/Chase/archive/2010/07/05/1771700.html)


## condition_variable
condition_variable与mutex的区别是: mutex 里面包的是关键区,互斥访问的，别人unlock后自动唤醒，lock与unlock是成对存在的。而condition_variable是线程之间同步的顺序控制,一个线程wait另一个线程运行完厚notify之后该线程才能继续运行。

条件变量用于线程间的同步通信。```<condition_variable >``` 头文件主要包含了与条件变量相关的类和函数。与条件变量相关的类包括 std::condition_variable和 std::condition_variable_any，还有枚举类型std::cv_status另外还包括函数 std::notify_all_at_thread_exit()。

当 std::condition_variable 对象的某个 wait 函数被调用的时候，它使用 std::unique_lock(封装 std::mutex) 来锁住当前线程。当前线程会一直被阻塞，直到另外一个线程在相同的 std::condition_variable 对象上调用了 notification 函数来唤醒当前线程。

### 基本版：wait、 notify_one、unique_lock
这部分的代码见 [cpp11_22_condVir_proConsu.cpp](https://github.com/DragonFive/cpp11/blob/master/cpp11_22_condVir_proConsu.cpp)
unique_lock 对象以独占所有权的方式（ unique owership）管理 mutex 对象的上锁和解锁操作，所谓独占所有权，就是没有其他的 unique_lock 对象同时拥有某个 mutex 对象的所有权。unique_lock 对象只是简化了 Mutex 对象的上锁和解锁操作，方便线程对互斥量上锁，即在某个 unique_lock 对象的声明周期内，它所管理的锁对象会一直保持上锁状态；而 unique_lock 的生命周期结束之后，它所管理的锁对象会被解锁。

wait函数的一个原型：

```
void wait (unique_lock<mutex>& lck);
```

当前线程调用 wait() 后将被阻塞(此时当前线程应该获得了锁（mutex），不妨设获得锁 lck)，直到另外某个线程调用 notify_* 唤醒了当前线程。

在线程被阻塞时，该函数会自动调用 lck.unlock() 释放锁，使得其他被阻塞在锁竞争上的线程得以继续执行。另外，一旦当前线程获得通知(notified，通常是另外某个线程调用 notify_* 唤醒了当前线程)，wait() 函数也是自动调用 lck.lock()，使得 lck 的状态和 wait 函数被调用时相同）。
这句话的意思就是在线程被阻塞的时候，释放mutex 的lock，在被唤醒的时候重新lock，直到这个lock出了作用域。

```
std::condition_variable::notify_one();
```
notify_one唤醒某个等待(wait)线程。如果当前没有等待线程，则该函数什么也不做，如果同时存在多个等待线程，则唤醒某个线程是不确定的(unspecified)。

### 加强版 wait_for、wait_until、notify_all

```
template <class Predicate>
void wait (unique_lock<mutex>& lck, Predicate pred);
```
加条件的wait，表示如何这个条件不成立，就wait，成立就直接执行。相当于
```
if (!pred()) wait(lck);
```
看这个例子：
```
template <class Rep, class Period>
cv_status wait_for (unique_lock<mutex>& lck,
                      const chrono::duration<Rep,Period>& rel_time);
	
template <class Rep, class Period, class Predicate>
bool wait_for (unique_lock<mutex>& lck,
               const chrono::duration<Rep, Period>& rel_time,
               Predicate pred);
```

wait_for 可以指定一个时间段，在当前线程收到通知或者指定的时间 rel_time 超时之前，该线程都会处于阻塞状态。而一旦超时或者收到了其他线程的通知，wait_for 返回，剩下的处理步骤和 wait() 类似。

可以通过返回值std::cv_status的值来判断是哪种返回情况;
```
std::condition_variable::notify_all();
```
notify_all 唤醒所有的等待(wait)线程。如果当前没有等待线程，则该函数什么也不做。

std::cv_status 枚举类型取值

cv_status::no_timeout 表示	wait_for 或者 wait_until 没有超时，即在规定的时间段内线程收到了通知。
cv_status::timeout 表示	wait_for 或者 wait_until 超时。
代码在：[cpp11_23_wait_for.cpp](https://github.com/DragonFive/cpp11/blob/master/cpp11_23_wait_for.cpp)

## 参考资料 

[【c++11FAQ】互斥](https://wizardforcel.gitbooks.io/cpp-11-faq/content/35.html)

[【c++11FAQ】std::future和std::promise](https://wizardforcel.gitbooks.io/cpp-11-faq/content/70.html)

[【c++11FAQ】async()](https://wizardforcel.gitbooks.io/cpp-11-faq/content/27.html)

[【c++11FAQ】线程（thread）](https://wizardforcel.gitbooks.io/cpp-11-faq/content/77.html)

[C++11 多线程——KingsLanding](http://www.cnblogs.com/zhuyp1015/archive/2012/04/08/2438288.html)

[第五章 条件变量与线程同步](https://github.com/forhappy/Cplusplus-Concurrency-In-Practice/tree/master/zh/chapter5-Condition-Variable)

[5.2 条件变量详解](https://github.com/forhappy/Cplusplus-Concurrency-In-Practice/blob/master/zh/chapter5-Condition-Variable/5.2%20Condition-variable-tutorial.md)

[4.3 锁类型详解](https://github.com/forhappy/Cplusplus-Concurrency-In-Practice/blob/master/zh/chapter4-Mutex/4.3%20Lock-tutorial.md)

# 正则表达式




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

# 原生字符串标识R
正常情况下字符串是位于R" "之间的，结束符就是"。可是字符串内部可以包含"怎么办呢？比如R"fewga"rgare"，改结束符，变成)"，这样就变成R"(fewga"rgare)"，不会混淆了。可是问题又来了，如果字符串内包含)"呢？于是又引入了d-char-sequenceopt（可以为空），估且叫它分隔串吧，变成R"--(fewga）"rgare)--"这样的形式，于是问题解决。由于分隔串是用户指定的，所以可以使用不固定的结束符，不会混淆（除非有人太二）。字符串内有)-"，我就用)#"，有)#"，我就用)**"。

”(…)”分隔法只不过是默认的分隔语法罢了。通过在“(…)”的(…)前后添加显式的自定义分隔号(译注:例如下面例子中的三个星号*)，我们还可以创造出任何我们想要的分隔语法。
```
// 字符串为："quoted string containing the usual terminator (")"
R"***("quoted string containing the usual terminator (")")***"
```

## 参考资料

[原生字符串标识R | C++11 FAQ 中文版](https://wizardforcel.gitbooks.io/cpp-11-faq/content/52.html)

[c++原始字符串](http://www.cnblogs.com/lzxskjo/p/4896164.html)

# 右值引用与移动构造函数
ove(x) 意味着“你可以把x当做一个右值”。
在C++11的标准库中，所有的容器都提供了移动构造函数和移动赋值操作符，那些插入新元素的操作，如insert()和push_back(), 也都有了可以接受右值引用的版本。最终的结果是，在没有用户干预的情况下，标准容器和算法的性能都提升了，而这些都应归功于拷贝操作的减少。

左值（赋值操作符“=”的左侧，通常是一个变量）与右值（赋值操作符“=”的右侧，通常是一个常数、表达式、函数调用）


## 参考资料
[C++11尝鲜：右值引用和转发型引用 ](http://blog.csdn.net/zwvista/article/details/12306283#t7)

[右值引用 | c++11 FAQ 中文版](https://wizardforcel.gitbooks.io/cpp-11-faq/content/47.html)

[cpp11 sniper](https://github.com/daniel-j-h/cpp11-snippets/blob/master/src/move.cpp)


#用户自定义数据后缀 
自字义后缀用operator""定义，就是一种特殊的函数。后缀名必须以下划线开头，因为没有下划线的后缀是留给std用的。后缀的参数只能是unsigned long long、long double、const char*或者const char* + size_t。没了，它就是这么简单易上手又很实用的特性。一般来说适合编为后缀的是单位，如kg，km。

~~C++14预定义了一些标准的字面量，s用于创建std::string，如 "hello"s；h、min、s、ms、us、ns用于创建std::chrono::duration；i、il、if用于创建复数complex<double>、complex<long double>、complex<float>。~~
有以下四种数据标识的情况，可以被用户定义后缀来使用用户自定义数据标识：

    整型标识：允许传入一个unsigned long long或者const char*参数
    浮点型标识：允许传入一个long double或者const char*参数
    字符串标识：允许传入一组(const char*,size_t)参数
    字符标识：允许传入一个char参数。


根据 C++ 11 标准，只有下面这些签名是合法的：

```
char const*
unsigned long long
long double
char const*, std::size_t
wchar_t const*, std::size_t
char16_t const*, std::size_t
char32_t const*, std::size_t


```
上面列出的第一个签名不要同字符串相混淆，应该被称为原始字面量 raw literal 操作符。例如：
```
char const* operator"" _r(char const* s)
{
    return s;
}
 
int main()
{
    std::cout << 12_r << '\n';
}
```


## 参考资料
[C++11 用户自定义字面值](http://www.cnblogs.com/lzxskjo/p/5198947.html)

[C++11 新特性：用户定义字面量](https://www.devbean.net/2012/05/cpp11-literals/)

[【c++11FAQ】用户定义数据标识 ](https://wizardforcel.gitbooks.io/cpp-11-faq/content/13.html)

# 随机数的产生

```
#include <random>
#include <iostream>
int main()
{
	std::default_random_engine generator;  
	std::uniform_int_distribution<int> dis(0,100);  
	for(int i=0;i<5;i++)  
	{  
	    std::cout<<dis(generator)<<std::endl;  
	}  
	return 0; 
}
```


## 参考资料

[ 【C++11】随机数函数库random](http://blog.csdn.net/akonlookie/article/details/8223525)

[[C++11]C++11带来的随机数生成器](http://www.cnblogs.com/egmkang/archive/2012/09/06/2673253.html)

[【c++11FAQ】随机数的产生](https://wizardforcel.gitbooks.io/cpp-11-faq/content/74.html)

[c++一般意义上的随机数生成](http://blog.sina.com.cn/s/blog_79ab4be10100uzrj.html)

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


