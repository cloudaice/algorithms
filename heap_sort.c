#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define random(x)   (rand()%x)

#define size   1000
void swap(int *a,int *b)
{
    int temp=*a;
    *a=*b;
    *b=temp;
}
//此时只有fisrt元素是不满足堆的要求的，该函数实现将first元素推到合适的位置，使得满足堆的要求
void pushdown(int first,int last,int A[])
{
    int r = first;
    int k;
    while(r<=last/2)
    {
        if((r==last/2)&&(last%2==0))
        {
            if(A[r]>A[r*2])
                swap(&A[r],&A[r*2]);
            break;
        }
        if(A[r*2+1]<A[r*2])
        {
            k=r*2+1;
        }
        else
        {
            k=r*2;
        }
        if(A[r]<=A[k])
            break;
        swap(&A[r],&A[k]);
        r=k;
    }
}
//对排序的函数实现
void sort(int n,int A[])
{
    int i;
    for(i=n/2;i>=1;i--)
    {
        pushdown(i,n,A);
    }
    for(i=n;i>=2;i--)
    {
        swap(&A[1],&A[i]);
        pushdown(1,i-1,A);
    }
}
int main()
{
    srand(time(0));
    int num[size+1];
    int i;
    for (i=1;i<size+1;i++)
    {
        num[i]=random(size);
    }
    sort(size,num);
    for (i=1;i<size+1;i++)
    {
        printf("%d ",num[i]);
    }
    printf("\n");
    for(i=2;i<size+1;i++)
    {
        if(num[i]-num[i-1]>0)
        {
            printf("error: %d %d\n",num[i],num[i-1]);
            break;
        }
            
    }
    return 0;
}
