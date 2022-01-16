//split circular nexted list into 2 parts
#include<stdio.h>
#include<stdlib.h>

struct node{
	int data;
	struct node *next;
}*head=NULL,*rear=NULL,*newnode,*temp,*head1,*head2;

void add_data(int data){
	
	newnode = (struct node*)malloc(sizeof(struct node));
	newnode->data=data;
	newnode->next=NULL;

	if(head==NULL&&rear==NULL){
		head=rear=newnode;
		newnode->next=head;
	}
	else{
		rear->next=newnode;
		rear=newnode;
		rear->next=head;
	}
}

void display(struct node *head){

	temp=head;

	if(temp==NULL){
		printf("List is empty\n");
		return;
	}

	do{
		printf("%d ",temp->data);
		temp=temp->next;
	}while(temp!=head);
	printf("\n");

}

void split_linkedlist(){
	struct node *slow = head;
	struct node *fast = head->next;
	while(fast!=head && (fast->next)!=head){
		slow=slow->next;
		fast=fast->next->next;
	}
	head1 = head;
	head2 = slow->next;
	slow->next = head1;
	
	struct node *cur = head2;
	while(cur->next!=head)
		cur=cur->next;
	cur->next = head2;
}

int main(){
	
	char input[20];
	int choice = -1,data;
	while(choice!=0){
		printf("\n\nEnter your choice:\n");
		printf("Press 1 to insert data:\n");
		printf("Press 2 to display data:\n");
		printf("Press 3 to display split nexted lists:\n");
		printf("Press 0 to exit.\n");

		fgets(input,10,stdin);
		if(sscanf(input,"%d",&choice)!=1)
			printf("Invalid input\n");

		if(choice==1){
			printf("Enter data to be entered: ");
			fgets(input,10,stdin);
			if(sscanf(input,"%d",&data)!=1)
				printf("Invalid input\n");
			else
				add_data(data);
		}
		
		if(choice==2) display(head);
		
		if(choice==3){
			split_linkedlist();
			display(head1);
			display(head2);
		}
	}	
	
	return 0;
}

