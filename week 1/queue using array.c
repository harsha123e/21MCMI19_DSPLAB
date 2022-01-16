//queue using array
#include <stdio.h>
#include <stdlib.h>

#define SIZE 5

int queue[SIZE],front =0, rear =0, size = 5;

void Enqueue(int element)
{
    if (size == rear) {
            printf("\nQueue is full\n");
            return;
        }
	else {
            queue[rear] = element;
            rear++;
            printf("%d added to queue\n",element);
        }
        return;
    }
 
void Dequeue(){
	int i;
    if (front == rear) {
        printf("\nQueue is empty\n");
        return;
    }
     else {
        for (i = 0; i < rear - 1; i++) {
            queue[i] = queue[i + 1];
        }
        printf("%d %d removed from queue\n",queue[front]);
        rear--;
   }
    return;
}
 
void display()
{
    int i;
    if (front == rear) {
        printf("\nQueue is Empty\n");
        return;
    }
    
    for (i = front; i < rear; i++) {
        printf(" %d <-- ", queue[i]);
    }
    return;
}
 
void Front(){
        
		if (front == rear) {
            printf("\nQueue is Empty\n");
            return;
        }
       printf("\nFront Element is: %d", queue[front]);
       return;
}


int main(){
	
	int choice=0,element;
		
	while(choice!=4){
		
		printf("Press 1 to Enqueue or add element\n");
		printf("Press 2 to Dequeue or delete element\n");
		printf("Press 3 to display all elements in Queue\n");
		printf("Press 4 to exit\n");
		printf("Enter your choice:");
		scanf("%d",&choice);
		
		if(choice==1){
		    printf("Enter the element to be added: ");
		 	scanf("%d",&element);
			Enqueue(element);
		}
		if(choice==2)
			Dequeue();
		if(choice==3) 
			display();		
	}
	
	return 0;
}
