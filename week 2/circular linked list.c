//circular linked list
#include<stdio.h>
#include<stdlib.h>

#define WORDS 3
#define SIZE 15

struct node{
	char info[WORDS][SIZE];
	struct node *link;
}*front=NULL,*rear=NULL,*newnode,*temp;

void create_node(){
	int i;
	newnode = (struct node*)malloc(sizeof(struct node));
	printf("Enter values:\n");
	for(i=0;i<WORDS;i++)
		scanf("%s",newnode->info[i]);
	newnode->link=NULL;
}
void add_data(){
	create_node();
	if(front==NULL&&rear==NULL){
		front=rear=newnode;
		newnode->link=front;
	}
	else{
		rear->link=newnode;
		rear=newnode;
		rear->link=front;
	}
}

void display(){
	int i,count=0;
	temp=front;
	if(temp==NULL){
		printf("List is empty\n");
		return;
	}
	printf("%d.",++count);
	for(i=0;i<WORDS;i++)
			printf("%s ",temp->info[i]);
	printf("\n");
	while(temp->link!=front){
		temp=temp->link;
		printf("%d.",++count);
		for(i=0;i<WORDS;i++)
			printf("%s ",temp->info[i]);
		printf("\n");
	}
}

void displaySecondString(){
	temp=front;
		printf("%s\n",temp->info[1]);
	while(temp->link!=front){
		temp=temp->link;
		printf("%s\n",temp->info[1]);
	}
}

int check_third_first_element(){

	int result=0;
	temp=front;
	if(temp==NULL){
		printf("List is empty\n");
		return;
	}
	if(!strcmp(temp->info[2],temp->link->info[0])==0)
		return 0;
	while(temp->link!=front){
		temp=temp->link;
		if(!strcmp(temp->info[2],temp->link->info[0])==0)
			return 0;
	}
	return 1;
}

int main(){
	
	int choice = 1;
	while(choice!=0){
		printf("Enter your choice:\n");
		printf("Press 1 to insert data:\n");
		printf("Press 2 to display data:\n");
		printf("Press 3 to display second string values:\n");
		printf("Press 4 to check if third and first node match or not\n");
		printf("Press 0 to exit.\n");
		scanf("%d",&choice);
		if(choice==1) add_data();
		if(choice==2) display();
		if(choice==3) displaySecondString();
		if(choice==4){
			if(check_third_first_element())
				printf("matching third and first element\n");
			else
				printf("third and first element not matching\n");
		}
	}	
	
	return 0;
}
