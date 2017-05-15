#ifndef LIST_H
#define LIST_H

#include<iostream>
#include<stdlib>
using namespace std;

template<class T>
class List
{
  struct Node
  {
    T data;
    Node *prev, *next;
    Node(const T &d = T(), Node * p = NULL , Node * n = NULL):data(d), prev(p), next(n){}
  };

}

#endif
