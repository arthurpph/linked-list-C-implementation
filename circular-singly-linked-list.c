#include <stdio.h>
#include <stdlib.h>

struct node {
    int number;
    struct node *next;
};

struct node *insert(struct node *head, int number) {
    struct node *newNode = (struct node *) malloc(sizeof(struct node));
    newNode->number = number;
    newNode->next = NULL;

    if(head == NULL) {
        head = newNode;
        head->next = head;
        return head;
    }

    struct node *currentNode = head;

    while(currentNode->next != head) {
        currentNode = currentNode->next;
    }

    currentNode->next = newNode;
    newNode->next = head;

    return head;
}

struct node *removeNode(struct node *head, int number) {
    if(head == NULL) {
        return NULL;
    }

    if(head->number == number) {
        if(head->next == head) {
            free(head);
            return NULL;
        }

        struct node *lastNode = head;
        while(lastNode->next != head) {
            lastNode = lastNode->next;
        }

        struct node *trashNode = head;
        head = head->next;
        lastNode->next = head;
        free(trashNode);
        return head;
    }

    struct node *currentNode = head;

    while(currentNode->next != head && currentNode->next->number != number) {
        currentNode = currentNode->next;
    }

    if(currentNode->next == head) {
        return head;
    }

    struct node *trashNode = currentNode->next;
    currentNode->next = currentNode->next->next;
    free(trashNode);
    return head;

    // struct node *previousNode = head;
    // struct node *currentNode = head->next;

    // while(currentNode != head) {
    //     if(currentNode->number != number) {
    //         previousNode = currentNode;
    //         currentNode = currentNode->next;
    //         continue;
    //     }

    //     previousNode->next = currentNode->next;
    //     free(currentNode);
    //     return head;
    // }

    return head;
}

void print(struct node *head) {
    if(head == NULL) {
        return;
    }

    struct node *currentNode = head;
    do {
        printf("%d\n", currentNode->number);
        currentNode = currentNode->next;
    } while(currentNode != head);
}

int main() {
    struct node *head = NULL;
    int i;

    for(i = 0; i < 100; i++) {
        head = insert(head, i);
    }

    removeNode(head, 5);
    print(head);

    system("pause");
    return 0;
}