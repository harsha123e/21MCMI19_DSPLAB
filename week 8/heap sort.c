// C program for implementation of Heap Sort
#include <stdio.h>

// To minHeapify a subtree rooted with node i which is
// an index in arr[]. n is size of heap

void swap(int* a, int* b) { int t = *a; *a = *b;  *b = t; }

void maxHeapify(int arr[],int n, int i)
{
    int largest = i;  // Initialize largest as root
    int left = (i << 1) + 1;  // left = 2*idx + 1
    int right = (i + 1) << 1; // right = 2*idx + 2

    // See if left child of root exists and is greater than
    // root
    if (left < n && arr[left] > arr[largest])
        largest = left;

    // See if right child of root exists and is greater than
    // the largest so far
    if (right < n && arr[right] > arr[largest])
        largest = right;

    // Change root, if needed
    if (largest != i)
    {
        swap(&arr[largest], &arr[i]);
        maxHeapify(arr, n, largest);
    }
}


void minHeapify(int arr[], int n, int i)
{
	int smallest = i; // Initialize smalles as root
	int l = 2 * i + 1; // left = 2*i + 1
	int r = 2 * i + 2; // right = 2*i + 2

	// If left child is smaller than root
	if (l < n && arr[l] < arr[smallest])
		smallest = l;

	// If right child is smaller than smallest so far
	if (r < n && arr[r] < arr[smallest])
		smallest = r;

	// If smallest is not root
	if (smallest != i) {
		swap(&arr[i], &arr[smallest]);

		// Recursively minHeapify the affected sub-tree
		minHeapify(arr, n, smallest);
	}
}

void heapSort(int arr[], int n, int choice)
{
	if(choice==1){
		int i;
		for ( i = n / 2 - 1; i >= 0; i--)
			minHeapify(arr, n, i);
	
		for ( i = n - 1; i >= 0; i--) {
			swap(&arr[0], &arr[i]);
	
			minHeapify(arr, i, 0);
		}
	}
	if(choice==2){
		int i;
		for ( i = n / 2 - 1; i >= 0; i--)
			maxHeapify(arr, n, i);
	
		for ( i = n - 1; i >= 0; i--) {
			swap(&arr[0], &arr[i]);
	
			maxHeapify(arr, i, 0);
		}
	}
}

void deleteRoot(int arr[], int n, int choice)
{
    int lastElement = arr[n - 1];
 
    arr[0] = lastElement;
 
    n = n - 1;
 	if(choice==1)
    	minHeapify(arr, n, 0);
    if(choice==2)
    	maxHeapify(arr, n, 0);
}

void printArray(int arr[], int n)
{
	int i;
	for ( i = 0; i < n; ++i)
		printf("%d ",arr[i]);
	printf("\n");
}

int main()
{
	int n,choice;
	
	printf("Press\n");
	printf("1. MIN-HEAP\n");
	printf("2. MAX-HEAP\n");
	scanf("%d",&choice);
	
	printf("Enter number of elements : ");
	scanf("%d",&n);
			
	while(choice!=0){
		
		int i,arr[n];
		
		printf("Press\n");
		printf("1. Insert elements : \n");
		printf("2. Sort elements : \n");
		printf("3. Delete root element : \n");
		printf("0. EXIT \n");
		scanf("%d",&choice);
		
		if(choice==1){
			printf("Enter Elements : ");
			for(i=0;i<n;i++)
				scanf("%d",&arr[i]);
		}
		
		if(choice==2){
			
			heapSort(arr, n, choice);
		
			printf("Sorted array is \n");
			printArray(arr, n);
		}
		if(choice==3)
			deleteRoot(arr, n, choice);
	}
}
