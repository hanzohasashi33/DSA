#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>



//structure for linked list
struct node 
{
    int data;
    struct node * next;
};




//function to print the linked list.
void printlinkedlist(struct node * head)
{
    while(head != NULL)
    {
        printf("%d",head->data);
        head = head->next;
    }
    printf("\n");
}




//function to add index at the beginning of the linked list.
void insertatbeg(struct node **head,int value)
{
    struct node * temp = (struct node *)malloc(sizeof(struct node));
    temp->data = value;
    temp->next = NULL;
    if(*head = NULL)              //if the linked list is empty
    {
        *head = temp;
    }
    else                          //else add the index at the beginning of the linked list.
    {
        temp->next = *head;
        *head = temp;
    }
}




int check(char *str1,char *str2,int l)
{
    int prime = 997;
    struct node *hashtable[prime];

    int n = strlen(str1);
    int m = strlen(str2);

    int i,j,k,c = 0;

    for(i = 0;i < m;i++)
    {
        int str2hash = 0;
        for(j = 0;j < l;j++)
        {
            str2hash = str2hash + ((str2[i + j] - '0') * pow(2,l-i-j));
        }
        int remainder = str2hash % prime;
        insertatbeg(&hashtable[remainder],i);
    }

    for(i = 0;i < m;i++)
    {
        int str1hash = 0;
        for(j = 0;j < l;j++)
        {
            str1hash = str1hash + ((str1[i + j] - '0') * pow(2,l-i-j)); 
        }
        int remainder = str1hash % prime;
        
        struct node * temp = hashtable[remainder];
        while(temp != NULL)
        {
            int newhash = 0;
            int index = temp->data;
            int c = l - 1;
            for(int i = index;i < index + l;i++)
            {
                newhash = newhash + ((str2[i] - '0') * pow(2,c--));
            }


            if(str1hash == newhash)
            {
                printf("Match Found.\n");
                return 1;
            }
            temp = temp->next;
        }
    }
    return -1;
}






int main()
{
    char *str1 = (char *)malloc(sizeof(char) * 1000000);
    char *str2 = (char *)malloc(sizeof(char) * 1000000);
    scanf("%s",str1);
    scanf("%s",str2);
    
    int n = strlen(str1);
    int m = strlen(str2);

    int f = 0;
    int r = n;
    int length;


    while(f <= r)
    {
        int l = (f + r)/2;
        if(check(str1,str2,l) == 1 && check(str1,str2,l+1) != 1)
        {
            length = l;
            break;
        }
        else if(check(str1,str2,l) == 1)
        {
            f = l + 1;
        }
        else
        {
            r = l - 1;
        }
    }

    printf("%d",length);
    return 0;
}
