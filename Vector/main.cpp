#include"Vector.h"
#include"stringclass.h"
template<class Iterator>
void display_Vector(Iterator first,Iterator last);

int main()
{
  /*
  //constructor,Insert,Erase
  Vector<int>V;
  int item;
  cout<<"input 10 integers:\n";
  for(int i=0;i<10;++i)
  {
    cin>>item;
    V.Push_back(item);
  }
  Vector<int>:: iterator itr=V.Begin();
  cout<<"after operator++:"<<endl;
  cout<<*(++itr)<<endl;
  cout<<"after operator--():"<<endl;
  cout<<*(--itr)<<endl;
  V.Erase(itr);
  cout<<"after erasing the first:"<<endl;
  display_Vector(V.Begin(),V.End());

  V.Pop_back();
  cout<<"after erasing the last:"<<endl;
  cout<<V.Front()<<endl;
  cout<<V.Back()<<endl;

  //copyconstructor,operator=,Reserve,Resize,operator[]
  Vector<int>V1=V;
  V1.Reserve(20);
  V1.Resize(20,5);
  for(int i=0;i<V1.Sizeof();++i)
    V1[i]++;
  cout<<"after Reserve(20),Resize(20,5) and adding(1):"<<endl;
  display_Vector(V1.Begin(),V1.End());
  */
  typedef Pair<String,int>tyPair;
  tyPair p;
  Vector<tyPair>v;
  v.Push_back(Make_pair<String,int>("Math",100));
  v.Push_back(Make_pair<String,int>("English",99));
  v.Push_back(Make_pair<String,int>("biology",98));
  Vector<tyPair>::iterator iter;
  iter=v.Begin();
  for(int i=1;iter!=v.End();++iter)
  {
    cout<<"The "<<i<<"th String:"<<iter->first<<"\n"<<"The "<<i<<"th integer:"<<iter->second<<endl;
    ++i;
  }
  return 0;
}
/*template<class Iterator>
void display_Vector(Iterator first,Iterator last)
{
  for(;first!=last;++first)
    cout<<*first<<'\t';
  cout<<endl;
}*/
