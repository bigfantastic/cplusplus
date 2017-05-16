#ifndef QUEUE_H
#define QUEUE_H

#include"Vector.h"
template<class T>
class Queue
{
  Vector<T>queueV;
  public:
    Queue(){}
    ~Queue(){}
    int Size()const {return queueV.Sizeof();}    //求长
    bool Empty()const {return queueV.Empty();}   //判空
    const T& Front()const{return queueV.Front();}    //取队头元素
    void Push(const T& item) {queueV.Push_back(item);}    //入队
    T Pop(){T item=queueV.Front();queueV.Erase(queueV.Begin());return item;}    //弹栈
    void Clear(){queueV.Clear();}    //置空队
};

#endif
