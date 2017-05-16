#ifndef LIST_H
#define LIST_H

#include<iostream>
#include<stdlib.h>
using namespace std;

template<class T>
class List
{
  struct Node         //双向结点声明
  {
      T data;
      Node *prev,*next;
      Node(const T&d=T(),Node *p=NULL,Node *n=NULL):data(d),prev(p),next(n){}
    };
  Node *head;         //头结点指针
  Node *tail;         //尾结点指针
  int size;         //数据结点个数
  void Init()         //初始化函数
  {size=0;head=new Node;tail=new Node;head->next=tail;tail->prev=head;}
  
  public:
  class const_iterator
  {
    protected:
      Node* current;
      T& retrieve()const{return current->data;}
      const_iterator(Node *p):current(p){}    //转换构造函数
      friend class List<T>;
    public:
      const_iterator():current(NULL){}
      const T& operator*()const{return retrieve();}//return current->data;
      const_iterator& operator++()    //前++
      {
            current=current->next;
            return *this;
          }
      const_iterator operator++(int)    //后++
      {
            const_iterator old=* this;    //old=current;
            ++(*this);            //current=current->next;
            return old;
          }
      const_iterator& operator--()    //前--
      {
            current=current->prev;
            return *this;
          }
      const_iterator operator--(int)    //后--
      {
            const_iterator old=*this;   //old=current;
            --(*this);            //current=current->prev;
            return old;
          }
      bool operator==(const const_iterator & rhs)const
        {return current==rhs.current;}
      bool operator!=(const const_iterator & rhs)const
        {return current!=rhs.current;}
    };

  class iterator:public const_iterator
  {
    protected:
      iterator(Node *p):const_iterator(p){}
      friend class List<T>;
    public:
      iterator(){}
      T& operator* (){return this->retrieve();}
      const T& operator* ()const{return const_iterator::operator*();}
      iterator& operator++()      //前++
      {
            this->current=this->current->next;
            return *this;
          }
      iterator operator++(int)      //后++
      {
            iterator old=* this;      //old=current;
            ++(*this);            //current->next;
            return old;
          }
      iterator& operator--()        //前--
      {
            this->current=this->current->prev;
            return *this;
          }
      iterator operator--(int)      //后--
      {
            iterator old=*this;       //old=current;
            --(*this);            //current=current->prev;
            return old;
          }
    };
  List(){Init();}         //默认构造函数。生成空表
  List(const List<T>&l){Init();operator=(l);}//复制构造函数
  ~List(){Clear();delete head;delete tail;}  //析构函数
  const List& operator=(const List& l);   //复制赋值运算符函数
  iterator Begin(){return iterator(head->next);}
  const_iterator Begin()const{return const_iterator(head->next);}
  iterator End(){return iterator(tail);}
  const_iterator End()const{return const_iterator(tail);}

  T& Front(){return *Begin();}      //返回首指针的引用
  const T& Front()const{return *Begin();} //返回首元素的常量型引用
  T& Back(){return *--End();}       //返回尾元素的引用
  const T& Back()const{return *--End();}  //返回尾元素的常量型引用
  void Push_front(const T& item){Insert(Begin(),item);} //首插
  void Push_back(const T& item){Insert(End(),item);}    //尾插
  void Pop_front(){Erase(Begin());}   //删除数据首结点
  void Pop_back(){Erase(--End());}    //删除数据尾结点
  iterator Erase(iterator itr);     //删除指示器位置上的结点
  iterator Insert(iterator itr,const T& item);//在指示器位置上插入item

  int Size()const{return size;}     //取数据结点个数
  bool Empty()const{return size==0;}    //判空函数
  void Clear(){while(!Empty())Pop_front();}//清表。结果为空表
  const List& operator+(List& l2);//l2加到l1后面
};

template<class T>               //复制赋值成员运算符函数的实现
const List<T>& List<T>::operator =(const List<T>& l)
{
  Clear();            //清为空表
  for(const_iterator itr=l.Begin();itr!=l.End();++itr)  //把表l的结点逐个复制
    Push_back(* itr);
  return * this;
}

template<class T>       //删除迭代器itr指向的结点
typename List<T>::iterator List<T>::Erase(iterator itr)
{
  Node *p=itr.current;      //令结点指针p等于要删除结点的迭代器itr
  iterator re(p->next);     //创建指向删除结点后继的迭代器
  p->prev->next=p->next;      //令删除结点前驱的后继指针指向删除结点的后继
  p->next->prev=p->prev;      //令删除结点后继的前驱指针指向删除结点的前驱
  delete p;           //删除结点
  size--;             //数据元素结点个数减1
  return re;            //返回被删除结点后继的迭代器
}

template<class T>       //在迭代器itr的位置上插入item
typename List<T>::iterator List<T>::Insert(iterator itr,const T& item)
{
  Node *p=itr.current;      //令结点指针p等于迭代器itr的位置
  size++;             //数据元素增1
  p->prev->next=new Node(item,p->prev,p);
  p->prev=p->prev->next;      //令插入位置结点的前驱指针指向新结点
  return iterator(p->prev); 
}

template<class T>
const List<T>& List<T>::operator +(List<T>& l2)
{
  iterator temp = --End();
  iterator temp1 = l2.Begin();
  temp.current->next = temp1.current;
  temp1.current->prev = temp.current;
  delete tail;
  delete l2.head;
  tail=l2.End().current;
  return *this;
}

#endif
