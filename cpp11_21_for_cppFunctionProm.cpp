/************************************************************************
 * �����ǩ : algorigthm �е�for_each map reduce �ȵ�ʵ�� ���к���ʽ���; 
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
#include <algorithm>
#include <set>
using namespace std;


//�����Ǻ���ʽ��������for_each 
template<typename Collection,typename Func>
void for_each(Collection const &collection,Func func)
{
	std::for_each(collection.begin(),collection.end(),func);
}

//�����Ǻ���ʽ��������map,��Ϊc++��for_each����������޸�,��������ʹ��transform 
//map������ʾ��������ÿ��Ԫ�ض�ִ����ͬ�Ĳ��� 
template <typename Collection,typename unop>
Collection map(Collection col,unop op) 
{
	std::transform(col.begin(),col.end(),col.begin(),op);
	return col;
}

//transformʵ��reduce
template <typename Collection,typename binop>
auto reduce(Collection col,binop op) 
{
	Collection result(col.size());
	std::transform(col.begin(),col.end()-1,col.begin()+1,result.begin(),op);
	return *(result.begin()-1);
}
 

//zip������ʾ�����������ж�ӦԪ��ִ�в������������; 
template <typename Collection,typename binop>
Collection zip(Collection fc,Collection sc,binop op) 
{	
	Collection result(fc.size());
	std::transform(fc.begin(),fc.end(),sc.begin(),result.begin(),op);
	return result;
}

// exists ��ʾ�жϼ������Ƿ���ĳ��Ԫ�ط�������; 
template <typename Collection,typename Condition>
bool exists(Collection col,Condition con) 
{
	auto exist = std::find_if(col.begin(),col.end(),con);
	return exist != col.end();
}

//��map()���ƣ�filter()Ҳ����һ��������һ�����С�
//��map()��ͬ���ǣ�filter()�Ѵ���ĺ�������������ÿ��Ԫ�أ�
//Ȼ����ݷ���ֵ��True����False�����������Ƕ�����Ԫ�ء�
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
  
  //��for_each����������ÿ��Ԫ�ؽ������; 
  println("running foreach");
  for_each(col,lambda_echo);

  // ��map����vector��ÿ��Ԫ��+1 
  println("running map operation");
  auto addOne = [] (int i) { return i+1;};
  auto returnCol = map(col,addOne);
  for_each(returnCol,lambda_echo);
   //������reduce����Ϊvectorÿһλ��һ������ ;
   println("running reduce operation");
   auto reduceAdd = [] (int a, int b){ return a+b;};
  int bigNum = reduce(col,reduceAdd);
  cout<<"reduce add result:"<<bigNum<<endl;
 
  // ������ʵ����������zip����������ʵ����������֮��Ķ�ӦԪ�ص�ͬ����; 
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
