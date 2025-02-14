#include <stdio.h>
#include <stdlib.h>

struct node {
    struct node *prev;
    int data;
    struct node *next;
};

struct node *head = NULL;
struct node *tail = NULL;

void add_head(int data) {
    struct node *new_n = (struct node *)malloc(sizeof(struct node));
    new_n->data = data;
    new_n->prev = NULL;
    new_n->next = head;

    if (head == NULL) {
        head = tail = new_n;
    } else {
        head->prev = new_n;
        head = new_n;
    }
}

void print() {
    struct node *tmp = head;
    while (tmp != NULL) {
        printf(" %d", tmp->data);
        tmp = tmp->next;
    }
    printf("\n");
}

void add_anywhere(int data, int location) {
    int size = 0;
    struct node *tmp = head;

    while (tmp != NULL) {
        size += 1;
        tmp = tmp->next;
    }

    if (location > size || location < 0) {
        printf("Location is not valid\n");
        return;
    }

    struct node *n = (struct node *)malloc(sizeof(struct node));
    n->data = data;

    if (location == 0) {
        n->next = head;
        n->prev = NULL;
        if (head != NULL) {
            head->prev = n;
        }
        head = n;
        if (tail == NULL) {
            tail = n;
        }
        return;
    }

    if (location == size) {
        n->next = NULL;
        n->prev = tail;
        if (tail != NULL) {
            tail->next = n;
        }
        tail = n;
        return;
    }

    struct node *t = head;
    for (int i = 0; i < location - 1; i++) {
        t = t->next;
    }

    n->next = t->next;
    n->prev = t;
    if (t->next != NULL) {
        t->next->prev = n;
    }
    t->next = n;
}

int main() {
    add_head(1);
    add_head(2);
    add_head(3);
    add_anywhere(8, 2);
    print();
    return 0;
}
