#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>


struct node
{
  int data;
  struct node * next;
};


struct node * head = NULL;
struct node * head1 = NULL;

void insertatbeg(struct node ** head,int key)
{
  struct node * temp = (struct node *)malloc(sizeof(struct node));
  temp->data = key;
  temp->next = *head;
  *head = temp;
}



void makecircular(struct node *head1,int index)
{
  struct node * temp = head1;
  struct node * temp1 = head1;
  while(temp -> next != NULL)
  {
    temp = temp->next;
  }

  for(int i = 0;i < index;i++)
  {
    temp1 = temp1->next;
  }
  temp->next = temp1;
}




bool FCDA(struct node * p1,struct node * p2)
{
  while(p2 != NULL)
  {
    p1 = p1->next;
    p2 = p2->next;
    if(p2 != NULL)
    {
      p2 = p2->next;
    }
    else 
    {
      return false;
    }
    if(p1 == p2)
    {
      return true;
    }
  }
  return false;
}




int main()
{
  int arr[] = {1,2,3,4,5,6,7,8,9,10};
  int n = sizeof(arr)/sizeof(arr[0]);
  for(int i = 0;i < n;i++)
  {
    insertatbeg(&head, arr[i]);
  }
  for(int i = 0;i < 9;i++)
  {
    insertatbeg(&head1, arr[i]);
  }
  makecircular(head1, 5);
  struct node * p1 = (struct node *)malloc(sizeof(struct node));
  struct node * p2 = (struct node *)malloc(sizeof(struct node));
  struct node * p3 = (struct node *)malloc(sizeof(struct node));
  struct node * p4 = (struct node *)malloc(sizeof(struct node));
  p1 = head1;
  p2 = head1;
  p3 = head;
  p4 = head;
  bool b = FCDA(p1, p2);
  bool b1 = FCDA(p3,p4);
  printf("%d\n",b);
  printf("%d\n",b1);
  return 0;
}
