#include<stdio.h>
#include<stdlib.h>
int main(int argc, char**argv)
{
  char word[]="hello";
  int gap=int(word[0] - 'a');
  printf("%d %d %d\n", int(word[0]), int('a'), gap);
  return 1;
}
