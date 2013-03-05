#include<stdio.h>
#include<stdlib.h>
float prob_of_alive(int x, int y, int n)
{
  float prob=1.0;
  if (n==0)
  {
    if((x>=0 && x<5) && (y>=0 && y<5))
      return 1;
    else
      return 0;
  }
  else
  {
    prob=prob*0.25*(prob_of_alive(x-1, y, n-1)+prob_of_alive(x+1, y, n-1)+prob_of_alive(x, y-1, n-1)+prob_of_alive(x, y+1, n-1));
  }
  return prob;
}

int main (int argc, char** argv)
{
  int n=4;
  int x=2;
  int y=2;
  float prob=prob_of_alive(x,y,n);
  printf("prob of alive: %f\n", prob);
}
