#ifndef DATE_H
#define DATE_H

#include<iostream>
#include<stdlib.h>
using namespace std;

class Date
{
  private:
    int yr,mo,da;
  public:
    Date(int y=0,int m=0,int d=0){yr=y;mo=m;da=d;}
    void Display(){cout<<mo<<'/'<<da<<'/'<<yr<<endl;}
};

#endif
