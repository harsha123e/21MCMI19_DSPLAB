#include<stdio.h>
#include<stdlib.h>
#define MAX 30
int insq( int queue[MAX], int qno, int rear[], int limit[], int *ele)
{
      if( rear[qno] == limit[qno] )
            return -1;
      else
      {
            rear[qno]++; 
            queue[ rear[qno] ] = *ele;
            return 1;
      }
}
int delq( int queue[MAX], int qno, int front[], int rear[], int *ele)
{
      if( front[qno] == rear[qno] )
            return -1;
      else
      {
            front[qno]++;
            *ele = queue[ front[qno] ];
            return 1;
      }
}

int max_size_index(int f[],int r[],int n){
	int max=r[0]-f[0],i,index=0;
	for(i=0;i<n;i++)
		if(max<r[i]-f[i])
	 		return i;
	return index;
}

int min_size_index(int f[],int r[],int n){
	int min=r[0]-f[0],i,index=0;
	for(i=0;i<n;i++)
		if(min>r[i]-f[i])
	 		return i;
	return index;
}

int main()
{
      int queue[MAX],ele;
      int bott[10], limit[10], f[10], r[10];
      int i, n,qno,size,ch,reply;
      printf("How many queues you want to enter? : ");
      scanf("%d", &n);
      size = MAX / n; 
      bott[0] = -1;
      for(i =0;i<MAX;i++)
      	queue[i]=-1;
      for(i=0;i<10;i++){
      	f[i]=-1; r[i]=-1;
	  }
      for(i = 1; i < n; i++)
            bott[i] = bott[i-1] + size;
      for(i = 0; i < n; i++)
           limit[i] = bott[i] + size;
  	
  			
	  for(i = 0; i < n; i++)
            f[i] = r[i] = bott[i];
      printf("-------------------------------------\n");
      printf("\tMenu");
      printf("\n------------------------------------");
      printf("\n 1. Insert in element Queue");
      printf("\n 2. Delete element from a Queue");
      printf("\n 3. Display Queue \n");
	  printf("\n 0. Exit \n");
      printf("------------------------------------\n");
      while(1)
      {
            printf("Choose operation : ");
            scanf("%d", &ch);
            if(ch==1)
            {
                      
                      	qno = min_size_index(f,r,n);
                      	
                        printf("Element to be entered in queue number %d : ",qno);
                        scanf("%d", &ele);
                        reply = insq(queue, qno, r, limit, &ele);
                        if( reply == -1)
                              printf("Queue %d is full \n", qno);
                        else
                              printf("%d is inserted in queue number %d.\n\n", ele, qno);
        	}
            if(ch==2){
                        
                        qno = max_size_index(f,r,n);
                        
						reply = delq(queue, qno, f, r, &ele);
                        if( reply == -1)
                              printf("\n Queue %d is empty. \n", qno);
                        else
                              printf("%d is deleted from queue number %d \n\n",ele, qno);
            }
             if(ch==3)	{
			 	printf("All 4 queues are : ");
             	for(i=0;i<MAX;i++)
				 	printf("%d ",queue[i]);
				printf("\n");
			}
			if(ch==0)
				exit(0);
             if(ch!=1 && ch!=2 && ch!=3)
			 printf("Invalid operation \n");
            
      }
      return 0;
}
