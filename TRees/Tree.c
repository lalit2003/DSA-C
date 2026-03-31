#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *left;
    struct node *right;
};

struct node *root = NULL;

// BST Insert Function
struct node* insert(struct node* root, int value){

    // Create new node if root is NULL
    if(root == NULL){
        struct node* newnode = (struct node*)malloc(sizeof(struct node));
        
        if(newnode == NULL){
            printf("Memory Allocation Failed!\n");
            return NULL;
        }

        newnode->data = value;
        newnode->left = NULL;
        newnode->right = NULL;

        return newnode;
    }

    // Insert in left subtree
    if(value < root->data){
        root->left = insert(root->left, value);
    }
    // Insert in right subtree
    else if(value > root->data){
        root->right = insert(root->right, value);
    }
    // Duplicate values (optional handling)
    else{
        printf("Duplicate value not allowed: %d\n", value);
    }

    return root;
}

void preorder(struct node *temp){
	if(temp == NULL){
		return;
	}
	printf("%d ",temp->data);
	preorder(temp->left);
	preorder(temp->right);
}

void inorder(struct node *temp){
    if(temp == NULL){
        return;
    }

    inorder(temp->left);
    printf("%d ", temp->data);
    inorder(temp->right);
}

void postorder(struct node *temp){
    if(temp == NULL){
        return;
    }

    postorder(temp->left);
    postorder(temp->right);
    printf("%d ", temp->data);
}

void search(struct node *temp,int key){
    if(temp == NULL){
        printf("Key Not Found\n");
        return;
    }

    if(key == temp->data){
        printf("%d Key Found\n",key);
    }
    else if(key < temp->data){
        search(temp->left,key);
    }
    else{
        search(temp->right,key);
    }
}

void findmin(struct node *temp){
    if(temp == NULL){
        printf("Tree Is Empty..\n");
        return;
    }

    if(temp->left == NULL){
        printf("%d Is Minimum Value\n", temp->data);
        return;
    }

    findmin(temp->left);
}

void findmax(struct node *temp){
    if(temp == NULL){
        printf("Tree Is Empty..\n");
        return;
    }

    if(temp->right == NULL){
        printf("%d Is Maximum Value\n", temp->data);
        return;
    }

    findmax(temp->right);
}

int main(){
    int n, value, i,key;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    for(i = 0; i < n; i++){
        printf("Enter value: ");
        scanf("%d", &value);

        root = insert(root, value); 
    }

    printf("\nInorder Traversal (Sorted): ");
    inorder(root);
    
    printf("\nPreOrder Traversal:-\n");
    preorder(root);
    
    printf("\nPostOrder Traversal:-\n");
    postorder(root);
    
    printf("\nEnter the Key To Search:- ");
    scanf("%d",&key);
    search(root,key);

    return 0;
}

/*struct node* insert(struct node* root, int value){
    if(root == NULL){
        struct node* newnode = (struct node*)malloc(sizeof(struct node));
        newnode->data = value;
        newnode->left = newnode->right = NULL;
        return newnode;
    }

    if(value < root->data){
        root->left = insert(root->left, value);
    }
    else{
        root->right = insert(root->right, value);
    }

    return root;
}

void create(){
    struct node *newnode;

    newnode = (struct node*)malloc(sizeof(struct node));

    if(newnode == NULL){
        printf("Memory Allocation Failed..\n");
        return;
    }

    printf("Enter The Value To Insert: ");
    scanf("%d",&newnode->data);

    newnode->left = NULL;
    newnode->right = NULL;

    if(root == NULL){
        root = newnode;
    }
}*/
