#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

struct node{
    int data;
    struct node *next;
};

struct node *first = NULL;

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
    if(pos < 0 || pos > count(first))
    {
        return;
    }
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

void SortedInsert(struct node *p, int data)
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
       
        struct node *q= NULL;
        while( p && p->data < data)
        {
            q = p;
            p = p->next;
        }
        if(p == first)
        {
            temp->next = first;
            first = temp;
        }else
        {
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


void Recursivedisplay(struct node *p)
{
    if(p != NULL)
    {
        printf("\r\nElement is: %d", p->data);
        Recursivedisplay(p->next);
    }
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

int Delete(int pos)
{
    struct node *p = first;
    struct node *q = NULL;
    int x = -1;
    
    if(pos < 1 || pos > count(p))
        return - 1;
    
    if(pos ==  1)
    {
        first = first->next;
        x = p->data;
        free(p);
        p = NULL;
    }
    else
    {
        for(int  i = 0; i < pos - 1; i++)
        {
            q = p;
            p = p->next;
        }
        if(p)
        {
            q->next = p->next;
            x = p->data;
            free(p);
            p = NULL;
        }
    }
    return x;
}

int isSorted()
{
    struct node *p = first;
    int x = INT_MIN;
    while(p != NULL)
    {
        if(p->data < x)
            return 0;
        x = p->data;
        p = p->next;
    }
    return 1;
}

int main()
{

    append(10);
    append(12);
    append(13);
    display(first);

    SortedInsert(first, 5);
    SortedInsert(first, 23);
    SortedInsert(first, 15);
    display(first);
    Delete(1);
    Delete(4);
    display(first);
    char ch = isSorted()?'Y':'N';
    printf("\r\nlinkedlist sorted: %c", ch);
    Insert(2, 2);
    display(first);
    ch = isSorted()?'Y':'N';
    printf("\r\nlinkedlist sorted: %c", ch);

    return 0;
}
