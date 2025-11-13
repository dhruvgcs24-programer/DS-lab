#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

struct Node* createNode(int data);
struct Node* insertAtBeginning(struct Node* head, int data);
struct Node* insertAtEnd(struct Node* head, int data);
struct Node* insertAtAnyPosition(struct Node* head, int data, int position);
void deleteStart(struct Node **head);
void deleteEnd(struct Node **head);
void deleteAtPos(struct Node **head, int pos);
void display(struct Node *head);
void sortList(struct Node **head);
void reverseList(struct Node **head);
struct Node* concatenate(struct Node *list1, struct Node *list2);

struct Node* createNode(int data) {
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
    if (!newNode) {
        printf("Memory allocation failed!\n");
        exit(1);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

struct Node* insertAtBeginning(struct Node* head, int data) {
    struct Node *newNode = createNode(data);
    newNode->next = head;
    return newNode;
}

struct Node* insertAtEnd(struct Node* head, int data) {
    struct Node *newNode = createNode(data);
    if (head == NULL)
        return newNode;
    struct Node *temp = head;
    while (temp->next != NULL)
        temp = temp->next;
    temp->next = newNode;
    return head;
}

struct Node* insertAtAnyPosition(struct Node* head, int data, int position) {
    struct Node *newNode = createNode(data);
    if (position <= 0) {
        printf("Invalid position!\n");
        free(newNode);
        return head;
    }
    if (position == 1) {
        newNode->next = head;
        return newNode;
    }
    struct Node *temp = head;
    for (int i = 1; temp != NULL && i < position - 1; i++)
        temp = temp->next;
    if (temp == NULL) {
        printf("Position out of range!\n");
        free(newNode);
        return head;
    }
    newNode->next = temp->next;
    temp->next = newNode;
    return head;
}

void deleteStart(struct Node **head) {
    if (*head == NULL) {
        printf("List is empty!\n");
        return;
    }
    struct Node *temp = *head;
    *head = (*head)->next;
    free(temp);
}

void deleteEnd(struct Node **head) {
    if (*head == NULL) {
        printf("List is empty!\n");
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
        printf("List is empty!\n");
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
        printf("Position out of range!\n");
        return;
    }
    prev->next = temp->next;
    free(temp);
}

void sortList(struct Node **head) {
    if (*head == NULL) return;
    struct Node *i, *j;
    int temp;
    for (i = *head; i != NULL; i = i->next)
        for (j = i->next; j != NULL; j = j->next)
            if (i->data > j->data) {
                temp = i->data;
                i->data = j->data;
                j->data = temp;
            }
}

void reverseList(struct Node **head) {
    struct Node *prev = NULL, *curr = *head, *next = NULL;
    while (curr != NULL) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    *head = prev;
}

struct Node* concatenate(struct Node *list1, struct Node *list2) {
    if (list1 == NULL) return list2;
    struct Node *temp = list1;
    while (temp->next != NULL)
        temp = temp->next;
    temp->next = list2;
    return list1;
}

void display(struct Node *head) {
    if (head == NULL) {
        printf("List is empty!\n");
        return;
    }
    struct Node *temp = head;
    printf("Linked List: ");
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main() {
    struct Node *head = NULL, *list2 = NULL;
    int choice, data, position;

    while (1) {
        printf("\n==== LINKED LIST MENU ====\n");
        printf("1. Insert at Beginning\n");
        printf("2. Insert at End\n");
        printf("3. Insert at Any Position\n");
        printf("4. Delete from Start\n");
        printf("5. Delete from End\n");
        printf("6. Delete at Position\n");
        printf("7. Sort List\n");
        printf("8. Reverse List\n");
        printf("9. Concatenate Second List\n");
        printf("10. Display\n");
        printf("11. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter data: ");
                scanf("%d", &data);
                head = insertAtBeginning(head, data);
                break;
            case 2:
                printf("Enter data: ");
                scanf("%d", &data);
                head = insertAtEnd(head, data);
                break;
            case 3:
                printf("Enter data: ");
                scanf("%d", &data);
                printf("Enter position: ");
                scanf("%d", &position);
                head = insertAtAnyPosition(head, data, position);
                break;
            case 4:
                deleteStart(&head);
                break;
            case 5:
                deleteEnd(&head);
                break;
            case 6:
                printf("Enter position: ");
                scanf("%d", &position);
                deleteAtPos(&head, position);
                break;
            case 7:
                sortList(&head);
                break;
            case 8:
                reverseList(&head);
                break;
            case 9:
                printf("Creating second list...\n");
                list2 = insertAtEnd(list2, 100);
                list2 = insertAtEnd(list2, 200);
                head = concatenate(head, list2);
                break;
            case 10:
                display(head);
                break;
            case 11:
                exit(0);
            default:
                printf("Invalid choice!\n");
        }
    }
    return 0;
}
