//stack using linked list
#include <stdio.h>
#include <stdlib.h>

struct node{
	int data;
	struct node *next;
};

int top=-1,size=0;

struct node *head,*newnode;

void create_newnode(int element){
	newnode = (struct node*)malloc(sizeof(struct node));
	newnode->data = element;
	newnode->next = NULL;
	printf("%d is pushed into stack\n",newnode->data);
}

void push(int element){
	if(top>size-2)
		printf("Stack Overflow\n");
	else{
		top++;
		create_newnode(element);
		if(head==NULL)
			head = newnode;
		else{
			newnode->next = head;
			head=newnode;
		}
	}
}

void pop(){
	struct node *temp;
	if(top==-1)
		printf("Stack Underflow\n");
	else{
		temp = head;
		while(temp->next!=NULL)
			temp=temp->next;
		printf("%d is poped out\n",temp->data);
		free(temp);
		top--;
	}
}

void display(struct node* temp){
	if(top==-1){
		printf("No elements are present in stack\n");
		return;
	}
	if(temp==NULL) return;
	display(temp->next);
	printf("%d<-",temp->data);
}

int main(){
	
	int choice=0,element;
	
	printf("Enter size of the stack: ");
	scanf("%d",&size);
		
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
			display(head);
		printf("\n");		
	}
	
	return 0;
}
