#include <stdio.h>
#include <stdlib.h>


struct node{
    int data;
    struct node *next;
};

struct node *first = NULL;

void append(int data)
{
    struct node *last,*temp;
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
           last = first;
       }
    }
    else{
    
        temp = (struct node *)malloc(sizeof(struct node *));
        if(temp== NULL){
           printf("\r\nNot enough memeory to add node");
           return;
        }
         printf("\r\nAdding node with data: %d", data);
        temp->data =  data;
        temp->next = NULL;
        last->next = temp;
        last = temp;
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
    append(10);
    append(12);
    append(1);
    display(first);
    Recursivedisplay(first);
    return 0;
}
