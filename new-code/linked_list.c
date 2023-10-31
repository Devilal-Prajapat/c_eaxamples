/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
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
    if(first == NULL)
    {
       first = (struct node *)malloc(sizeof(struct node *));
       if(first== NULL){
           printf("\r\nNot enough memeory to create first node");
           return;
       }
       else
       {
           printf("\r\ncreated first node with data: %d", data);

           first->data = data;
           first->next = NULL;
       }
    }
    else{
        struct node *q = first;
        while(q->next != NULL)
        {
           q = q->next;
        }
        temp = (struct node *)malloc(sizeof(struct node *));
        printf("\r\nAdding node with data: %d", data);
        temp->data =  data;
        temp->next = NULL;
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
    return 0;
}
