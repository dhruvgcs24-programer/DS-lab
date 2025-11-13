#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

struct Node* createNode(int data);
void insertEnd(struct Node **head, int data);
void display(struct Node *head);
void deleteStart(struct Node **head);
void deleteEnd(struct Node **head);
void deleteAtPos(struct Node **head, int pos);
void sortList(struct Node **head);
void reverseList(struct Node **head);
struct Node* concatenate(struct Node *list1, struct Node *list2);

struct Node* createNode(int data) {
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void insertEnd(struct Node **head, int data) {
    struct Node *newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
        return;
    }
    struct Node *temp = *head;
    while (temp->next != NULL)
        temp = temp->next;
    temp->next = newNode;
}

void display(struct Node *head) {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }
    struct Node *temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

void deleteStart(struct Node **head) {
    if (*head == NULL) {
        printf("List is empty.\n");
        return;
    }
    struct Node *temp = *head;
    *head = (*head)->next;
    free(temp);
}

void deleteEnd(struct Node **head) {
    if (*head == NULL) {
        printf("List is empty.\n");
        return;
    }
    struct Node *temp = *head, *prev = NULL;
    if (temp->next == NULL) {
        free(temp);
        *head = NULL;
        return;
    }
    while (temp->next != NULL) {
        prev = temp;
        temp = temp->next;
    }
    prev->next = NULL;
    free(temp);
}

void deleteAtPos(struct Node **head, int pos) {
    if (*head == NULL) {
        printf("List is empty.\n");
        return;
    }
    if (pos == 1) {
        deleteStart(head);
        return;
    }

    struct Node *temp = *head, *prev = NULL;
    for (int i = 1; temp != NULL && i < pos; i++) {
        prev = temp;
        temp = temp->next;
    }
    if (temp == NULL) {
        printf("Position out of range.\n");
        return;
    }
    prev->next = temp->next;
    free(temp);
}

void sortList(struct Node **head) {
    if (*head == NULL) return;
    struct Node *i, *j;
    int temp;
    for (i = *head; i != NULL; i = i->next) {
        for (j = i->next; j != NULL; j = j->next) {
            if (i->data > j->data) {
                temp = i->data;
                i->data = j->data;
                j->data = temp;
            }
        }
    }
}
