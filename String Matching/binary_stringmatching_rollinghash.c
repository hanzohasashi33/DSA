#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>


void rollinghash(char *txt,char *ptn,int n,int m)
{
    int i,j;
    int txthash = 0;
    int ptnhash = 0;
    int x = 1;
    for(i = 0;i < m;i++)
    {
        x = (x * 2)%599;
        txthash = (txthash * 2 + txt[i])%599;
        ptnhash = (ptnhash * 2 + ptn[i])%599;
    }
    printf("%d ",txthash);
    printf("%d\n",ptnhash);
    if(ptnhash == txthash)
        {
            i = 0;
            for(j = 0;j < m;j++)
            {
                if(txt[i + j] != ptn[j])
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
        
        txthash = ((txthash * 2) + txt[i + m - 1] - (txt[i - 1] * x))%599;
        printf("%d\n",txthash);


        if(ptnhash == txthash)
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
                printf("There is a match at %d.\n",i);
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