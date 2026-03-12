#include<stdio.h>
int main(){

    int arr[6];
    int i, size;          
    int pos, value;       

    printf("Enter number of elements (max 5): ");
    scanf("%d",&size);

    if(size > 5){
        printf("Array overflow!\n");
        return 0;
    }

    printf("Enter %d elements:\n",size);
    for(i = 0; i < size; i++){
        scanf("%d",&arr[i]);
    }

    printf("Enter the position to insert element: ");
    scanf("%d",&pos);

    printf("Enter the value to insert: ");
    scanf("%d",&value);

    for(i = size; i > pos; i--){
        arr[i] = arr[i-1];
    }

    arr[pos] = value;

    size++; 
    printf("Updated array:\n");
    for(i = 0; i < size; i++){
        printf("%d ",arr[i]);
    }

    return 0;
}
