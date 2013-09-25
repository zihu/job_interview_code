#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<string>
#include<iostream>
#define min(a, b) (a)>(b)?(b):(a)
using namespace std;

int miss_num=0;
int find_missing_number(string nums)
{
  int pos=-1;
  int slen=nums.size();
  if(slen<2)
    return false;

  int hlen=slen/2+1;
  for(int i=1; i<hlen; i++ )
  {
    int fail=0;
    //first number;
    int firn=stoi((nums.substr(0,i)));

    int next = firn+1;
    int j=i;
    printf("***********round %d first: %d****************\n", i, firn);
    while(true)
    {
      string nexts = to_string(next);
      int nindex = nexts.size();
      if(j+nindex > slen)
	break;

      int nextn=stoi(nums.substr(j, nindex)); 
      printf("%d\n", nextn);
      if(nextn == next)
      {
	j+=nindex;
	next += 1;
	continue;
      }
      else
      {
	if(nextn == (next+1))
      	{
	  if(fail==0)
	  {
	    miss_num=next;
	    pos=j;
	  }
	  j+= nindex;
	  next += 2;
      	  continue;
      	}
	else
	{
	  fail+=1;
	  break;
	}
      }

    }
    if(fail==0)
      return pos;
  }
 
  return -1;
}

int main(int argc, char**argv)
{
  //string nums="9899100101103104105";
  string nums="383940383941383943383944";
  printf("%s\n", nums.c_str());
  int pos=find_missing_number(nums);
  if(pos>0)
    printf("%s\t%d\t%s\n", nums.substr(0,pos).c_str(), miss_num, nums.substr(pos,nums.size()-pos).c_str());
  else
    printf("bad string: %s\n", nums.c_str());
  return 0;
}


