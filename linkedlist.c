#include <stdio.h>
#include <stdlib.h>

struct node{
    
    int data;
    struct node* link;
};

struct node* root = NULL;
int length(void);
void append(void);
void display(void);
void addAtBegin(void);
void delete(void);
int main()
{
  int val;
  printf("Hello, World!\n");
  printf("enter Element");
  for(int i= 0;i<=3; i++){
      append();
  }
  val = length();
 
  addAtBegin();
  val = length();
  display();
  delete();
  display();
  return 0;
}

void append(void){
    struct node* temp;
    temp = (struct node*) malloc(sizeof(struct node));
    printf("Enter the data Value\n");
    scanf("%d",&temp->data);
    temp->link = NULL;
    if(root == NULL){
        root = temp;
    }
    else{
        struct node* p;
        p = root;
        while(p->link!=NULL){
            p = p->link;
        }
        p->link = temp;
    }
}
void addAtBegin(void){
    struct node* temp;
    temp = (struct node*) malloc(sizeof(struct node));
    printf("Enter the data Value\n");
    scanf("%d",&temp->data);
    temp->link = NULL;
    if(root == NULL){
        root = temp;
    }
    else{
        temp->link = root;
        root = temp;
    }
}

void display(void){
    struct node* temp;
    temp = (struct node*) malloc(sizeof(struct node));
    //printf("Enter the data Value\n");
   // scanf("%d", temp->data);
    //temp->link = NULL;
    temp = root;
    if(temp == NULL){
        printf("No Element");
    }
    else{
            while(temp!=NULL){
            printf("%d-->",temp->data);
            temp = temp->link;
        }
       printf("\n");
    }
}

int length(void){
  int count = 0;
  struct node* temp;
  temp = (struct node*) malloc(sizeof(struct node));
  temp = root;
  while(temp!=NULL){
    count++;
    temp = temp->link;
  }
  printf("lenth is : %d\n", count);
  return count;

}

void delete(void){
  struct node* temp;
  temp = (struct node*) malloc(sizeof(struct node));
  int loc;
  printf("enter Location to delete\n");
  scanf("%d",&loc);
  if(loc>length()) {
  printf("Envalid Loc");
  }
  else if(loc == 1){
    temp = root;
    root = temp->link;
    temp->link = NULL;
    free(temp);
  }
  else{
    struct node* p = root, *q;
    int i = 1;
    while(i< loc-1){
      p = p->link;
      i++;
    }
    q=p->link;
    p->link = q->link;
    q->link = NULL;
    free(q);
  }
}
