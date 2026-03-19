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
void delete_beg();
void delete_end();
void delete_specific_position();

int main(){
	int choice;

	while(1){
		printf("\n\n*******Doubly-LinkList-Menu*******\n");
		printf("\n1.CREATE\n2.TRAVERSE\n3.INSERT-BEGINING\n4.INSERT-END\n5.INSER-AT-ANY-POSITION.");
		printf("\n6.DELETE-BEGINING\n7.DELETE-END\n8.DELETE FROM SPECIFIC POSITION.\n");
		printf("9.EXIT.\n");
		printf("\nEnter Your Choice:- ");
		scanf("%d",&choice);
		
		switch(choice){
			case 1:
				create();
				forward_traversal();
                backward_traversal();
				break;
			case 2:
				forward_traversal();
                backward_traversal();
				break;
			case 3:
				insert_beg();
				forward_traversal();
                backward_traversal();
				break;
			case 4:
				insert_end();
				forward_traversal();
                backward_traversal();
				break;
			case 5:
				insert_any_position();
				forward_traversal();
                backward_traversal();
				break;
			case 6:
				delete_beg();
				forward_traversal();
                backward_traversal();
				break;
			case 7:
				delete_end();
				forward_traversal();
                backward_traversal();
				break;
			case 8:
				delete_specific_position();
				forward_traversal();
                backward_traversal();
				break;
			case 9:
				printf("\n********************************\n");
				printf("Exiting From Program..\n");
				exit(0);
			default:
				printf("Invalid Options...\n");
		}
	}
}

void delete_specific_position(){
	struct node *temp,*ptr;
	int i,pos;
	int len = length();
	printf("Enter The Position To Delete A NODE:- ");
	scanf("%d",&pos);
	
	if(pos > len){
		printf("Invalid postion ..\n");
		return;
	}
	
	if(pos < 1){
		printf("Invalid Position..\n");
		return;
	}
	
	if(head == NULL){
		printf("List Is Empty Soo Nothig To delete..\n");
		return;
	}
	
    if(pos == 1){
        temp = head;
        head = head->next;

        if(head != NULL){
            head->prev = NULL;
        }

        free(temp);
        return;
    }
	else{
	  temp = head;
	  for(i=1;i<pos-1;i++){
		  temp=temp->next;
	    }
	  ptr = temp->next;
	  temp->next = ptr->next;
	
	  if(ptr->next != NULL){
         ptr->next->prev = temp;
        }
	  free(ptr);
	}
}

void delete_end(){
	struct node *temp,*ptr;
	
	if(head == NULL){
		printf("List IS Empty Nothing to delete..\n");
		return;
	}
	
	temp = head;
	if(head->next == NULL){
		head = NULL;
		printf("%d deleted From End..\n",temp->data);
		free(temp);
		return;
	}
	else{
		while(temp->next != NULL){
			temp=temp->next;
		}
		
		ptr = head;
		while(ptr->next != temp){
			ptr = ptr->next;
		}
		ptr->next = NULL;
			temp->prev = NULL;
			printf("%d Deleted Data From End..\n",temp->data);
			free(temp);
	}
	
	
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
	
	while(temp != NULL){
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
	int len = length();
	
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
