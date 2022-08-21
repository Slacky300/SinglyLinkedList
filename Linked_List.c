#include <stdio.h>
#include <stdlib.h>

struct node{
    
    int data;
    struct node *next;

}*head = NULL,*p,*temp,*head2 = NULL;




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
void display(struct node *head){
    
    p = head;
    if(head==NULL){   
        printf("Linked list empty\n");
    }else{
        while(p!=NULL){
            printf("%d ",p->data);
            p = p->next;
        }
    }
    printf("\n");
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
    
    if(head==NULL){
        printf("Linked list is empty\n");
        return head;
    }
    temp = head;
    head = head->next;
    free(temp);
    return head;
}

void removeLast(){

    if(head==NULL){
        printf("Linked list is empty\n");
        return head;
    }
    p = head;
    while(p->next->next!=NULL){
        p = p->next;
    }
    temp =  p->next;
    p->next = NULL;
    free(temp);
    
   
}
void deleteSpecific(struct node *head,int value){
    struct node *pTail;
    
    if(value == head->data){
        printf("Choose remove First Node! (HEAD NODE)\n");
        return;
    }
    pTail = head;
    p = head;
    
    while(p->data!=value){
        
        p = p->next;
        
    }
    while(pTail->next->data!=value){
        pTail = pTail->next;
    }
    
    pTail->next=p->next;
    
    free(p);
    
    
    
}

struct node *split(struct node *head,int value){
    temp = head;
    while(temp!=NULL && temp->data!=value){
        temp = temp->next;
    }
    
    head2 = temp->next;
    temp->next = NULL;
    return head2;
}
void merge(struct node *head,struct node *head2){
    temp = head;
    if(head2==NULL){
        printf("Merge operation can't be performed\n");
        return;
    }
    while(temp!=NULL&&temp->next!=NULL){
        temp=temp->next;
    }
    temp->next=head2;
    head2 =NULL;
}


struct node *reverseList(struct node *head){
    struct node *prev,*nx,*curr;
    curr =  head;
    prev = NULL;
    while(curr!= NULL){
        nx = curr->next;
        curr->next = prev;
        prev = curr;
        curr = nx;
    }
    head = prev;
    return head;
}

void sort(struct node *head){
   int going = 0;
   temp = NULL;
   if(head==NULL){
       return;
   }
   do{
       going = 0;
       p = head;
       while(p->next!=temp){
           if(p->data>p->next->data){
               swap(p,p->next);
               going = 1;
           }
           p=p->next;
       }
       temp = p;
   }while(going);
}
void swap(struct node *a,struct node *b){
    int temp = a->data;
    a->data = b->data;
    b->data = temp;
}

void main(){
    
    
    int choice,choice2,choice3;
    do{
        printf("Enter the operation you want to perform\n");
        printf("1.CreateList\n2.Insert\n3.Count\n4.Delete\n5.Display\n6.Split\n7.Merge\n8.Reverse\n9.Sort\n10.Exit\n");
        scanf("%d",&choice);
        if(choice == 1){
            head = createList(head);
        }else if(choice == 2){
            do{
                int hold,index;
                printf("Enter the position to insert\n");
                printf("1.Starting\n2.Specific\n3.Last\n4.Before an element \n5.After an element\n6.Stop Inserting\n");
                scanf("%d",&choice2);
            if(choice2 == 1){
                
                printf("Enter the value\n");
                scanf("%d",&hold);
                head = addAtBeg(head,hold);
            }else if(choice2==2){
                
                printf("Enter the position you want to add\n");
                scanf("%d",&index);
                printf("Enter the value to add\n");
                scanf("%d",&hold);
                head = insertAtIndex(head,index,hold);
            }else if(choice2==3){
                printf("Enter the value to add at last\n");
                scanf("%d",&hold);
                head = addAtEnd(head,hold);
                printf("Linked list: \n");
                display(head);
            }else if(choice2==4){
                display(head);
                printf("Enter the value\n");
                scanf("%d",&hold);
                printf("Enter the element\n");
                scanf("%d",&index);
                head = insertBefore(head,index,hold);
                printf("Linked list: \n");
                display(head);
            }else if(choice2 == 5){
                display(head);
                printf("Enter the value\n");
                scanf("%d",&hold);
                printf("Enter the element\n");
                scanf("%d",&index);
                head = insertAfter(head,index,hold);
                printf("Linked list: \n");
                display(head);
                
            }else if(choice2==6){
                break;
            }else{
                printf("Invalid Input\n");
            }
            }while(choice2!=6);
            
        }else if(choice==3){
            printf("The no. of current nodes = %d\n",count());
        }else if(choice==4){
            do{
                int hold;
                printf("1.First Node\n2.Specific Node\n3.Last Node\n4.Exit\n");
                scanf("%d",&choice3);
                if(choice3==1){
                    head = removeHead(head);
                    printf("Linked List:\n");
                    display(head);
                }else if(choice3==2){
                    printf("Enter the value\n");
                    scanf("%d",&hold);
                    deleteSpecific(head,hold);
                    printf("Linked List:\n");
                    display(head);
                }else if(choice3==3){
                    removeLast();
                    printf("Linked List:\n");
                    display(head);
                }else if(choice3==4){
                    break;
                }else{
                    printf("Invalid input\n");
                }
                
            }while(choice3!=4);
        }else if(choice==5){
            printf("Linked List:\n");
            display(head);
        }else if(choice==6){
            int hold;
            printf("Enter the value till you want the linked list\n");
            scanf("%d",&hold);
            head2 = split(head,hold);
            printf("New Linked List after splitting\n");
            printf("Linked list 1: ");
            display(head);
            printf("Linked list 2: ");
            display(head2);
            
            
        }else if(choice==7){
            merge(head,head2);
            printf("Merged Succesfully\nCurrent Linked list:\n");
            display(head);
        }else if(choice==8){
                head = reverseList(head);
                printf("Reverse list:\n");
                display(head);
           
        }else if(choice==9){
            
                sort(head);
                printf("Sorted List:\n");
                display(head);
           
        }else if(choice==10){
            
                    break;
           
        }else{
             printf("Invalid Input\n");
        }
    }while(choice!=10);
        printf("End of linked list operations\nFinal Linked List: ");
        display(head);
        
        
}
