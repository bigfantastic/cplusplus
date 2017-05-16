#ifndef LINKEDPQUEUE_H
#define LINKEDPQUEUE_H
#include"Vector.h"
template<class T>
class PQueue
{
  Vector<T>queueV;
  public:
    PQueue(){}
    ~PQueue(){}
    int Size()const{return queueV.Sizeof();}    //求长
    bool Empty()const{return queueV.Empty();}    //判空
    const T& Front()const{return queueV.Front();}    //取队头元素
    void Push(const T& item){queueV.Push_back(item);}    //入队
    T Pop();
    void Clear(){queueV.Clear();}    //置空队
};
template<class T>
T PQueue<T>:: Pop()
{
  typename Vector<T>::iterator itr, min = queueV.Begin();    //令迭代器指向数组首元素
  for(itr = min; itr!=queueV.End();++itr)    //遍历寻找最小值元素
    if((*itr)<(*min))
      min=itr;    //指向当前最小元素
  T item=*min;    //储存最小元素
  queueV.Erase(min);    //删除最小元素
  return item;    //返回最小元素
}
#endif
