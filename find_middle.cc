#include<stdio.h>
#include<stdlib.h>
#define max(a, b) ((a)>(b)?(a):(b))
#define min(a, b) ((a)<(b)?(a):(b))
float find_median(int A[], int B[], int lenA, int lenB)
{
  printf("A len:%d, B len:%d\n", lenA, lenB);
  int m=0;
  int ai=0;
  int bi=0;
  int posa=0;
  int posb=0;
  int count=0;
  int m_index=int((lenA+lenB-1)/2);
  
  int total_len=lenA+lenB;
  for(int i=0; i< total_len;i++)
  {
    float m=0.0;
    if(ai< lenA && A[ai]<B[bi])
    {
      ai++;
    }
    else if (bi< lenB)
    {
      bi++;
    }

    count++;
    if(count==m_index)
    {
      if(total_len%2!=0)
     {
       if(ai< lenA && bi< lenB)
	 m=(A[ai]>B[bi])? B[bi]:A[ai];
       else if (ai>=lenA)
	 m=B[bi];
       else
	 m=A[ai];
     }
     else
     {
       if (ai< lenA && bi< lenB)
	 m=(float(A[ai]+B[bi]))/2;
       else if (ai >= lenA)
	 m=(float(B[bi]+B[bi+1]))/2;
       else
	 m=(float(A[ai]+A[ai+1]))/2;
     }
     return m; 
    }
  }
}

float get_median(int arr[], int len)
{
  if(len%2==0)
    return float(arr[len/2]+arr[len/2-1])/2;
  else
    return arr[len/2];
}

float find_median_dv(int A[], int B[], int lenA, int lenB)
{
  int m=0;
  int ai=0;
  int bi=0;
  int posa=0;
  int posb=0;
  int count=0;
  float mA=get_median(A, lenA);
  float mB=get_median(B, lenB);

  if(lenA==1) 
  {
    if(lenB %2 ==0)
    {
      if(A[0] >= B[lenB/2-1] && A[0] <=B[lenB/2])
	return A[0];
      else if(A[0]<B[lenB/2-1])
	return B[lenB/2-1];
      else
	return B[lenB/2];
	
    }
    else
    {
      if(A[0]>=B[lenB/2-1] && A[0] <=B[lenB/2+1])
	return float(A[0]+B[lenB/2])/2;
      else if(A[0]<B[lenB/2-1])
	return float(B[lenB/2-1]+B[lenB/2])/2;
      else
	return float(B[lenB/2+1]+B[lenB/2])/2;
    }
  }

  if(lenB==1) 
  {
    if(lenA %2 ==0)
    {
      if(B[0] >= A[lenA/2-1] && A[0] <=A[lenA/2])
	return B[0];
      else if(B[0]<A[lenA/2-1])
	return A[lenA/2-1];
      else
	return A[lenA/2];
    }
    else
    {
      if(B[0]>=A[lenA/2-1] && B[0] <=A[lenA/2+1])
	return float(B[0]+A[lenA/2])/2;
      else if(B[0]<A[lenA/2-1])
	return float(A[lenA/2-1]+A[lenA/2])/2;
      else
	return float(A[lenB/2+1]+A[lenA/2])/2;
    }

  }

  if(lenA==2 && lenB==2)
  {
    return float(max(A[0], B[0])+min(A[1], B[1]))/2;
  }

  if(mA == mB)
    return mA;
  else if(mA>mB)
    return find_median_dv(A, B+((lenB+1)/2-1), lenA/2+1, lenB/2+1);
  else
    return find_median_dv(A+((lenA+1)/2-1), B, lenA/2+1, lenB/2+1);

}


int main(int argc, char**argv)
{
  int A[1]={ 9};
  int B[4]={1, 2, 7, 8};
  float m= find_median_dv(A, B, sizeof(A)/4, sizeof(B)/4);
  printf("median: %f\n", m);
  return 1;
}
