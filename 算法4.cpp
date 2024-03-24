#include <stdio.h>
#include <string.h>
#include <time.h>
#include <limits.h> 
int MaxSubSequenceSum(const int A[],int N)
{
	int ThisSum, MaxSum, j;
	ThisSum = MaxSum = 0;
	for(j = 0; j < N; j++)
	{
		ThisSum += A[j];
		if(ThisSum > MaxSum)
		{
			MaxSum = ThisSum;
		}
		else
		{
			if(ThisSum < 0)
			ThisSum = 0;
		}
	}
	return MaxSum;	
} 
int main()
{
    clock_t start,end;
    double time;
    int n,i,result;
    printf("����������");
    scanf("%d",&n);
    int a[n];
    for(i = 0;i < n;i++)
    {
        scanf("%d",&a[i]);
    }
    start = clock();
    {
    	result=MaxSubSequenceSum(a,n);
	}
    end = clock();
    time = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("��������к�Ϊ %d \n",result);
    printf("��ʱΪ %f�� \n",time);
}
