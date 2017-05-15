#include"shape.h"
int main()
{
  Shape* A[4];
  A[0]=new Triangle(3,4);
  A[1]=new Rectangle(5,8);
  A[2]=new Trapezoide(5,7,8);
  A[3]=new Circle(8);
  for(int i=0;i<4;++i)
    A[i]->Show();
  cout<<"The total area is"<<Total(A,4)<<endl;
  for(int i=0;i<4;++i)
    delete A[i];
  return 0;
} 
