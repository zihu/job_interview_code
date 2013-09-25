#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void swap(int &a, int &b)
{
  int temp=a;
  a = b;
  b = temp;
}

void swap(char &a, char &b)
{
  char temp=a;
  a = b;
  b = temp;
}

void merge_arr(int* partA, int lenA, int*partB, int lenB)
{
  int lenT=lenA+lenB;
  int *arrT=new int[lenT];
  int ai=0; 
  int bi=0;
  for(int i=0; i< lenT; i++)
  {
    if(ai< lenA && bi< lenB)
    {
      if(partA[ai]<partB[bi])
      {
	arrT[i]=partA[ai];
	ai++;
      }
      else
      {
	arrT[i]=partB[bi];
	bi++;
      }
    }
    else if(ai>=lenA)
    {
      arrT[i]=partB[bi];
      bi++;
    }
    else
    {
      arrT[i]=partA[ai];
      ai++;
    }
  }
  memcpy(partA, arrT, lenT*sizeof(int));
  delete [] arrT;
}

void sort_merge(int* arr, int len)
{
  if(len==1)
    return;
  if(len==2)
  {
    if(arr[0]>arr[1])
    {
      swap(arr[0], arr[1]);
    }
  }
  else
  {
    sort_merge(arr, (len+1)/2);
    sort_merge(arr+(len+1)/2, len/2);
    merge_arr(arr, (len+1)/2, arr+(len+1)/2, len/2);
  }
}

void sort_quick(int *arr, int start, int end)
{
  int len = end-start+1;
  //base case:
  if(len<=1)
    return;

  if(len==2)
  {
    if(arr[start]>arr[end])
    {
      swap(arr[start], arr[end]);
    }
    return;
  }

  //choose pivot;
  int pivot = arr[start+len/2];
  int ai=start;
  int bi=end;

  //partition;
  while(ai<= bi)
  {
    while(arr[ai]<pivot)
      ai++;
    while(arr[bi]>pivot)
      bi--;
    if(ai<=bi)
    {
      swap(arr[ai], arr[bi]);
      ai++;
      bi--;
    }
  }
  
  //recursive sort;
  sort_quick(arr, start, bi);
  sort_quick(arr, ai, end);
  return;
}

void sort_bubble(int* arr, int len)
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


void sort_naive(int* order, char* str, int len)
{
  for (int i=0; i< len; i++)
    printf("%d\t", order[i]);
  printf("\n");

  for(int i=(len-1); i>0; i--)
    for (int j=0; j< i; j++)
    {
      if(order[j]>order[j+1])
      {
	char temp = str[j];
	str[j]=str[j+1];
	str[j+1] = temp;
	int temp2 = order[j];
	order[j]=order[j+1];
	order[j+1]=temp2;
      }
    }
  printf("str: %s\n", str);
}

void sort_str_dict(char* str, char* dict)
{
  //build the letter to index map:
  int number_of_letter =strlen(dict);
  int *char_2_index=new int [number_of_letter];
  memset(char_2_index, 0, number_of_letter);
  for(int i=0; i< number_of_letter; i++)
  {
    int offset = int(dict[i]-'a');
    char_2_index[offset]=i; 
  }

  int str_len=strlen(str);
  int order[str_len];
  for(int i=0; i< str_len; i++)
  {
    order[i]=char_2_index[int(str[i]-'a')];
  }
  sort_naive(order, str, str_len);
  delete [] char_2_index;
}


void quickSort(int arr[], int left, int right) 
{
  int i = left, j = right;
  int tmp;
  int pivot = arr[(left + right) / 2];
		     
  /* partition */
  while (i <= j) 
  {
    while (arr[i] < pivot)
      i++;
    while (arr[j] > pivot)
      j--;
    if (i <= j) 
    {
      tmp = arr[i];
      arr[i] = arr[j];
      arr[j] = tmp;
      i++;
      j--;
    }
  }
			   
  /* recursion */
  if (left < j)
    quickSort(arr, left, j);
  if (i < right)
    quickSort(arr, i, right);
}

int main(int argc, char**argv)
{
  char str[]="hello";
  char dict[]="djqwertyuioplkhgfsazxcvbnm";
  printf("strlen: %lu\t sizeof: %lu\n", strlen(dict), sizeof(dict));
  printf("dict: %s\n", dict);
  printf("str: %s\n", str);
  sort_str_dict(str, dict);
  int arr[]={2,3,9,1,0,6, 20, 22, 8, 5, 40, 100, 7};

  //int arr[]={2,3,1,0,6, 20, 22, 8};
  printf("arr size: %lu, int size: %lu,  len: %lu\n", sizeof(arr), sizeof(int), sizeof(arr)/sizeof(int));
  //sort_bubble(arr, sizeof(arr)/sizeof(int));
  //sort_merge(arr, sizeof(arr)/sizeof(int));

  sort_quick(arr, 0, (sizeof(arr)/sizeof(int)-1));
  //quickSort(arr, 0, (sizeof(arr)/sizeof(int)-1));
  for(int i=0; i<( sizeof(arr)/sizeof(int)); i++)
    printf("%d\n", arr[i]);

  //sort_bubble_char(dict, strlen(dict));
  //printf("%s\n", dict);

}


