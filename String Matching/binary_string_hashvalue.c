#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#define prime 599



int hashvalue(int n)
{
    return n%prime;
}



void rollinghash(char *txt,char *ptn,int n,int m)
{
    int i,j;
    int x = 1;
    int txthash = 0;
    int ptnhash = 0;

    for(i = 0;i < m;i++)
    {
        x = hashvalue(x * 2);
        ptnhash = hashvalue(ptnhash * 2 + ptn[i]);
        txthash = hashvalue(txthash * 2 + txt[i]);
    }
    printf("%d\n%d",txthash,ptnhash);
    if(txthash == ptnhash)
    {
        i = 0;
        for(j = 0;j < m;j++)
        {
            if(txt[i + j] == ptn[j])
            {
                break;
            }
        }
        if(j == m)
        {
            printf("There is a match at index 0.\n");
        }
    }


    for(i = 1;i < n - m + 1;i++)
    {
        txthash = hashvalue(txthash * 2 + txt[i + m - 1] - (x * txt[i - 1]));
        printf("%d\n",txthash);

        if(txthash == ptnhash)
        {
            for(j = 0;j < m;j++)
            {
                if(txt[i + j] != ptn[j])
                {
                    break;
                }
            }
            if(j == m)
            {
                printf("There is a match at index %d.\n",i);
            }
        }
    }
}







int main()
{
    char *txt = (char *)malloc(sizeof(char) * 1000000);
    char *ptn = (char *)malloc(sizeof(char) * 1000000);
    scanf("%s",txt);
    scanf("%s",ptn);

    int i,j;
    int n = strlen(txt);
    int m = strlen(ptn);

    for(i = 0;i < n;i++)
    {
        txt[i] -= '0';
    }
    for(j = 0;j < m;j++)
    {
        ptn[j] -= '0';
    }

    rollinghash(txt,ptn,n,m);
    return 0;
}