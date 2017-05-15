#ifndef VECTOR_H
#define VECTOR_H
#include<stdlib.h>
#include<iostream>
using namespace std;

template<class T>
class Vector
{
  private:
    T *data;                           //指向动态数组指针
    int size;
    int max;                           //数组容量
    void Error(const char* cs)const{cout<<cs<<endl;exit(1);}
  public:
    enum{SPARE_MAX=16};                //枚举常量表示数组最小长度
    explicit Vector(int n=0):size(0),max(n+SPARE_MAX){if(max>0)data=new T[max];}
    Vector(const Vector& v):data(NULL),max(0){operator=(v);}          //复制构造函数
    ~Vector(){delete[]data;}
    Vector& operator=(const Vector<T>& v);                            //复制赋值函数
    T& operator[](int id){return data[id];}                           //下标运算符函数
    const T& operator[](int id)const{return data[id];}                //常量型下标运算符函数
    bool Empty()const{return size==0;}
    int Sizeof()const{return size;}
    int Max()const{return max;}
    void Clear(){size=0;}

    typedef T* iterator;                                              //迭代器
    typedef const T* const_iterator;                                        //const型迭代器
    iterator Begin(){return data;}                                    //返回左边界的指针,return &data[0];
    const_iterator Begin()const{return data;}
    iterator End(){return data+size;}                                 //返回右边界的指针,return &data[size];(实际上返回的最后一个数据后一位的地址空间)
    const_iterator End()const{return data+size;}

    const T& Front()const{return data[0];}                            //返回首指针的引用
    T& Front(){return data[0];}
    const T& Back()const{return data[size-1];}                        //返回尾指针的引用
    T& Back(){return data[size-1];}
    void Push_back(const T& item){data[size++]=item;}                 //尾插 相当于InsertRear
    void Pop_back(){size--;}                                          //尾删
    void Reserve(int newMax);                                         //扩大数组容量尾newMax,保留原来数据
    void Resize(int newSize,const T& item=T());                       //把数据个数增加为newSize,保留原来数据，其余的值为item
    iterator Insert(iterator itr,const T& item);                      //在迭代器iterator的位置上插入item
    iterator Erase(iterator itr);                                     //在迭代器iterator的位置上删除元素
    iterator operator++();
    iterator operator--();
};
template<class T>
Vector<T>& Vector<T>:: operator=(const Vector<T>& v)                            //复制赋值函数
{
  if(max!=v.max)
  {
    delete[]data;
    max=v.max;
    data=new T[max];
  }
  size=v.size;
  for(int i=0;i<size;++i)
    data[i]=v.data[i];
  return *this;
}

template<class T>
void Vector<T>:: Reserve(int newMax)                                         //扩大数组容量尾newMax,保留原来数据
{
  if(newMax<max)                                                             //如果数组容量已满,则返回
    return;
  T* old=data;                                                               //保留原数组
  data=new T[newMax];                                                        //重新分配新数组
  for(int i=0;i<size;++i)
    data[i]=old[i];
  max=newMax;
  delete[]old;
}

template<class T>
void Vector<T>:: Resize(int newSize,const T& item)                       //把数据个数增加为newSize,保留原来数据，其余的值为item
{
  if(newSize>max)
    Reserve(newSize*2+1);
  for(int i=size;i<newSize;++i)
    data[i]=item;
  size=newSize;
}

template<class T>                                                     //把元素item插入到迭代器itr的位置
typename Vector<T>::iterator Vector<T>::Insert(iterator itr,const T& item)
{
  if(size==max)
    Reserve(2*max+1);                                                 //如果数据空间已满，就先扩大容量
  for(iterator p=data+size,q=data+size-1;p!=itr;--p,--q)
    *p=*q;
  *itr=item;
  size++;
  return itr;
}

template<class T>                                                     //模板参数表
typename Vector<T>::iterator Vector<T>::Erase(iterator itr)                                        //删除指示器指向的元素
{
  for(iterator p=itr,q=itr+1;q!=data+size;++p,++q)
    *p=*q;
  size--;
  return itr;
}



//Pair
template<class T1,class T2>
class Pair
{
  public:
    T1 first;
    T2 second;
    Pair(const T1& f= T1(), const T2& s = T2()):first(f),second(s){}
    Pair(const Pair& pa): first(pa.first),second(pa.second){}
    bool operator==(const Pair& pa);                                  //两个Pair对象的first和second依次相等
    bool operator<(const Pair& pa);                                   //按字典顺序比较Pair的两个对象
};

template<class T1, class T2>
bool Pair<T1,T2>:: operator==(const Pair& pa)
{return first==pa.first&&second==pa.second;}

template<class T1, class T2>
bool Pair<T1,T2>:: operator<(const Pair& pa)
{return first<pa.first||(!(first<pa.first)&&second<pa.second);}

template<class T1, class T2>                                          //以f和s创建一个新的Pair对象
Pair<T1,T2>Make_pair(const T1& f , const T2& s)
{
  return Pair<T1,T2>(f,s);
}

#endif
