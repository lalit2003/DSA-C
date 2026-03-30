#include<stdio.h>
#include<stdlib.h>

struct node{
	int data;
	struct node *next;
};

struct node *rear = NULL;
struct node *front = NULL;

void enqueue();
void dequeue();
void traverse();
void peek();

int main(){
	int choice;

    while(1){
    	printf("\n___QUEUE-IMPLEMENTATION-USING-LINLLIST___\n");
        printf("\n1. Enqueue\n2. Dequeue\n3. Peek\n4. Traverse\n5. Exit\n");
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
			   printf("\nExiting From Program...\n");
			   printf("_________________\n");
			   exit(0);
            default: 
			   printf("Invalid Choice\n");
        }
    }
}

void enqueue(){
	struct node *newnode;
	newnode = (struct node *)malloc(sizeof(struct node));
	if(newnode == NULL){
		printf("Memory Allocation Failed..");
		return;
	}
	
	printf("Enter The Value To Enqueue:- ");
	scanf("%d",&newnode->data);
	
	if(front == NULL){
		newnode->next = NULL;
		front = newnode;
		rear = newnode;
	}
	else{
		newnode->next = NULL;
		rear->next = newnode;
		rear = newnode;
	}
	
	printf("\nNode Enqueue Successfully..\n");
}

void dequeue(){
	struct node *temp;
	temp = front;
	if(front == NULL){
		printf("\n Queue Is Empty..\n");
		return;
	}
	else if(front->next == NULL){
		printf("%d Dequeue Successfully..\n",front->data);
		front = NULL;
		rear = NULL;
		free(temp);
		return;
	}
	else{
	   front = front->next;
	   printf("%d Is Sucessfully Dequeue From Original Queue..\n",temp->data);
	   free(temp);
	   return;
	}
}

void peek(){
	struct node *temp;
	temp = front;
	
	if(front == NULL){
		printf("Queue Is Empty..\n");
		return;
	}
	else{
		printf("\n%d Is Peek Node..\n",temp->data);
	}
	
}

void traverse(){
	struct node *temp;
	temp = front;
	
	if(front == NULL){
		printf("Queue IS Empty..\n");
		return;
	}
	
	while(temp != NULL){
		printf("| %d | ",temp->data);
		temp = temp->next;
	}
	printf("\n Traverse Successfully..\n");
}
