#include <stdio.h>
#include <stdlib.h>

struct node {
    int info;
    struct node* next;
};

// insert at beginning and return new head
struct node* insert_beg(int item, struct node* start) {
    struct node* ptr = (struct node*)malloc(sizeof(struct node));
    if (ptr == NULL) {
        printf("overflow error\n");
        return start;
    }
    ptr->info = item;
    ptr->next = start;
    return ptr;   // new head
}

// insert at end and return head
struct node* insert_end(int item, struct node* start) {
    struct node *ptr, *temp;
    ptr = (struct node*)malloc(sizeof(struct node));
    if (ptr == NULL) {
        printf("overflow error\n");
        return start;
    }
    ptr->info = item;
    ptr->next = NULL;

    if (start == NULL) {
        // list was empty, new node is head
        start = ptr;
    } else {
        temp = start;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = ptr;
    }
    return start;    // head (maybe same, maybe new)
}

// insert at given position (1-based) and return head
struct node* insert_pos(int item, int pos, struct node* start) {
    struct node *ptr, *temp;
    int count;

    ptr = (struct node*)malloc(sizeof(struct node));
    if (ptr == NULL) {
        printf("overflow error\n");
        return start;
    }
    ptr->info = item;
    ptr->next = NULL;

    // inserting at position 1 => same as insert at beginning
    if (pos == 1) {
        ptr->next = start;
        return ptr;  // new head
    }

    temp = start;
    count = 1;

    while (temp != NULL && count < pos - 1) {
        temp = temp->next;
        count++;
    }

    if (temp == NULL) {
        printf("position not found\n");
        free(ptr);
        return start;
    }

    ptr->next = temp->next;
    temp->next = ptr;

    return start;
}

int main() {
    struct node *start = NULL, *temp;
    int x;

    printf("Enter item : ");
    scanf("%d", &x);

    // first node
    start = insert_beg(x, start);

    // insert 45 at beginning
    start = insert_beg(45, start);

    // insert 67 at end
    start = insert_end(67, start);

    // insert 89 at position 2
    start = insert_pos(89, 2, start);

    printf("Elements are: ");
    temp = start;
    while (temp != NULL) {
        printf("%d ", temp->info);
        temp = temp->next;
    }

    return 0;
}
