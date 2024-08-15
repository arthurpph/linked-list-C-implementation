#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *previous;
    struct node *next;
};

struct node* insertOnStart(struct node *head, int data) {
    if(head == NULL) {
        head = (struct node*) malloc(sizeof(struct node));
        head->data = data;
        head->previous = head;
        head->next = head;
        return head;
    }

    struct node *newNode = (struct node*) malloc(sizeof(struct node));

    struct node *last = head->previous;
    newNode->data = data;
    last->next = newNode;
    head->previous = newNode;
    newNode->next = head;
    newNode->previous = last;

    return newNode;
}

struct node* insertOnEndSlow(struct node *head, int data) {
    if(head == NULL) {
        return insertOnStart(head, data);
    }

    struct node *currentNode = head;

    while(currentNode->next != head) {
        currentNode = currentNode->next;
    }

    struct node *newNode = (struct node*) malloc(sizeof(struct node));

    newNode->data = data;
    currentNode->next = newNode;
    newNode->next = head;
    newNode->previous = currentNode;
    head->previous = newNode;

    return head;
}

struct node* insertOnEnd(struct node *head, int data) {
    if(head == NULL) {
        return insertOnStart(head, data);
    }

    struct node *newNode = (struct node*) malloc(sizeof(struct node));

    struct node *last = head->previous;
    newNode->data = data;
    last->next = newNode;
    newNode->previous = last;
    newNode->next = head;
    head->previous = newNode;

    return head;
}

struct node* removeNode(struct node *head, int data) {
    if(head == NULL) {
        return NULL;
    }

    if(head->data == data) {
        if(head->next == NULL) {
            free(head);
            return NULL;
        }

        struct node *newHead = head->next;
        newHead->previous = head->previous;
        free(head);
        return newHead;
    }

    struct node *currentNode = head;

    while(currentNode != NULL) {
        if(currentNode->data == data) {
            currentNode->previous->next = currentNode->next;

            if(currentNode->next != NULL) {
                currentNode->next->previous = currentNode->previous;
            }

            free(currentNode);
            return head;
        }

        currentNode = currentNode->next;
    }

    return head;
}

void printFromTheStart(struct node *head) {
    if(head == NULL) {
        return;
    }

    struct node *currentNode = head;

    do {
        printf("%d\n", currentNode->data);
        currentNode = currentNode->next;
    } while (currentNode != head && currentNode != NULL);
}

void printFromTheEnd(struct node *head) {
    if(head == NULL) {
        return;
    }

    struct node *currentNode = head->previous;

    while(currentNode != NULL) {
        printf("%d\n", currentNode->data);

        if(currentNode == head) {
            break;
        }

        currentNode = currentNode->previous;
    }
}

int main() {
    struct node *head = NULL;
    int i;

    for(i = 0; i < 1000000; i++) {
        head = insertOnEnd(head, i);
    }

    head = removeNode(head, 999999);

    printFromTheEnd(head);

    system("pause");
    return 0;
}