//singly linked list with only 0 and 1 and binary to decimal conversion
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#define MAX 20

struct node{
	int data;
	struct node *link;
}*top=NULL,*newnode,*temp;

void create_node(int element){
	newnode = (struct node*)malloc(sizeof(struct node));
	newnode->data=element;
	newnode->link=NULL;
}

void push(int element){
	create_node(element);
	if(top==NULL)
		top=newnode;
	else{
		newnode->link=top;
		top=newnode;
	}
}
void pop(){
	if(top==NULL)
		return;
	else{
		temp=top;
		top=top->link;
		printf("%d is removed\n",temp->data);
		free(temp);
	}	
}
void display(struct node* temp){
	if(temp==NULL) return;
	display(temp->link);
	printf("%d",temp->data);
}
int evaluate(){
	int result=0,counter=0;
	temp=top;
	while(temp!=NULL){
		result += temp->data * pow(2,counter++);
		temp=temp->link;
	}
	return result;
}

int main(){
	int choice=-1,input;
	while(choice!=0){
		printf("Enter your choice:\n");
		printf("Press 1 to enter value (0 and 1 only):\n");
		printf("Press 2 to evaluate:\n");
		printf("Press 3 to display entered values:\n");
		printf("Press 4 to remove last entered element:\n");
		printf("Press 0 to exit\n");
		scanf("%d",&choice);
		if(choice==1){
			printf("Enter value: ");
			scanf("%d",&input);
			if(input!=0&&input!=1){
				printf("Invalid input. Program terminated\n");
				choice=0;
			}
			else
				push(input);
		}
		if(choice==2)
			printf("Equivalent function output : %d\n",evaluate());
		if(choice==3){
			display(top);
			printf("\n");
		}
		if(choice==4)
			pop();
	}
	
	return 0;
}
