#include<stdio.h>
#include<stdlib.h>
#include<string.h>
bool is_bst(int*tree, int len)
{

  return false;
}

int main(int argc, char**argv)
{
  int tree[]={8,3,10,1,6,14,0,4,7,13,20};
  int len = sizeof(tree)/sizeof(int);
  if(is_bst(tree, len))
    printf("Binary search tree\n");
  else
    printf("Not binary search tree\n");
  return 0;
}


