#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// this function is paste from network which implement very nice
void quick_sort(int s[],int l,int r)
{
    int i,j,x;
    if(l<r)
    {
        i=l;
        j=r;
        x=s[i];
        while(i<j)
        {
            while(i<j&&s[j]>x) j--;
            if(i<j) s[i++]=s[j];
            while(i<j&&s[i]<x) i++;
            if(i<j) s[j--]=s[i];
        }
        s[i]=x;
        quick_sort(s,l,i-1);
        quick_sort(s,i+1,r);
    }
}
void swap(int *a,int *b)
{
    int temp=*a;
    *a=*b;
    *b=temp;
}
void quick_sort_me(int s[],int l,int r)
{
    int i,j,mid;
    if(l<r)
    {
        printf("hello\n");
        mid = s[(l+r)/2];
        i=l;
        j=r;
        while(i<j)
        {
            while(i<j&&s[i]<mid) i++; //当没有等号的时候，需要判断两边都遇到相等的值的情况，避免每次都在进行交换，导致出现死循环
            while(i<j&&s[j]>mid) j--; //当都加上等号的时候，如果中间树刚好取到最大的值的时候，则每次都递归相同的序列数组。从而导致栈溢出，出现段错误
            if(i<j)
            {
                swap(&s[i],&s[j]);
            }
            /*
               if(i==r)
               {
               swap(&s[(l+r)/2],&s[r]); 
               }
               if(j==l)
               {
               swap(&s[(l+r)/2],&s[l]);
               }
               */
            if(s[i]==s[j])
            {
                j--;
                i++;
            }
        } 
        quick_sort_me(s,l,j-1);
        quick_sort_me(s,i,r);
    }
}
int main(int argc,int argv)
{
    int num[10]={2,10,4,90,1034,4,98,4,-9,0};
    quick_sort_me(num,0,9);
    int i;
    for (i=0;i<10;i++)
    {
        printf("%d ",num[i]);
    }
}
