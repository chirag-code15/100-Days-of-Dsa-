#include <stdio.h>
#include <stdlib.h>
struct node {
    int data;
    struct node* next;
};
void enqueue(struct node** front, struct node** rear, int value) {
    struct node* newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = value;
    newnode->next = NULL;
    if (*rear == NULL) {
        *front = *rear = newnode;
        return;
    }
    (*rear)->next = newnode;
    *rear = newnode;
}
void rotate(struct node** front, struct node** rear) {
    if (*front == NULL || (*front)->next == NULL)
        return;

    struct node* temp = *front;
    *front = (*front)->next ; 
    (*rear)->next = temp;
    *rear = temp;
    (*rear)->next = NULL;
}
void display(struct node* front) {
    struct node* temp = front;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
}
int main() {
    int n, m, x;
    struct node* front = NULL;
    struct node* rear = NULL;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &x);
        enqueue(&front, &rear, x);
    }
    scanf("%d", &m);
    for (int i = 0; i < m; i++) {
        rotate(&front, &rear);
    }
    display(front); 
    return 0;
}