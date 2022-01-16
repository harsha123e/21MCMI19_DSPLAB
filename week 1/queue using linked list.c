//queue using linked list
#include <stdio.h>
#include <stdlib.h>

struct node{
	int data;
	struct node *next;
};

int front=0,rear=0,size=0;

struct node *head,*newnode,*temp;

void create_newnode(int element){
	newnode = (struct node*)malloc(sizeof(struct node));
	newnode->data = element;
	newnode->next = NULL;
	printf("%d is added to queue\n",newnode->data);
}

void enqueue(int element){
	if(rear==size)
		printf("Queue is full\n");
	else{
		rear++;
		create_newnode(element);
		if(head==NULL)
			head = newnode;
		else{
			temp = head;
			while(temp->next!=NULL)
				temp=temp->next;
			temp->next = newnode;
		}
	}
}

void dequeue(){
	struct node *nextnode;
	if(front==rear)
		printf("No elements are present in queue\n");
	else{
		nextnode = head->next;
		temp = head;
		head = nextnode;
		printf("%d is poped out\n",temp->data);
		free(temp);
		rear--;
	}
}

void display(){
	if(front==rear)
		printf("No elements are present in queue\n");
	else{
		temp = head;
		while(temp->next!=NULL){
			printf("%d<-",temp->data);
			temp=temp->next;
		}
		printf("%d<-",temp->data);
	}
	
}

int main(){
	
	int choice=0,element;
	
	printf("Enter size of the queue: ");
	scanf("%d",&size);
		
	while(choice!=4){
		
		printf("Press 1 to add element\n");
		printf("Press 2 to delete element\n");
		printf("Press 3 to display all elements in queue\n");
		printf("Press 4 to exit\n");
		printf("Enter your choice:");
		scanf("%d",&choice);
		
		if(choice==1){
		    printf("Enter the element to be added: ");
		 	scanf("%d",&element);
			enqueue(element);
		}
		if(choice==2)
			dequeue();
		if(choice==3) 
			display();
		printf("\n");		
	}
	
	return 0;
}
