#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define prime 599


struct node 
{
    int data;
    struct node * next;
};


//setting everything to null
struct node * hasharray[prime] = {0};


int hashvalue(int key)
{
    return key%prime;
}




void insertatbeg(struct node ** head,int key)
{
    struct node * temp = malloc(sizeof(struct node));
    temp->data = key;
    temp->next = *head;
    *head = temp;
}


void printlist(struct node * head)
{
    while(head != NULL)
    {
        printf("%d",head->data);
        head = head->next;
    }
    printf("\n");
}




void traverse(struct node *head,char *txt,char *ptn,int n,int m)
{
    while (head != NULL)
    {
        for(int i = head->data,k = 0;k < m;k++)
        {
            if(txt[i + k] != ptn[k])
            {
                break;
            }
        }
        printf("There is a match at %d.\n",head->data);
        head = head -> next;
    }
}


int main()
{
    char *txt = (char *)malloc(sizeof(char) * 1000000);
    char *ptn = (char *)malloc(sizeof(char) * 1000000);
    scanf("%s",txt);
    scanf("%s",ptn);


    int n = strlen(txt);
    int m = strlen(ptn);


    for(int k = 0;k < n;k++)
    {
        txt[k] -= '0';
    }
    for(int k = 0;k < m;k++)
    {
        ptn[k] -= '0';
    }



    int txthash = txt[0];
    int ptnhash = ptn[0];
    int x = 2;

    for(int j = 1;j < m;j++)
    {
        x = hashvalue(x * 2);
        ptnhash = hashvalue(ptnhash * 2 + ptn[j]);
        txthash = hashvalue(txthash * 2 + ptn[j]);
    }
    int requiredhash = ptnhash;
    printf("%d\n",requiredhash);
    printf("%d\n",txthash);

    insertatbeg(&hasharray[txthash],0);
    

    for(int i = 1;i < n - m + 1;i++)
    {
        txthash = hashvalue(txthash * 2 + txt[i + m - 1] - (x * txt[i - 1]));
        insertatbeg(&hasharray[txthash],i);
    }

    printlist(hasharray[requiredhash]);
    traverse(hasharray[requiredhash],txt,ptn,n,m);
    return 0;
}