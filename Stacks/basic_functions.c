#include <stdio.h>
#include <stdlib.h>


int maxsize = 1000;
int stack[1000];
int top = -1;

int isempty()
{
    if(top == -1)
    {
        return 1;
    }
    else 
    {
        return 0;
    }
}



int isfull()
{
    if(top == maxsize)
    {
        return 1;
    }
    else 
    {
        return 0;
    }
}


int peek()
{
    return stack[top];
}


int pop()
{
    int data;
    if(!isempty())
    {
        data = stack[top];
        top --;
        return data;
    }
    /*else 
    {
        printf("stack empty");
    }*/
}


int push(int data)
{
    if(!isfull())
    {
        top ++;
        stack[top] = data;
    }
    /*else 
    {
        printf("Stack full");
    }*/
}



int main()
{
    //pushing items in stack
    push(3);
    push(5);
    push(9);
    push(1);
    push(12);
    push(13);
    push(15);
    push(20);
    printf("%d",peek());
    while(!isempty())
    {
        int data = pop();
        printf("%d\n",data);
    }
    return 0;
}
