#include <stdio.h>
#include <stdlib.h>


struct node{
    int data;
    struct node *next;
};

struct node *first = NULL;

void append(int data)
{
    struct node *temp;
    temp = (struct node *)malloc(sizeof(struct node *));
    if(temp == NULL)
    {
        printf("\r\nNot enough memeory to create node");
        return;
    }
    
    temp->data =  data;
    temp->next = NULL;
   
    if(first == NULL)
    {
        first = temp;
    }
    else
    {
        struct node *q = first;
        while(q->next != NULL)
        {
           q = q->next;
        }
        printf("\r\nAdding node with data: %d", data);
        q->next = temp;
    }
}

void Add_AtBegin(int data)
{
    struct node *temp;
    temp = (struct node *)malloc(sizeof(struct node *));
    printf("\r\nAdding node with data: %d", data);
    temp->data =  data;
    temp->next = NULL;
    if(first == NULL)
    {
       first = temp;
    }
    else{
        temp->next = first;
        first = temp;
    }
}

void display(struct node *p)
{
    struct node *temp = p;
    printf("\r\nElements are:");
    while(temp != NULL)
    {
        printf(" %d", temp->data);
        temp = temp->next;
    }
}

void Recursivedisplay(struct node *p)
{
    if(p != NULL)
    {
        printf("\r\nElement is: %d", p->data);
        Recursivedisplay(p->next);
    }
}

int count(struct node *p)
{
    struct node *temp = p;
    int cnt = 0;
    while(temp != 0)
    {
        cnt += 1;
        temp = temp->next;
    }
    return cnt;
}

int sum(struct node *p)
{
    struct node *temp = p;
    int sum = 0;
    while(temp != NULL)
    {
        sum += temp->data;
        temp = temp->next;
    }
    return sum;
}


int recursive_sum(struct node *p)
{
    struct node *temp = p;
    if(temp == NULL)
    {
        return 0;
    }else
    {
        return recursive_sum(temp->next) + temp->data;
    }
    
}

int main()
{
    Add_AtBegin(99);
    Add_AtBegin(100);
    append(10);
    append(12);
    append(1);
    display(first);
    Recursivedisplay(first);
    Add_AtBegin(0);
    Add_AtBegin(5);
    append(-5);
    display(first);
    printf("\r\nNumber of nodes: %d", count(first));
    printf("\r\nSum of nodes: %d", sum(first));
    printf("\r\nSum of nodes using recursion : %d", recursive_sum(first));
    return 0;
}
