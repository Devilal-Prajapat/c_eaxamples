#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

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

void Insert(int pos, int data)
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
        if(pos == 0)
        {
            temp->next = first;
            first = temp;
        }
        else if(pos > 0)
        {
            struct node *q = first;
            for(int i = 0; i< pos - 1; i++)
            {
               q = q->next;
            }
            printf("\r\nAdding node with data: %d", data);
            temp->next = q->next;
            q->next = temp;
        }
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

int Maximum(struct node *p)
{
    struct node *temp = p;
    int max = INT_MIN;
    while(temp != NULL)
    {
        if(temp->data > max)
        {
            max = temp->data;
        }
        temp = temp->next;
    }
    return max;
}

int recursive_max(struct node *p)
{
    struct node *temp = p;
    if(temp == NULL)
    {
        return INT_MIN;
    }else
    {
        int x = recursive_max(temp->next);
        return (temp->data > x ) ? temp->data : x;
       
    }
}

struct node *Search(struct node *p, int key)
{
    struct node *temp = p;
    while(temp != NULL)
    {
        if(temp->data == key)
        {
            return temp;    
        }
        temp = temp->next;
    }
    return NULL;
}

struct node *ImprovedSearch(struct node *p, int key)
{
    struct node *temp = p;
    struct node *q = NULL;
    int cnt = 0;
    while(temp != NULL)
    {
        if(temp->data == key)
        {
            if(cnt == 0)
               return temp; 
      
            q->next = temp->next;
            temp->next = first;
            first= temp;
            return temp;    
        }
        cnt++;
        q = temp;
        temp = temp->next;
    }
    return NULL;
}

int main()
{
    Add_AtBegin(99);
    Add_AtBegin(100);
    append(10);
    append(12);
    append(1);
    Insert(1, 9);
    Insert(0, 101);
    Insert(7, 102);
    display(first);
    Recursivedisplay(first);
    Add_AtBegin(0);
    Add_AtBegin(5);
    append(-5);
    display(first);
    printf("\r\nNumber of nodes: %d", count(first));
    printf("\r\nSum of nodes: %d", sum(first));
    printf("\r\nSum of nodes using recursion : %d", recursive_sum(first));
    printf("\r\nMax value : %d", Maximum(first));
    printf("\r\nMax value using recursion : %d", recursive_max(first));
   
    Search(first,12);
    display(first);
    
    struct node *p = Search(first,12);
    if(p)
    {
        printf("\r\nLiner Search key found : %d", p->data);
    }
    else
    {
        printf("\r\nkey not found");
    }
    
    display(first);
    struct node *q = ImprovedSearch(first,12);
    q = ImprovedSearch(first,5);
   
    if(q)
    {
        printf("\r\nImproved Liner Search key found : %d", q->data);
    }
    else
    {
        printf("\r\nkey not found");
    }
    display(first);
    q = ImprovedSearch(first,5);
    if(q)
    {
        printf("\r\nImproved Liner Search key found : %d", q->data);
    }
    else
    {
        printf("\r\nkey not found");
    }
    display(first);
    return 0;
}
