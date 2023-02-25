#include<stdio.h>
#include"node.h"

extern int * Arr[N];
extern int Num_Elements[N];


void PrintArr()
{
  for(int i=0; i<N; i++)
  {
     for(int j = 0; j < Num_Elements[i]; j++)
       printf(" %d ", Arr[i][j]);
     printf("\n");
  }
}

int main()
{

}
  

  
