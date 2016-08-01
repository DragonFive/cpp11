/************************************************************************
 * 代码标签 : algorigthm 中的for_each map reduce 等的实现 进行函数式编程; 
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
#include <algorithm>
#include <set>
using namespace std;


//下面是函数式编程里面的for_each 
template<typename Collection,typename Func>
void for_each(Collection const &collection,Func func)
{
	std::for_each(collection.begin(),collection.end(),func);
}

//下面是函数式编程里面的map,因为c++的for_each不允许对象被修改,所以这里使用transform 
//map操作表示对容器中每个元素都执行相同的操作 
template <typename Collection,typename unop>
Collection map(Collection col,unop op) 
{
	std::transform(col.begin(),col.end(),col.begin(),op);
	return col;
}

//transform实现reduce
template <typename Collection,typename binop>
auto reduce(Collection col,binop op) 
{
	Collection result(col.size());
	std::transform(col.begin(),col.end()-1,col.begin()+1,result.begin(),op);
	return *(result.begin()-1);
}
 

//zip操作表示对两个容器中对应元素执行操作，结果返回; 
template <typename Collection,typename binop>
Collection zip(Collection fc,Collection sc,binop op) 
{	
	Collection result(fc.size());
	std::transform(fc.begin(),fc.end(),sc.begin(),result.begin(),op);
	return result;
}

// exists 表示判断集合中是否有某个元素符合条件; 
template <typename Collection,typename Condition>
bool exists(Collection col,Condition con) 
{
	auto exist = std::find_if(col.begin(),col.end(),con);
	return exist != col.end();
}

//和map()类似，filter()也接收一个函数和一个序列。
//和map()不同的是，filter()把传入的函数依次作用于每个元素，
//然后根据返回值是True还是False决定保留还是丢弃该元素。
template <typename Collection,typename Predicate>
Collection filterNot(Collection col,Predicate predicate ) 
{   
    auto returnIterator = std::remove_if(col.begin(),col.end(),predicate);
    col.erase(returnIterator,std::end(col));    
    return col;
}

template <typename Collection,typename Predicate>
Collection filter(Collection col,Predicate predicate) 
{
	 auto fnCol = filterNot(col,[predicate](typename Collection::value_type i) { return !predicate(i);});
	 return fnCol; 
}

int main()
{
  //helper println
  auto println = [](const char  *message){ std::cout << message << std::endl;};
  
  auto lambda_echo = [](int i ) { std::cout << i << std::endl; };  
  std::vector<int> col{20,24,37,42,23,45,37};
  
  //用for_each来对容器中每个元素进行输出; 
  println("running foreach");
  for_each(col,lambda_echo);

  // 用map来对vector中每个元素+1 
  println("running map operation");
  auto addOne = [] (int i) { return i+1;};
  auto returnCol = map(col,addOne);
  for_each(returnCol,lambda_echo);
   //这里用reduce来认为vector每一位是一个大数 ;
   println("running reduce operation");
   auto reduceAdd = [] (int a, int b){ return a+b;};
  int bigNum = reduce(col,reduceAdd);
  cout<<"reduce add result:"<<bigNum<<endl;
 
  // 这里其实不是真正的zip函数，可以实现两个集合之间的对应元素的同操作; 
  println("running zip operation");
  auto zipAdd = [] (int a, int b){ return a+b;};
  std::vector<int> secondCol{40,22,22,24,23,45,34};
  auto zipCol = zip(col,secondCol,zipAdd);
  for_each(zipCol,lambda_echo);

  println("runnig exists");
  //prints 1 if true 0 if false
  std::cout << "value 20 exist= " << exists(col, [] (int value){ return value==20;}) << std::endl;
  std::cout << "value 43 exist= " << exists(col, [] (int value){ return value==43;}) << std::endl;

  println("running filterNot");
  auto filterCol = filterNot(col,[](int value){ return value==23;});
  for_each(filterCol,lambda_echo);

  println("running filter");
  auto filteredCol = filter(col,[](int value){ return value > 30;});
  for_each(filteredCol,lambda_echo);  
}
