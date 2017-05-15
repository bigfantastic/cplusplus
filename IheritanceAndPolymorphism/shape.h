#ifndef SHAPE_H
#define SHAPE_H

#include<iostream>
using namespace std;
class Shape
{
public:
  virtual double Area()=0;
  virtual void Show()=0;
};
class Triangle:public Shape
{
  double bottom,height;
  virtual double Area()
    {return(bottom*height/2);}
public:
  Triangle(double b,double h):bottom(b),height(h){}
  virtual void Show()
    {cout<<"The area of Triangle="<<Area()<<endl;}
};
class Rectangle:public Shape
{
  double length,width;
  virtual double Area()
    {return(length*width);}
public:
  Rectangle(double l,double w):length(l),width(w){}
  virtual void Show()
    {cout<<"The area of Rectangle="<<Area()<<endl;}
};
class Trapezoide:public Shape
{
  double top,bottom,height;
  virtual double Area()
    {return((top+bottom)*height/2);}
public:
  Trapezoide(double t,double b,double h):top(t),bottom(b),height(h){}
  virtual void Show()
    {cout<<"The area of Trapezoide="<<Area()<<endl;}
};
class Circle:public Shape
{
  double radius;
  virtual double Area()
    {return(3.14159*radius*radius);}
public:
  Circle(double r):radius(r){}
  virtual void Show()
    {cout<<"The area of Circle="<<Area()<<endl;}
};
double Total(Shape* a[],int n)
{
  double t=0;
  for(int i=0;i<n;++i)
    t+=a[i]->Area();
  return(t);
}
#endif
