#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/*
 * KMP字符窜匹配算法,时间复杂度为O（max(m,n)）
 */

#define  SIZE_OF_P    50
int main(int argc,char* argv[])
{
    int j,i;
    int P[SIZE_OF_P];
    char A[] = "abhalfhsdfosdaldfiafhakdfhsdufaoopdfaifhadfhasabab";
    char B[] = "faoopdf";
    int len_A = strlen(A);
    int len_B = strlen(B);
    /*
     * 字符窜的自匹配的过程:获得P数组以便后边进行窜匹配的时候使用
     * 本质上寻找字符窜开始处到某一个位置的一段字粗窜中头和尾的最大相似长度
     */
    j=-1;
    P[0]=-1;
    for(i=1;i<len_B;i++)
    {
        while((j>=0)&&(B[j+1]!=B[i]))
            j=P[j];
        if(B[j+1]==B[i])
            j=j+1;
        P[i]=j;
    }

    //利用获得的数组P进行窜匹配
    j=-1;
    for(i=0;i<len_A;i++)
    {
        while (j>=0&&A[i]!=B[j+1])
            j=P[j];
        if(A[i]==B[j+1])
            j=j+1;
        if(j==len_B-1)
        {
            printf("%d\n",i);
            break;
        }
    }
    return 0;
}
