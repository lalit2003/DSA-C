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
int  length();
void delete_beg();
void delete_end();
void delete_specific_pos();
void delete_as_fuck();

int main(){
	int choice;

	while(1){
		printf("\n\n*******Single-LinkList-Menu*******\n");
		printf("\n1.CREATE\n2.TRAVERSE\n3.INSERT-BEGINING\n4.INSERT-END\n5.INSER-AT-ANY-POSITION.");
		printf("\n6.DELETE-BEGINING\n7.DELETE-END\n8.DELETE FROM SPECIFIC POSITION.\n");
		printf("9.DELETE AS FUCK.\n10.EXIT.\n");
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
				delete_as_fuck();
				traverse();
				break;
			case 10:
				printf("\n********************************\n");
				printf("Exiting From Program..\n");
				exit(0);
			default:
				printf("Invalid Options...\n");
		}
	}
}

void delete_as_fuck(){
	struct node *temp,*ptr;
	int key;
	
	ptr = head;
	
	printf("Enter the key to delete:- ");
	scanf("%d",&key);
	
	if(head == NULL){
		printf("Nothing to Delete bkl...\n");
		return;
	}
	
	if(head->data == key){
		temp = head;
		head = head->next;
		printf("%d is deleted..\n",temp->data);
		free(temp);
	}
	else{
		temp = head;
		while(temp->next != NULL){
			if(temp->next->data == key){
				ptr = temp->next;
				temp->next = temp->next->next;
				printf("%d is Deleted.\n",ptr->data);
				free(ptr);
				break;
			}
			temp = temp->next;
		}
		
		printf("Bhkk bkl..\n");
		return;
	}
}

void delete_specific_pos(){
	struct node *ptr,*temp;
	int i,pos;
	ptr = head;
	temp = head;
	if(head == NULL){
		printf("List Is Empty..\n");
		return;
	}
	
	printf("Enter Your Position:- ");
	scanf("%d",&pos);
	
	if(pos == 1){
		delete_beg();
		return;
	}
	
	for(i=1;i<pos-1;i++){
		temp=temp->next;
	}
	
	ptr = temp->next;
	temp->next = ptr->next;
	free(ptr);
	
	
}

void delete_beg(){
	struct node *temp = head;
	if(head == NULL){
		printf("List Is Empty Nothing to Delete ..\n");
		return;
	}
	else{
		head = head->next;
		printf("%d Data Is deletd..\n",temp->data);
		free(temp);
		
	}
}

void delete_end(){
	struct node *temp = head;
	if(head == NULL){
		printf("List is Empty..\n");
		return;
	}
	else if(head->next == NULL){
        free(head);
        head = NULL;
        return;
    }
	else{
		while(temp->next->next!=NULL){
			temp=temp->next;
		}
		free(temp->next);
        temp->next = NULL;
	}
}

int length(){
	int count=0;
	struct node *temp = head;
	while(temp != NULL){
		count++;
		temp = temp->next;
	}
	
	return count;
}

void insert_any_pos(){
	int pos,i;
	int len = length();
	struct node *temp,*newnode;
	printf("Enter The Position :- ");
	scanf("%d",&pos);
	
	if(pos < 1 || pos > len+1){
        printf("Invalid Position\n");
        return;
    }
	
	newnode = (struct node *)malloc(sizeof(struct node));
	if(newnode == NULL){
		printf("Memory Allocation Failed..\n"); 
		return;
	}
	printf("Enter the Data To Insert:- ");
	scanf("%d",&newnode->data);
	
	if(pos == 1){
		insert_beg();
		return;
	}
	
	if(pos == len+1){
		insert_end();
		return;
	}
	temp = head;

   for(i =1 ;i<pos-1;i++){
   	  temp = temp->next;
   }
   
   newnode->next = temp->next;
   temp->next = newnode;

}

void insert_end(){
 	struct node *temp,*newnode;
 	temp = head;
 	
 	newnode = (struct node *)malloc(sizeof(struct node));
 	if(newnode == NULL){
 		printf("Memory Allocation Failed..\n");
 		return;
	}
	
	printf("Enter The Value To Insert At End:- ");
	scanf("%d",&newnode->data);
	newnode->next = NULL;
	 
 	if(head == NULL){
 		newnode->next = head;
 		head = newnode;
	}else{
		while(temp->next != NULL){
			temp=temp->next;
		}
		temp->next = newnode;
		newnode->next = NULL;
	}
	
}

void insert_beg(){
    struct node *newnode;

    newnode = (struct node *)malloc(sizeof(struct node));

    if(newnode == NULL){
        printf("Memory Allocation Failed..\n");
        return;
    }

    printf("Enter The Value To Insert:- ");
    scanf("%d",&newnode->data);

    newnode->next = head;
    head = newnode;

    printf("\nNode Inserted At Beginning Successfully..\n");
}

void create(){
	int n,i;
	printf("Enter How Many Nodes You Want To Create:- ");
	scanf("%d",&n);
	struct node *newnode,*temp;
	for(i=0;i<n;i++){
		newnode = (struct node *)malloc(sizeof(struct node));
		if(newnode == NULL){
			printf("Memory Allocation Failed..\n");
			return ;
		}
		printf("Enter The Data For Node %d:- ",i+1);
		scanf("%d",&newnode->data);
		newnode->next = NULL;
		
		if(head == NULL){
			newnode->next = head;
			head = newnode;
		}else{
			temp = head;
			
			while(temp->next != NULL){
				temp = temp->next;
			}
			
			temp->next = newnode;
		}
	}
}

void traverse(){
	struct node *temp = head;
	if(head == NULL){
		printf("List Is Empty..\n");
		return;
	}
	
    while(temp != NULL){
      printf("%d->",temp->data);
       temp = temp->next;
    }
   printf("NULL");
}

