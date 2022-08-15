#include <stdio.h>
#include <stdlib.h>

struct node{
    
    int data;
    struct node *next;

}*head = NULL,*p,*temp;

struct node * addAtEnd(struct node *head,int value){


    temp = (struct node *)malloc(sizeof(struct node));
    temp->data=value;
    p = head;
    if(p == NULL){
    
       head  = temp;
       head->next = NULL;
    
    }else{
        while(p->next!=NULL){
    
            p = p->next;
    
        }

        p->next = temp;
        temp->next = NULL;
    }
    
    
    return head;

}
void display(){
    
    p = head;
    if(head==NULL){   
        printf("Linked list empty\n");
    }else{
        while(p!=NULL){
            printf("%d ",p->data);
            p = p->next;
        }
    }
}
struct node * createList(struct node *head){
    int i,limit,value;
    printf("Enter the no. of node you want to add\n");
    scanf("%d",&limit);
    for(i = 0;i<limit;i++){
        printf("Enter the value : ");
        scanf("%d",&value);
        head = addAtEnd(head,value);
    }
    
        return head;
}

struct node * insertAfter(struct node *head,int value,int hold){
   
    temp = (struct node *)malloc(sizeof(struct node));
    temp->data = hold;
    p = head;
    while(p->data!=value){
        
        p = p->next;
        if(p == NULL){
            printf("Value : %d does not exists in the provided linked list\n",value);
            return head;
        }
    }
    temp->next = p->next;
    p->next =  temp;
    return head;
    
    
}

struct node * addAtBeg(struct node *head,int value){
   
    temp = (struct node *)malloc(sizeof(struct node));
    temp->data = value;
    temp->next = head;
    head = temp;
    return head;
}

struct node * insertAtIndex(struct node *head,int location, int value){
   
    temp = (struct node *)malloc(sizeof(struct node));
    temp->data = value;
    p = head;
    for(int i = 1;i<location;i++){
       
        if(p==NULL){
            printf("Linked list exceeded\n");
            return head;
        }
        
        p = p->next;
    }
        temp->next=p->next;
        p->next  = temp;
        return head;
}
struct node * insertBefore(struct node *head,int value,int hold){
   
    temp = (struct node *)malloc(sizeof(struct node));
    temp->data = hold;
    p = head;
    while(p->next->data!=value){
        
        p = p->next;
        if(p == NULL){
            printf("Value : %d does not exists in the provided linked list\n",value);
            return head;
        }
    }
    
    temp->next = p->next;
    p->next =  temp;
    return head;
    
    
}

int count(){
    int i = 0;
    p = head;
    while(p!=NULL){
        i++;
        p = p->next;
    }
    return i;
}

struct node * removeHead(struct node *head){
    temp = head;
    head = head->next;
    free(temp);
    return head;
}

void removeLast(){

    p = head;
    while(p->next->next!=NULL){
        p = p->next;
    }
    temp =  p->next;
    p->next = NULL;
    free(temp);
    
   
}

void main(){
    
    // head = createList(head);
    // head = insertAfter(head,52,98);
    // head = addAtBeg(head,50);
    // head = insertAtIndex(head,3,89);
    // head = insertBefore(head,52,98);
    // display();
    // printf("\nNo. of nodes = %d \n",count());
    // head = removeHead(head);
    // display();
    // printf("\nNo. of nodes = %d \n",count());
    // removeLast();
    // display();
    // printf("\nNo. of nodes = %d \n",count());
    int choice;
    do{
        printf("Enter the operation you want to perform\n");
        printf("1.CreateList\n2.Insert\n3.Count\n4.Delete\n5.Exit\n");
        scanf("%d",&choice);
        if(choice == 1){
            head = createList(head);
        }else if(choice == 2){
            int choice2,hold;
            printf("Enter the position to inser\n");
            printf("1.Starting\n2.Specific\n3.Last\n4.Before an element \n5.After an element\n6.Stop Inserting\n");
            scanf("%d",&choice2);
            if(choice2 == 1){
                
                printf("Enter the value\n");
                scanf("%d",&hold);
                head = addAtBeg(head,hold);
            }else if(choice2==2){
                
                printf("Enter the position you want to add\n");
                scanf("%d",)
                head = insertAtIndex(head,3,89);
            }
        }
    }

}
