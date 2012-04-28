#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define  random(x)   (rand()%x)

#define Maxsize   100001

typedef struct {
    int key;
} Element;

typedef struct {
    Element elements[Maxsize+1];
    int n;
} HEAP;

void Create_Heap(HEAP *heap)
{
    heap->n = 0;
}

int  Heap_is_empty(HEAP heap)
{
    if(!heap.n)
        return 1;
    else
        return 0;
}

int  Heap_is_full(HEAP heap)
{
    if(heap.n==Maxsize)
        return 1;
    else
        return 0;
}

void Insert(HEAP* heap,Element element)
{
    int i;
    i = heap->n+1;
    if(!Heap_is_full(*heap))
    {
        while((i!=1)&&(element.key>heap->elements[i/2].key))
        {
            heap->elements[i]=heap->elements[i/2];
            i/=2;
        }
        heap->elements[i]=element;
        heap->n++;
    }
    else
    {
        printf("heap is full\n");
        exit(0);
    }
}

Element Delete(HEAP *heap)
{
   Element element,tmp;
   int parent = 1;
   int child = 2;
   if(!Heap_is_empty(*heap))
   {
       element = heap->elements[1];
       tmp = heap->elements[heap->n--];
       while(child<=heap->n)
       {
           if((child<heap->n)&&(heap->elements[child].key<heap->elements[child+1].key))
           {
               child++;
           }
           if(heap->elements[child].key<tmp.key)
               break;
           heap->elements[parent]=heap->elements[child];
           parent = child;
           child=child*2;
       }
       heap->elements[parent]=tmp;
       return element;
   }else
   {
       printf("heap is empty\n");
       exit(0);
   }
}
int main(int argc,char* argv[])
{
    HEAP myheap;
    Create_Heap(&myheap);

    int i;
    srand((int)time(0));
    Element element;
    for (i=0;i<100000;i++)
    {
        element.key = random(1000);
        Insert(&myheap,element);
    }
    printf("%d\n",myheap.n);
    for(i=0;i<100000;i++)
    {
        printf("%d ",Delete(&myheap).key );
    }
    printf("\n");
    return 0;
}

