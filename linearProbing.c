#include <stdio.h>

#define MAX 20

struct Employee {
    int key;        // 4-digit employee key
    int empId;
    char name[20];
};

struct Employee ht[MAX];
int m;

/* Initialize hash table */
void initHashTable() {
    int i;
    for (i = 0; i < m; i++)
        ht[i].key = -1;   // -1 indicates empty slot
}

/* Hash function */
int hashFunction(int key) {
    return key % m;
}

/* Insert employee record using linear probing */
void insert() {
    struct Employee emp;
    int index, i;

    printf("Enter 4-digit Key: ");
    scanf("%d", &emp.key);

    printf("Enter Employee ID: ");
    scanf("%d", &emp.empId);

    printf("Enter Employee Name: ");
    scanf("%s", emp.name);

    index = hashFunction(emp.key);

    /* Linear Probing */
    for (i = 0; i < m; i++) {
        int pos = (index + i) % m;

        if (ht[pos].key == -1) {
            ht[pos] = emp;
            printf("Record inserted at address %d\n", pos);
            return;
        }
    }

    printf("Hash Table is full. Insertion failed.\n");
}

/* Display hash table */
void display() {
    int i;
    printf("\nHash Table Contents:\n");
    printf("Address\tKey\tEmpID\tName\n");

    for (i = 0; i < m; i++) {
        if (ht[i].key != -1)
            printf("%d\t%d\t%d\t%s\n", i, ht[i].key, ht[i].empId, ht[i].name);
        else
            printf("%d\t---\t---\t---\n", i);
    }
}

int main() {
    int choice;

    printf("Enter size of hash table (m): ");
    scanf("%d", &m);

    initHashTable();

    while (1) {
        printf("\n1. Insert Employee Record");
        printf("\n2. Display Hash Table");
        printf("\n3. Exit");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            insert();
            break;
        case 2:
            display();
            break;
        case 3:
            return 0;
        default:
            printf("Invalid choice\n");
        }
    }
}
