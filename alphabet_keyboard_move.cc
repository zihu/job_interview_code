#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void output_move(char* word, int len)
{
  printf("word:%s, len:%d\n, size: %d\n", word, len, sizeof(word));
  int posr=0;
  int posc=0;
  int curposr=0;
  int curposc=0;
  int i=0;
  for (i=0; i< len; i++)
  {
    posc=int(word[i]-'a')/5;
    posr=int(word[i]-'a')%5;
    int j=0;
    int rmovcount= posr-curposr;
    int cmovcount= posc-curposc;
    char rmov, cmov;
    if(rmovcount<0)
      rmov='l';
    else
      rmov='r';

    if(cmovcount<0)
      cmov='u';
    else
      cmov='d';

    for(j=0; j<abs(rmovcount); j++)
      printf("%c", rmov);
    for(j=0; j<abs(cmovcount); j++)
      printf("%c", cmov);
    printf("i");
    curposr=posr;
    curposc=posc;
  }
  printf("\n");
}

int main (int argc, char**argv)
{
  char word[]="hello";
  output_move(word, strlen(word));
  printf("word:%s, len:%d\n, size: %d\n", word, strlen(word), sizeof(word));

  return 1;
}
