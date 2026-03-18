#include<stdio.h>
#include<stdlib.h>

struct node{
	int data;
	struct node *prev;
	struct node *next;
};

struct node *head = NULL;
//struct node *tail = NULL;

void create();
void forward_traversal();
void backward_traversal();
void insert_beg();
void insert_end();
void insert_any_position();
void detele_beg();

int main(){
	create();
	forward_traversal();
	backward_traversal();
	
	insert_beg();
	forward_traversal();
	backward_traversal();
	
	insert_end();
	forward_traversal();
	backward_traversal();
	
	insert_any_position();
	forward_traversal();
	backward_traversal();
	
	delete_beg();
	forward_traversal();
	backward_traversal();
}

void delete_beg(){
	struct node *temp;
	if(head == NULL){
		printf("List is Empty..\n");
		return;
	}
	
	temp = head;
	
	if(head->next == NULL){
		printf("\nDeleted Node Data Is %d",head->data);
		head = NULL;
		free(temp);
		return;
	}
	
	head = head->next;
	head->prev = NULL;
	printf("\nDeleted Node Data Is %d ",temp->data);
	temp->next = NULL;
	free(temp);
}

int length(){
	struct node *temp;
	temp = head;
	int counter = 0;
	
	while(temp->next != NULL){
		counter++;
		temp = temp->next;
	}
	return counter;
}

void insert_any_position() {
    int pos, i;
    struct node *newnode, *temp, *ptr;
    int len = length();

    printf("Enter The Position:- ");
    scanf("%d", &pos);

    if(pos < 1 || pos > len + 1) {
        printf("Invalid Position..\n");
        return;
    }

    newnode = (struct node *)malloc(sizeof(struct node));
    if(newnode == NULL) {
        printf("Memory Allocation Failed..\n");
        return;
    }

    printf("Enter Data:- ");
    scanf("%d", &newnode->data);

    newnode->prev = NULL;
    newnode->next = NULL;

    if(pos == 1) {
        newnode->next = head;
        if(head != NULL)
            head->prev = newnode;
        head = newnode;
        return;
    }

    temp = head;
    for(i = 1; i < pos - 1; i++) {
        temp = temp->next;
    }

    ptr = temp->next;
    temp->next = newnode;
    newnode->prev = temp;
    newnode->next = ptr;

    if(ptr != NULL){
    	ptr->prev = newnode;
	}

}

void insert_end(){
	struct node *newnode,*temp;
	newnode = (struct node *)malloc(sizeof(struct node));
	if(newnode == NULL){
		printf("Memory Allocation failed..\n");
		return;
	}
	
	printf("\nEnter the Value To Insert At END:- ");
	scanf("%d",&newnode->data);
	newnode->prev = NULL;
	newnode->next = NULL;
	
	if(head == NULL){
		newnode->next = head;
		head = newnode;
		return;
	}
	else{
		temp = head;
		while(temp->next != NULL){
			temp = temp->next;
		}
		temp->next = newnode;
		newnode->prev = temp;
		newnode->next = NULL;		
	}
	
	
}

void insert_beg(){
	struct node *newnode;
	newnode = (struct node *)malloc(sizeof(struct node));
	if(newnode == NULL){
		printf("Memory allocation failed..\n");
		return;
	}
	printf("\nEnter the Value To Insert At Begining:- ");
	scanf("%d",&newnode->data);
	newnode->prev = NULL;
	newnode->next = head;
	
	if(head != NULL){
		head->prev = newnode;
	}
	head = newnode;
}

void backward_traversal(){
    struct node *temp;
    
    if(head == NULL){
        printf("List Is Empty...\n");
        return;
    }
    
    temp = head;
    
    while(temp->next != NULL){
        temp = temp->next;
    }
    
    printf("\nBackward Traversal:- ");
    while(temp != NULL){
        printf("%d->", temp->data);
        temp = temp->prev;
    }
    
    printf("NULL\n");
}

void forward_traversal(){
	struct node *temp;
	
	temp = head;
	
	if(head == NULL){
		printf("List Is Empty...\n");
		return;
	}
	
	printf("\nForward Traversal:- ");
	while(temp != NULL){
		printf("%d->",temp->data);
		
		temp=temp->next;
	}
	printf("NULL\n");
}

void create(){
	struct node *newnode,*temp;
	int n,i;
	
	printf("Enter How Many Nodes You Want To Create:- ");
	scanf("%d",&n);
	
	for(i=0;i<n;i++){
		
		newnode = (struct node *)malloc(sizeof(struct node));
		if(newnode == NULL){
			printf("Memory Allocation Failed...\n");
			return;
		}
		
		printf("Enter the Data for Node %d :- ",i+1);
		scanf("%d",&newnode->data);
		
		newnode->prev = NULL;
		newnode->next = NULL;
		
		if(head == NULL){
			newnode->prev = NULL;
			head = newnode;
		}
		else{
			temp=head;
			
			while(temp->next != NULL){
				temp = temp->next;
			}
			
			temp->next = newnode;
			newnode->prev = temp;
		}
	}
}
