#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void swap(char &a, char &b)
{
  char temp=a;
  a = b;
  b = temp;
}

void sort_bubble_char(char* arr, int len)
{
  for(int i=(len-1); i>0; i--)
    for(int j=0; j<i; j++)
    {
      if(arr[j]>arr[j+1])
      {
	swap(arr[j], arr[j+1]);
      }
    }
}

const int max_buf_size=256;


void spell_longest_word(char* dict_fn, char* letters)
{
  int letters_len=strlen(letters);
  sort_bubble_char(letters, strlen(letters));
  //printf("%s\n", letters);
  
  char buf[max_buf_size];
  FILE *dict_fp=fopen(dict_fn, "r");
  if(!dict_fp)
  {
    printf("Open file: %s failed\n", dict_fn);
    exit(0);
  }

  int slen=0;
  int maxlen=0;
  char longest_wd[max_buf_size];
  char wd[max_buf_size];

  while(!feof(dict_fp))
  {
    memset(buf, 0, max_buf_size);
    if(fgets(buf, max_buf_size, dict_fp)!=NULL)
    {
      slen=0;
      //printf("%d:%s", strlen(buf), buf);
      buf[strlen(buf)-1]='\0';
      memset(wd, 0, max_buf_size);
      strcpy(wd, buf);
      sort_bubble_char(buf, strlen(buf));
      int word_len=strlen(buf);
      if(word_len> letters_len)
	continue;
      for(int i=0, j=0; i< word_len && j< letters_len;)
      {
	if(buf[i]==letters[j])
	{
	  i++;
	  j++;
	  slen++;
	}
	else if(buf[i]>letters[j])
	{
	  j++;
	}
	else
	{
	  slen=0;
	  break;
	}
      }
      printf("%s\t%d\n", wd, slen);
      if(slen>maxlen)
      {
	strcpy(longest_wd, wd);
	maxlen=slen;
      }

    }
  }
  fclose(dict_fp); 
  printf("longest word: %s\t%d\n", longest_wd, maxlen);
}



int main(int argc, char**argv)
{
  char letters[]= {'a', 'e', 'f', 'f', 'g', 'i', 'r', 'q'};
  char *dict_fn="dict.txt";
  spell_longest_word(dict_fn, letters);
}
