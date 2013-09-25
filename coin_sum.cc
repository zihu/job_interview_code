#include<stdio.h>
#include<stdlib.h>
#include<string.h>
//OPT(N, SUM)=min(OPT(N-1, SUM), 1+OPT(N-1, SUM-V[i]))
#define min(a, b) (a)>(b)?(b):(a)
#define MAX_INT 65535

int coins[]={1,2,5,10};
int len = sizeof(coins)/sizeof(int);
/*
int minimum_coins(int sum, int index)
{
  if(sum == 0)
    return 0;

  if(index<0)
  {
    return MAX_INT;
  }
  if(sum<0)
  {
    return MAX_INT;
  }
  return min((minimum_coins(sum, index-1)), (1+minimum_coins(sum-coins[index], index-1)));
  //return min((minimum_coins(sum, index+1)), (1+minimum_coins(sum-coins[index], index+1)));
}
*/

int minimum_coins(int sum, int index)
{
  int rslt[index][sum+1]; 
  for(int i=0; i< index; i++)
    for(int j=0; j<= sum; j++)
    {
      rslt[i][j] = MAX_INT;
      if(j==0)
	rslt[i][j] = 0;
      if(i==0 && j==coins[i])
	rslt[i][j] = 1;
    }

  for(int i=1; i< index; i++)
    for(int j=1; j<= sum; j++)
    {
      if(j<coins[i])
      {
	if(i-1>=0)
	  rslt[i][j]=rslt[i-1][j];
      }
      else
      {
	if(i-1>=0)
	  rslt[i][j]=min(rslt[i-1][j], 1+rslt[i-1][j-coins[i]]);
      }
      printf("%d\t%d\t%d\n", i, j, rslt[i][j]);
    }
  return rslt[index-1][sum];
}


int combin_coins(int value, int max)
{
  if(value<0)
    return 0;
  if(value == 0)
    return 1;
  if(max>=25) 
    return combin_coins(value-1, 1)+combin_coins(value-5, 5)+combin_coins(value-10, 10)+combin_coins(value-25, 25);
  else if(max>=10)
    return combin_coins(value-1, 1)+combin_coins(value-5, 5)+combin_coins(value-10, 10);
  else if(max>=5)
    return combin_coins(value-1, 1)+combin_coins(value-5, 5);
  else if(max>=1)
    return combin_coins(value-1, 1);
  else
    return 0;
}

int main(int argc, char**argv)
{
  /*
  if(argc<2)
  {
    printf("usage: %s sum\n", argv[0]);
    return -1;
  }
  int sum=atoi(argv[1]);
  int len = sizeof(coins)/sizeof(int);
  printf("num coins: %d, sum: %d\n", len, sum);
  minimum_coins(coins, len, sum);
  */
  /*
  int value=100;
  int n=combin_coins(value, 25);
  printf("value: %d, combination:%d\n", value, n);
  */
  int value=11;
  int n=minimum_coins(value, len);
  printf("value: %d, combination:%d\n", value, n);
  return 0;
}


