#include"employee.h"
int main()
{
  vector<Teacher>T;
  Teacher te("吴晓刚","男",35,19960053,"讲师",5000);
  vector<Student>S;
  string tna,tgend,tpro;
  int tye;
  double tid,tsal;
  cout<<"请输入教师个人信息："<<endl;
  while(1)
  {
    char ch;
    cout<<"姓名:";
    cin>>tna;
    te.Set_name(tna);
    cout<<"性别:";
    cin>>tgend;
    te.Set_gender(tgend);
    cout<<"年龄:";
    cin>>tye;
    te.Set_years(tye);
    cout<<"工号:";
    cin>>tid;
    te.Set_id(tid);
    cout<<"职称:";
    cin>>tpro;
    te.Set_profession(tpro);
    cout<<"工资:";
    cin>>tsal;
    te.Set_salary(tsal);
    cout<<endl;
    T.push_back(te);
    cout<<"Do you want to input another one?y/n:";
    cin.get(ch);
    cin.get(ch);
    if(ch=='n'||ch=='N')
       break;
    cout<<endl;
  }
  vector<Teacher>::iterator itr;
  for(itr=T.begin();itr!=T.end();++itr)
    cout<<"姓名："<<(*itr).Get_name()<<"\n"<<"性别："<<(*itr).Get_gender()<<"\n"<<"年龄："<<(*itr).Get_years()<<"\n"<<"工号："<<(*itr).Get_id()<<"\n"<<"职称："<<(*itr).Get_profession()<<"\n"<<"工资："<<(*itr).Get_salary()<<"\n"<<endl;
  return 0;
}
