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
        head->previous = NULL;
        head->next = NULL;
        return head;
    }

    struct node *newNode = (struct node*) malloc(sizeof(struct node));

    newNode->data = data;
    head->previous = newNode;
    newNode->next = head;
    newNode->previous = NULL;

    return newNode;
}

struct node* insertOnEnd(struct node *head, int data) {
    if(head == NULL) {
        return insertOnStart(head, data);
    }

    struct node *currentNode = head;

    while(currentNode->next != NULL) {
        currentNode = currentNode->next;
    }

    struct node *newNode = (struct node*) malloc(sizeof(struct node));

    newNode->data = data;
    currentNode->next = newNode;
    newNode->previous = currentNode;
    newNode->next = NULL;

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
        newHead->previous = NULL;
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

    while(head != NULL) {
        printf("%d\n", head->data);
        head = head->next;
    }
}

void printFromTheEnd(struct node *head) {
    if(head == NULL) {
        return;
    }

    while(head->next != NULL) {
        head = head->next;
    }

    while(head != NULL) {
        printf("%d\n", head->data);
        head = head->previous;
    }
}

int main() {
    struct node *head = NULL;

    head = insertOnEnd(head, 10);
    head = insertOnEnd(head, 20);
    head = insertOnEnd(head, 30);
    head = insertOnEnd(head, 40);
    head = insertOnEnd(head, 50);
    head = insertOnEnd(head, 60);
    head = insertOnEnd(head, 70);
    head = insertOnEnd(head, 80);

    head = removeNode(head, 30);

    printFromTheStart(head);

    system("pause");
    return 0;
}