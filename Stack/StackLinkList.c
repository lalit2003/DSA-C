#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *next;
};

struct node *top = NULL;

void push();
void pop();
void peek();
void display();

int main(){
    int choice;

    while(1){
        printf("\n__STACK IMPLEMENTATION USING LINKED LIST__\n");
        printf("1. Push\n2. Pop\n3. Peek\n4. Display\n5. Exit\n");
        printf("Enter your choice: ");

        if(scanf("%d", &choice) != 1){
            printf("Invalid Input! Exiting...\n");
            exit(0);
        }

        switch(choice){
            case 1: 
			    push();
				display(); 
				break;
            case 2: 
			    pop();
				display(); 
				break;
            case 3: 
			    peek();
				display(); 
				break;
            case 4: 
			    display(); 
				break;
            case 5:
                printf("Exiting Program...\n");
                exit(0);
            default:
                printf("Invalid Choice! Try again.\n");
        }
    }

    return 0;
}

void push(){
    struct node *newnode = (struct node *)malloc(sizeof(struct node));

    if(newnode == NULL){
        printf("Memory Allocation Failed!\n");
        return;
    }

    printf("Enter data: ");
    if(scanf("%d", &newnode->data) != 1){
        printf("Invalid Input!\n");
        free(newnode);
        return;
    }

    newnode->next = top;
    top = newnode;

    printf("Element pushed successfully.\n");
}

void pop(){
    if(top == NULL){
        printf("Stack is empty!\n");
        return;
    }

    struct node *temp = top;
    top = top->next;

    printf("%d popped from stack.\n", temp->data);
    free(temp);
}

void peek(){
    if(top == NULL){
        printf("Stack is empty!\n");
        return;
    }

    printf("Top element: %d\n", top->data);
}

void display(){
    if(top == NULL){
        printf("Stack is empty!\n");
        return;
    }

    struct node *temp = top;

    printf("\nStack elements (Top to Bottom):\n");
    while(temp != NULL){
        printf("| %d |\n", temp->data);
        temp = temp->next;
    }
}
