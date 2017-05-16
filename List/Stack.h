#ifndef STACK_H
#define STACK_H

#include"Vector.h"
template<class T>
class Stack
{
  Vector<T>stackV;
  public:
    Stack(){}
    ~Stack(){}
    int Size()const{return stackV.Sizeof();}                                      //求数据元素个数
    bool Empty()const{return stackV.Empty();}                                   //判空
    const T& Top()const{return stackV.Back();}                                  //取栈顶元素的常量型引用
    T Pop(){T item=stackV.Back();stackV.Pop_back();return item;}                //弹栈
    void Push(const T& item){stackV.Push_back(item);}                          //压栈
    void Clear(){stackV.Clear();}                                              //清为空栈
};


#endif
