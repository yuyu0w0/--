#include <stdio.h>
#include <string.h>
#include <time.h>
int MaxSubSequenceSum(const int A[], int N)
{
    int ThisSum, MaxSum, i, j, k;
    MaxSum = 0;
    for(i=0;i< N ;i++)
    {
        ThisSum = 0;
        for(j=i;j< N ;j++)
        {
        	ThisSum += A[j];
			if(ThisSum > MaxSum)
			{
				MaxSum = ThisSum;
			}                                                                             
        }
    }
    return MaxSum;
}
int main()
{
    clock_t start,end;
    double time;
    int n,i,result;
    printf("输入数据数");
    scanf("%d",&n);
    int a[n];
    for(i = 0;i < n;i++)
    {
        scanf("%d",&a[i]);
    }
    start = clock();
    result=MaxSubSequenceSum(a,n);
    end = clock();
    time = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("最大子序列和为 %d \n",result);
    printf("用时为 %f秒 \n",time);
}
