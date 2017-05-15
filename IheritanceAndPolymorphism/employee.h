#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include"person.h"
class Employee:public Person                        //派生类
{
  private:
    double salary;                                    //工资
  public:
    Employee(int id,const Date& bt,double s):Person(id,bt),salary(s){}
    void Display();
};

void Employee:: Display()
{
  cout<<idno<<endl;
  btdate.Display();
  cout<<salary<<endl;
}
class Teacher:public People
{
  private:
    double id;
    string profession;
    double salary;
  public:
    Teacher(const string& na,const string& gend,int ye,double i=100000,const string& pro="教授",double s=1000):People(na,gend,ye),id(i),profession(pro),salary(s){}
    virtual~Teacher(){}
    virtual void Display(){People::Display();cout<<"工号："<<id<<"\n"<<"职称："<<profession<<"\n"<<"工资："<<salary<<endl;}

    virtual double Get_id(){return id;}
    virtual string Get_profession(){return profession;}
    virtual double Get_salary(){return salary;}

    virtual void Set_id(double i){id=i;}
    virtual void Set_profession(string pro){profession=pro;}
    virtual void Set_salary(double sa){salary=sa;}
};
class Student:public People
{
  private:
    double id;
    string grade;
    string majo;
    double mark;
  public:
    Student(const string& na,const string& gend,int ye,double i=100000,const string& gra="freshman",const string& maj="Math",double mar=590):People(na,gend,ye),id(i),grade(gra),majo(maj),mark(mar){}
    virtual void Display(){People::Display();cout<<"学号："<<id<<"\n"<<"年级："<<grade<<"\n"<<"专业："<<majo<<"\n"<<"入学成绩："<<mark<<endl;}
};

#endif
