//smallest subarray with sum greater than given value
#include <stdio.h>

int smallestSubWithSum(int arr[], int n, int x)
{
    // Initialize current sum and minimum length
    int curr_sum = 0, min_len = n + 1,i,j,k;
 
    // Initialize starting and ending indexes
    int start = 0, end = 0;
    while (end < n) {
        // Keep adding array elements while current sum
        // is smaller than or equal to x
        while (curr_sum <= x && end < n)
            curr_sum += arr[end++];
 
        // If current sum becomes greater than x.
        while (curr_sum > x && start < n) {
            // Update minimum length if needed
            if (end - start < min_len){
			
                min_len = end - start;
 				i = start;
 				j = end;
			 }
            // remove starting elements
            curr_sum -= arr[start++];
        }
    }
    
    printf("Sub array : ");
    for(k=i;k<j;k++)
    	printf("%d ",arr[k]);
    
    return min_len;
}
int main()
{	
	int i,arr[100],n,sum;
	printf("Enter size of array: ");
	scanf("%d",&n);
	printf("Enter array : ");
	for(i=0;i<n;i++)
		scanf("%d",&arr[i]);
	printf("Enter sum: ");
	scanf("%d",&sum);
	printf("\nSize of subarray : %d",smallestSubWithSum(arr, n, sum));
	return 0;
}
