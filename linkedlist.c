#include <conio.h>
#include <stdio.h>

struct Node
{
    int data;
    struct Node *next;
    /* data */
};

struct Node *createNode(int data){
    struct Node *newNode=(struct Node*)malloc (sizeof(struct Node));
    if(newNode==NULL){
        printf("Memory allocation failed\n");
        exit(1);
    }
    newNode-> data=data;
    newNode->next=NULL;
    return newNode;
}

struct Node *insertAtBeginning(struct Node* head,int data){
    struct Node*newNode=createNode(data);
    newNode->next=head;
    head=newNode;
    return head;
}

struct Node * insertAtEnd(struct Node* head,int data){
         struct Node* newNode=createNode(data);
         if(head==NULL)
         return newNode;
         struct Node* temp=head;
         while(temp->next!=NULL)
           temp=temp->next;
           temp->next=newNode;
           return head;
}

struct Node* insertAtAnyPosition(struct Node* head,int data,int position){
    struct Node* newNode=createNode(data);
    if(position==1){
        newNode->next=head;
        head=newNode;
        return head;
    }
    if(position<=0){
        printf("Invalid position");
        return head;
    }
    struct Node*temp=head;
    int i;
    for(i=1;temp!=NULL&&temp<position-1;i++){
        temp=temp->next;
    }
    if(temp==NULL){
        printf("Out of range!!\n");
        return head;
    }
    newNode->next=temp->next;
    temp->next=newNode;
    return head;
}

void display(struct Node*head){
    struct Node*temp =head;
    if(head==NULL){
        printf("List is Empty!!\n");
        return ;
    }
    printf("Linked List");
    while(temp!=NULL){
        printf("%d->",temp->data);
        temp=temp->next;
    }
    printf("NULL\n");
}

int main(){
    struct Node* head=NULL;
    int choice,data,position;
    while(1){
        printf("\n---LINKED LIST----\n");
        printf("1.Insert at the beginning\n");
        printf("2.Insert at end\n");
        printf("3.Insert at any position\n");
        printf("4.Display\n");
        printf("5.Exit\n");
        printf("Enter your choice: ");
        scanf("%d",&choice);
        switch(choice){
            case 1:
            printf("Enter data: ");
            scanf("%d",&data);
            head=insertAtBeginning(head,data);
            break;
            case 2:
            printf("Enter data: ");
            scanf("%d",&data);
            head=insertAtEnd(head,data);
            break;
            case 3:
            printf("Enter data: ");
            scanf("%d",&data);
            printf("Enter position(1-based): ");
            scanf("%d",&position);
            head=insertAtAnyPosition(head,data,position);
            break;
            case 4:
            display(head);
            break;
            case 5:
            exit(0);
            default:
            printf("Invalid Choice!!\n");
        }
    }
    return 0;
}
