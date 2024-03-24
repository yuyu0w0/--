#include <stdio.h>
#include <string.h>
#include <time.h>
#include <limits.h> 
int max(int a, int b) {
    return (a > b) ? a : b;
}

int maxCrossingSum(int arr[], int l, int m, int h) {
    int sum = 0;
    int left_sum = INT_MIN;
    for (int i = m; i >= l; i--) {
        sum += arr[i];
        if (sum > left_sum) {
            left_sum = sum;
        }
    }

    sum = 0;
    int right_sum = INT_MIN;
    for (int i = m + 1; i <= h; i++) {
        sum += arr[i];
        if (sum > right_sum) {
            right_sum = sum;
        }
    }

    return max(left_sum + right_sum, max(left_sum, right_sum));
}

int maxSubArraySum(int arr[], int l, int h) {
    if (l == h) {
        return arr[l];
    }

    int m = (l + h) / 2;

    return max(max(maxSubArraySum(arr, l, m), maxSubArraySum(arr, m + 1, h)), maxCrossingSum(arr, l, m, h));
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
    result=maxSubArraySum(a, 0, n-1);
    end = clock();
    time = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("最大子序列和为 %d \n",result);
    printf("用时为 %f秒 \n",time);
}
