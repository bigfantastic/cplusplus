#include"List.h"

template<class Iterator>					//在指定范围内输出链表元素
void display_list(Iterator first,Iterator last);
int main()
{
  /*
	List<int>L;
	cout<<"input 10 integers:\n";
	int item;
	for(int i=0;i<10;++i)
	{
		cin>>item;
		L.Push_back(item);
	}
	cout<<"after operator++():"<<endl;			//输出第二个元素
	List<int>::iterator itr=L.Begin();
	cout<<*(++itr)<<endl;
	cout<<"after operator--():"<<endl;			//输出第一个元素
	cout<<*(--itr)<<endl;
	L.Erase(itr);								//删除第一个元素
	cout<<"after erasing the first:"<<endl;
	display_list(L.Begin(),L.End());

	L.Pop_back();				//尾删
	cout<<"after erasing the last:"<<endl;
	display_list(L.Begin(),L.End());

	cout<<"the first and the last:"<<endl;
	cout<<L.Front()<<endl;						//输出首元素
	cout<<L.Back()<<endl;						//输出尾元素
//新增的语句
	cout<<"update the first and the last:"<<endl;
	L.Front()=100;
	L.Back()=200;
	display_list(L.Begin(),L.End());
*/ 
	List<int>a;
	List<int>b;
	List<int>c;
	cout<<"input 5 integers(a):";
	int item;
	for(int i=0;i<5;++i)
	{
		cin>>item;
		a.Push_back(item);
	}
	cout<<"input 5 integers(b):";
	for(int i=0;i<5;++i)
	{
		cin>>item;
		b.Push_back(item);
	}
	c=a+b;
	display_list(c.Begin(),c.End());
	return 0;
}

template<class Iterator>				//在指定范围内输出链表元素
void display_list(Iterator first,Iterator last)
{
	for(;first!=last;++first)
		cout<<*first<<'\t';
	cout<<endl;
}
