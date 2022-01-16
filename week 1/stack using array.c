//stack using array
#include <stdio.h>
#include <stdlib.h>

#define SIZE 10

int stack[SIZE],top=-1; 
 
void push(int element)
{
    if (top == SIZE - 1){
		printf("Stack overflow\n");
		return;
	}
    stack[++top] = element;
    printf("%d pushed to stack\n", element);
}
 
void pop()
{
    if (top==-1)
		printf("Stack underflow\n");
	else
		printf("%d poped out of stack\n",stack[top--]);
}

void display(){
	int i;
	if(top==-1)
		printf("No elements are present in stack\n");
	else{		
		printf("Elements of stack are: ");
		for(i=0;i<=top;i++)
			printf("%d ",stack[i]);	
	}

}

int main(){
	
	int choice=0,element;
		
	while(choice!=4){
		
		printf("Press 1 to push or add element\n");
		printf("Press 2 to pop or delete element\n");
		printf("Press 3 to display all elements in stack\n");
		printf("Press 4 to exit\n");
		printf("Enter your choice:");
		scanf("%d",&choice);
		
		if(choice==1){
		    printf("Enter the element to be pushed: ");
		 	scanf("%d",&element);
			push(element);
		}
		if(choice==2)
			pop();
		if(choice==3) 
			display();	
		printf("\n");	
	}
	
	return 0;
}
