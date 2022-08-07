#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node *next;
    
}*head=NULL,*n1,*n2,*n3;

void traverse(struct node *ptr){
    int i=0;
    while(ptr != NULL){
        printf("Element at index %d = %d\n",i,ptr->data);
        ptr = ptr->next;
        i++;
    }
}

struct node * insertAtHead(struct node *head,int data){
    struct node *ptr = (struct node *)malloc(sizeof(struct node));
    ptr->next = head;
    ptr->data = data;
    return ptr;
    
}

struct node * insertInBetwn(struct node *head,int data,int index){
    struct node *ptr = (struct node *)malloc(sizeof(struct node));
    struct node *p = head;
    int i = 0;
    while(i != index-1){
        p = p->next;
        i++;
    }
    ptr->data = data;
    ptr->next = p->next;
    p->next = ptr;
}


void main(){
    n1 =  (struct node *)malloc(sizeof(struct node));
    n2 =  (struct node *)malloc(sizeof(struct node));
    n3 =  (struct node *)malloc(sizeof(struct node));
    n1->data = 45;
    head = n1;
    n1->next = n2;
    n2->data = 54;
    n2->next = n3;
    n3->data = 65;
    n3->next = NULL;
    traverse(head);
    
    head = insertAtHead(head,48);
    printf("New linked list\n");
    traverse(head);
    insertInBetwn(head,85,2);
    printf("New linked list\n");
    traverse(head);
}