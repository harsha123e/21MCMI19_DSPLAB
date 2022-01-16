//merge sort

#include<stdio.h>

void merge(int a[], int l, int mid, int r){
	int i=l,j=mid+1,k=l,temp[r+1];
	while(i<=mid && j<=r){
		if(a[i]<a[j]){
			temp[k]=a[i];
			i++;k++;
		}
		else{
			temp[k]=a[j];
			j++;k++;
		}
	}
	while(i<=mid){
		temp[k]=a[i];
		i++,k++;
	}
	while(j<=r){
		temp[k] = a[j];
		j++,k++;
	}
	for(i=l;i<=r;i++)
		a[i] = temp[i];
}

void mergeSort(int a[], int l, int r){
	int mid;
	if(l<r){
		mid = (l+r)/2;
		mergeSort(a,l,mid);
		mergeSort(a,mid+1,r);
		merge(a,l,mid,r);
	}
}

int main(){
	
	unsigned long long int n;
	int i,pivot_type;
	
	printf("Enter array size : ");
	scanf("%llu",&n);
		
	int a[n];
	
	//assigning random values to array
	srand(time(NULL));
	for(i=0;i<n;i++)
		a[i] = rand()%100;
	
	mergeSort(a, 0, n-1);

	printf("Random Array after sorting:\n");
	for(i=0;i<n;i++)
		printf("%d ",a[i]);
	
	//assigning all elements as 1
	for(i=0;i<n;i++)
		a[i]=1;
			
	mergeSort(a, 0, n-1);

	printf("\nArray of 1s after sorting:\n");
	for(i=0;i<n;i++)
		printf("%d ",a[i]);
	
	//distoring 1st and last element for 1%
	a[0]=2;
	a[n-1]=2;
		
	mergeSort(a, 0, n-1);

	printf("\nAlmost sorted array after sorting:\n");
	for(i=0;i<n;i++)
		printf("%d ",a[i]);
		
	return 0;
}
