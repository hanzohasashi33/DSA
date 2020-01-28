#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>


struct node
{
    int data;
    struct node* next; 
};

void insert_at_beg(struct node**, int);
void print(struct node**);
int check(char*, char*, int);


void print(struct node** head)
{
    struct node* temp = *head;
    while (temp!=NULL)
    {
        printf("%d ",temp->data);
        temp = temp->next;
    }
}


void insert_at_beg(struct node** head, int data)
{
    struct node* temp = malloc (sizeof(struct node*));
    temp->data = data;
    temp->next = NULL;
    if (*head==NULL) // empty list
    *head = temp;
    else
    {
        temp->next = *head;
        *head = temp;
    }
}


int check(char* str1, char* str2, int l)
{
    int p = 997;
    struct node* array[p];
    int l_str1 = strlen(str1);
    int l_str2 = strlen(str2);
    int i,j,k,c=0;
    
    for (i=0; i<= l_str2 - l; i++)
    {
        int sum=0;
        for (j=0; j < l; j++)
            sum = sum + (str2[i+j]-'0') * pow(2,l-1-j);
        
        int remainder = sum % p;
        
        insert_at_beg(&array[remainder],i);
        
    }
    
    for (i=0; i<= l_str1 - l; i++)
    {
        int sum1=0;
        for (j=0; j < l; j++)
            sum1 = sum1 + (str1[i+j]-'0') * pow(2,l-1-j);
        
        int remainder = sum1 % p;
        struct node* temp = array[remainder];
        while (temp!=NULL)
        {
            int sum2=0;
            int index = temp->data;
            int c = l-1;
            for (int i=index; i<l+index;i++)
                sum2 = sum2 + (str2[i]-'0') * pow(2,c--);
            
            if (sum1==sum2)
            {
                printf("Match found at %d of str2\n",index);
                return 1;
            }
            temp = temp->next;
        }
    }
    return -1;
}


int main()

{
    char *str1,*str2;
    scanf("%s%s",str1,str2);
    int f = 0;
    int r = strlen(str1);
    int length;
    
    while (f <= r)
    {
        int l = (f+r)/2;
        if (check(str1, str2, l)==1 && check(str1, str2, l+1)!=1)
        {
            length = l;
            break;
        }    
        else if (check(str1, str2, l)==1)
            f = l+1;
        else
            r = l-1;
    }

    printf("%d",length);
            
    return 0;
    
}