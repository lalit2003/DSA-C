#include<stdio.h>
#include<stdlib.h>
#define MAX 100

int queue[MAX];
int front = -1;
int rear = -1;

void enqueue();
void dequeue();
void traverse();
void peek();
int isempty();

int main(){
	int choice;

    while(1){
    	printf("\n___QUEUE-IMPLEMENTATION-USING-ARRAY___\n");
        printf("\n1. Enqueue\n2. Dequeue\n3. Peek\n4. Traverse\n5. IS-EMPTY\n6. Exit\n");
        printf("Enter Choice: ");
        scanf("%d", &choice);

        switch(choice){
            case 1: 
			   enqueue(); 
			   traverse();
			   break;
            case 2: 
			   dequeue();
			   traverse(); 
			   break;
            case 3: 
			   peek(); 
			   break;
            case 4: 
			   traverse(); 
			   break;
			case 5:
				if(isempty()){
					printf("Queue Is Empty..\n");
				}
				else{
					printf("Queue Is Not Empty..\n");
				}
				break;
            case 6:
			   printf("\nExiting From Program...\n");
			   printf("_________________\n");
			   exit(0);
            default: 
			   printf("Invalid Choice\n");
        }
    }
}

void enqueue(){
    int value;
    printf("Enter The Value To Enqueue:- ");
    scanf("%d", &value);

    if(rear == MAX - 1){
        printf("Queue Overflow..\n");
        return;
    }

    if(front == -1){
        front = 0;
    }

    rear++;
    queue[rear] = value;

    printf("Enqueued Successfully..\n");
}

void dequeue(){
	if(front == -1 || front > rear){
		printf("Queue is Empty..\n");
		return;
	}
	printf("%d Deleted From The Queue..\n",queue[front]);
	front++;
	
	if(front > rear){
		front = rear = -1;
	}
}

int isempty(){
	if(front == -1 || front > rear){
		return 1;
	}
	return 0;
}

void traverse(){
	int i;
	
	if(isempty()){
		printf("Queue Is Empty..\n");
		return;
	}
	for(i=front;i<=rear;i++){
		printf("| %d |",queue[i]);
	}
	printf("\n");
}

void peek(){
    if(front == -1 || front > rear){
        printf("Queue Is Empty..\n");
        return;
    }

    printf("Peek Element Is %d..\n", queue[front]);
}
