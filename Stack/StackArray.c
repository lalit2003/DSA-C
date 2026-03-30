#include<stdio.h>
#include<stdlib.h>
#define MAX 100

int stack[MAX];
int top = -1;

void push();
void pop();
void peek();
void display();
void isEmpty();
void isFull();

int main() {
    int choice;

    while (1) {
        printf("\n--- Stack Menu ---\n");
        printf(" 1.Push\n 2.Pop\n 3.Peek\n 4.Display\n 5.isEmpty\n 6.isFull\n 7.Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
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
			   break;
            case 4: 
			   display(); 
			   break;
            case 5: 
			   isEmpty(); 
			   break;
            case 6: 
			    isFull(); 
				break;
            case 7: 
               printf("Exiting From The Program..\n");
			   exit(0);
			   
            default: 
			   printf("Invalid choice\n");
        }
    }
}

void push(){
	int value;
	if(top == MAX -1){
		printf("Stack Is Overflow..\n");
	}
	else{
		printf("Enter The Value To Push:- ");
		scanf("%d",&value);
		top++;
		stack[top] = value;
	}
	printf("\n %d Element Pushed Into the Stack Succesfully..\n",stack[top]);
}

void pop(){
	if(top == -1){
		printf("Stack Is UnderFlow..\n");
	}
	else{
		printf("\n%d Element Popped Out Of The Stack..\n",stack[top]);
		top--;
	}
}

void display(){
	int i;
    if (top == -1) {
        printf("Stack is Empty\n");
    } else {
        printf("\nStack elements:\n");
        for (i = top; i >= 0; i--) {
            printf(" | %d |\n", stack[i]);
        }
    }
}

void peek(){
	if(top == -1){
		printf("Stack Is Empty No Peek Element Found..\n");
	}
	else{
		printf("%d Is The Peeked Element ..\n",stack[top]);
	}
}

void isEmpty() {
    if (top == -1)
        printf("Stack is Empty\n");
    else
        printf("Stack is NOT Empty\n");
}

void isFull() {
    if (top == MAX - 1)
        printf("Stack is Full\n");
    else
        printf("Stack is NOT Full\n");
}
