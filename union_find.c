#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define   SIZE  1000
int father[SIZE];
int rank[SIZE];

//这个函数实现非常巧妙，具体跑了两遍，第一遍从叶子节点跑到根节点，目的是为了寻找到根节点，第二遍是从新回朔到叶子节点，目的是更新每个节点，使之能够直接指向根。
int find(int x)
{
    if(father[x]==x)
        return x;
    else 
        return father[x]=find(father[x]);
}

void merge(int x,int y)
{
    int a = find(x);
    int b = find(y);
    if(rank[a]>rank[b])
        father[b]=a;
    else
    {
        father[a]=b;
        if(rank[a]==rank[b])
            rank[b]++;
    }
}

int main(int argc,char* argv[])
{
    memset(rank,0,sizeof(rank));
    int i;
    for(i=1;i<SIZE;i++)
        father[i]=i;
    for (i=3;i<SIZE;i+=2)
    {
        merge(1,i);
    }
    for (i=4;i<SIZE;i+=2)
    {
       merge(2,i); 
    }
    for(i=1;i<SIZE;i++)
    {
        if(find(i)==find(1))
            printf("%d ",i);
    }
    printf("\n");
    for(i=1;i<SIZE;i++)
    {
        if(find(i)==find(2))
            printf("%d ",i);
    }
    printf("\n");
    return 0;
}
