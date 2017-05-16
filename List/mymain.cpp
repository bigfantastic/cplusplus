#include"Vector.h"
#include"Queue.h"
#include"Stack.h"
#include"LinkedPQueue.h"
int main()
{
  Queue<int>Q;
  Stack<int>S;
  cout<<"input 10 integers:\n";
  int item;
  for(int i=0;i<10;++i)
  {
    cin>>item;
    Q.Push(item);
    S.Push(item);
  }
  while(!Q.Empty())
    if(Q.Front()%2==0)
      cout<<Q.Pop()<<'\t';
    else
      Q.Pop();
  cout<<endl;
  while(!S.Empty())
    if(S.Top()%2==0)
      cout<<S.Pop()<<'\t';
    else
      S.Pop();
  cout<<endl;
  PQueue<int>P;
  cout<<"input 5 integers:\n";
  for(int i=0;i<5;++i)
  {
    cin>>item;
    P.Push(item);
  }
  cout<<P.Pop()<<endl;
  return 0;
}
