#include<stdio.h>
#include<stdlib.h>

struct node{
	int data;
	struct node *next;
};

struct node *head = NULL;

void create();
void traverse();
void insert_beg();
void insert_end();
void insert_any_pos();
void delete_beg();
void delete_end();
void delete_specific_pos();

int main(){
	int choice;

	while(1){
		printf("\n\n*******Circular-Single-LinkList-Menu*******\n");
		printf("\n1.CREATE\n2.TRAVERSE\n3.INSERT-BEGINING\n4.INSERT-END\n5.INSER-AT-ANY-POSITION.\n");
		printf("6.DELETE-BEGINING\n7.DELETE-END\n8.DELETE FROM SPECIFIC POSITION.\n");
        printf("9.EXIT.\n");
		printf("\nEnter Your Choice:- ");
		scanf("%d",&choice);
		
		switch(choice){
			case 1:
				create();
				traverse();
				break;
			case 2:
				traverse();
				break;
			case 3:
				insert_beg();
				traverse();
				break;
			case 4:
				insert_end();
				traverse();
				break;
			case 5:
				insert_any_pos();
				traverse();
				break;
			case 6:
				delete_beg();
				traverse();
				break;
			case 7:
				delete_end();
				traverse();
				break;
			case 8:
				delete_specific_pos();
				traverse();
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

void delete_specific_pos(){
	int i,pos;
	struct node *temp,*ptr;
	
	if(head == NULL){
		printf("Nothing to delete ..list is empty..\n");
		return;
	}
	
	printf("Enter the Position to Delete:- ");
	scanf("%d",&pos);
	
	if(pos ==1 && head->next == head){
		temp = head ;
		free(temp);
		head = NULL;
		return;
	}
	
	if(pos == 1){
		temp = head;
		ptr = head;
		
		while(temp->next!= head){
			temp = temp->next;
		}
		head = head->next;
		free(ptr);
		temp->next = head;
	}
	else{
		temp = head;
		for(i=1;i<pos-1;i++){
			temp=temp->next;
		}
		ptr = temp->next;
		temp->next = ptr->next;
		
	   printf("%d deleted\n",ptr->data);
       free(ptr);
	}
}

void delete_end(){
	struct node *temp,*ptr;
	
	if(head == NULL){
		printf("List is Empty Nothing To delete..\n");
		return;
	}
	
	if(head->next == head){
        printf("%d deleted\n",head->data);
        free(head);
        head = NULL;
        return;
	}
	
	else{
		ptr = NULL;
		temp = head;
		while(temp->next != head){
			ptr = temp;
			temp = temp->next;
		}
		ptr->next = head;
		printf("%d is deleted from last ..\n",temp->data);
		free(temp);
		
	}
}

void delete_beg(){
	struct node *temp,*ptr;
	
	if(head == NULL){
		printf("List is Empty Nothing To Delete..\n");
		return;
	}
	
	if(head->next == head){
		printf("%d Data is Deleted From Begining..\n",head->data);
		free(head);
		head = NULL;
		return;
	}
	
	else{
		temp = head;
		ptr = head;
		while(temp->next != head){
			temp = temp->next;
		}
		head = head->next;
		printf("%d data is deleted from begining..\n",ptr->data);
		free(ptr);
		temp->next = head;
	}
}

void insert_any_pos(){
	int pos,i;
	struct node *newnode,*temp,*ptr;
	
	printf("Enter the Position To Insert:- ");
	scanf("%d",&pos);
	newnode = (struct node *)malloc(sizeof(struct node));
	if(newnode == NULL){
		printf("Memory Allocation Failed..\n");
		return;
	}
	printf("Enter the Data To insert :- ");
	scanf("%d",&newnode->data);
	
	if(head == NULL){
		printf("List Is Empty .. First Create the List..\n");
		return;
	}
	
	if(pos == 1){
		temp = head;
		while(temp->next!=head){
			temp = temp->next;
		}
		newnode->next = head;
		temp->next = newnode;
		head = newnode;
	}
	

	else{
      ptr = head;
      
      for(i=1;i<pos-1 && ptr->next !=head;i++){
      	ptr = ptr->next;
	  }
	  
	  newnode->next = ptr->next;
	  ptr->next= newnode;
	}

}

void create(){
	int n,i;
	struct node *newnode,*temp;
	printf("Enter How Many Nodes You Want To Create:- ");
	scanf("%d",&n);
	for(i=0;i<n;i++){
		newnode = (struct node *)malloc(sizeof(struct node));
		if(newnode == NULL){
			printf("Memory allocation Failed..\n");
			return;
		}
		printf("Enter The Data for Node %d :- ",i+1);
		scanf("%d",&newnode->data);
		
		if(head == NULL){
           head = newnode;
           newnode->next = head;
           temp = head;
	    }
		else{
			temp->next = newnode;
			newnode->next = head;
			temp = newnode;
		}
	}

}

void insert_end(){
	struct node *newnode,*temp;
	
	newnode=(struct node *)malloc(sizeof(struct node));
	if(newnode == NULL){
		printf("Memory Allocation Failed..\n");
		return;
	}
	
	printf("Enter the value to insert At End:- ");
	scanf("%d",&newnode->data);
	
	if(head == NULL){
		head = newnode;
		newnode->next = head; 
	}
	else{
		temp = head;
		while(temp->next != head){
			temp = temp->next;
		}
		
		temp->next = newnode;
		newnode->next = head;
	}
}

void insert_beg(){
	struct node *newnode,*temp;
	newnode = (struct node *)malloc(sizeof(struct node));
	if(newnode == NULL){
		printf("Memory Allocation Failed..\n");
		return;
	}
	printf("Enter the data to Insert:- ");
	scanf("%d",&newnode->data);
	
	if(head == NULL){
		head = newnode;
		newnode->next = head;
	}
	else{
		temp = head;
		while(temp->next != head){
			temp = temp->next;
		}
		newnode->next = head;
		temp->next = newnode;
		head = newnode;
	}
}

void traverse(){
    struct node *temp;

    if(head == NULL){
        printf("List is empty\n");
        return;
    }

    temp = head;
	
	do{
		printf("%d->",temp->data);
		temp=temp->next;
	}while(temp != head);
}


