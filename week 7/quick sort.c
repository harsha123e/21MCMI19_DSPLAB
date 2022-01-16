#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>

void swap(int *n1, int *n2){
	if(n1!=n2){	
	*n1=*n1^*n2;
	*n2=*n1^*n2;
	*n1=*n1^*n2;
	}
}

int partition(int a[],int start,int end){
	int *pivot=&a[start];
	while(start<end){
		while(a[start]<=*pivot)
			start++;
		while(a[end]>*pivot)
			end--;
		if(start<end)
			swap(&a[start],&a[end]);
	}
	if(*pivot>a[end])
		swap(pivot,&a[end]);
	return end;
}

int r_partition(int a[],int start,int end){
	srand(time(NULL));
	int random_index = start + rand() % (end - start);
	swap(&a[random_index],&a[start]);
	return partition(a,start,end);	
}

int m_partition(int a[],int start,int end){
	int median = start;
	int middle = (start+end)/2;
	
	if(a[start]>a[end] && a[start] <= a[middle])
		median = start;
	else if(a[end]>a[start] && a[end] <= a[middle])
		median = end;
	else
		median = middle;
	
	swap(&a[median],&a[start]);
	return partition(a,start,end);	
}

int m2_partition(int a[],int start,int end){
	int median = start;
	int n = end+1;
	int middle = (start+end)/2;
	
	if(a[n/4]>a[(3*n)/4] && a[n/4] <= a[middle])
		median = start;
	else if(a[(3*n)/4]>a[n/4] && a[(3*n)/4] <= a[middle])
		median = end;
	else
		median = middle;
	
	swap(&a[median],&a[start]);
	return partition(a,start,end);	
}

void quicksort(int arr[],int start,int end,int pivot_type){
	int sorted_position;
	if(start<end){
		if(pivot_type==1)
			sorted_position=partition(arr,start,end);
		else if(pivot_type==2)
			sorted_position=r_partition(arr,start,end);
		else if(pivot_type==3)
			sorted_position=m_partition(arr,start,end);
		else if(pivot_type==4)
			sorted_position=m2_partition(arr,start,end);
		quicksort(arr,start,sorted_position-1,pivot_type);
		quicksort(arr,sorted_position+1,end,pivot_type);
	}
}

int main(){
	
	unsigned long long int n;
	int i,pivot_type;
	
	printf("Enter array size : ");
	scanf("%llu",&n);
	
	printf("Enter pivot type:\n");
	printf("1.first element as pivot\n");
	printf("2.random element as pivot\n");
	printf("3.median of {first, middle, last} element as pivot\n");
	printf("4.median of {n/4, middle, 3n/4} element as pivot\n");
	scanf("%d",&pivot_type);
	
	int a[n];
	
	//assigning random values to array
	srand(time(NULL));
	for(i=0;i<n;i++)
		a[i] = rand()%100;
	
	quicksort(a,0,n-1,pivot_type);

	printf("Random Array after sorting:\n");
	for(i=0;i<n;i++)
		printf("%d ",a[i]);
	
	//assigning all elements as 1
	for(i=0;i<n;i++)
		a[i]=1;
			
	quicksort(a,0,n-1,pivot_type);

	printf("\nArray of 1s after sorting:\n");
	for(i=0;i<n;i++)
		printf("%d ",a[i]);
	
	//distoring 1st and last element for 1%
	a[0]=2;
	a[n-1]=2;
		
	quicksort(a,0,n-1,pivot_type);

	printf("\nAlmost sorted array after sorting:\n");
	for(i=0;i<n;i++)
		printf("%d ",a[i]);
		
	return 0;
}
