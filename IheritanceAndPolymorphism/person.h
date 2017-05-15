#ifndef PERSON_H
#define PERSON_H

#include"date.h"
#include<cstring>
#include<vector>
using namespace std;

class Person
{
  protected:
    int idno;                                 //身份证号
    Date btdate;                              //出生日期
  public:
    Person(int id=130000,const Date& bt=Date(12,31,1990)):idno(id),btdate(bt){}
    virtual void Display(){cout<<idno<<endl;btdate.Display();}
};

class People
{
  private:
    string name;
    string gender;
    int years;
  public:
    People(const string& na="",const string& gend="m",int ye=0):name(na),gender(gend),years(ye){}
    virtual~People(){}
    virtual void Display(){cout<<"姓名："<<name<<"\n"<<"性别："<<gender<<"\n"<<"年龄："<<years<<endl;}

    virtual string Get_name(){return name;}
    virtual string Get_gender(){return gender;}
    virtual int Get_years(){return years;}
    
    virtual void Set_name(string na){name=na;}
    virtual void Set_gender(string ge){gender=ge;}
    virtual void Set_years(int yr){years=yr;}
};
#endif
