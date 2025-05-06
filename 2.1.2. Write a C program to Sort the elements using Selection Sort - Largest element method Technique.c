#include<stdio.h>
void main() {
	int a[20], i, n, j, large, index;
	printf("Enter value of n : ");
	scanf("%d", &n);
	// Write the code to read an array elements
	for(int i=0; i<n; i++){
		printf("Enter element for a[%d] : ", i);
		scanf("%d", &a[i]);
	}
	
	printf("Before sorting the elements in the array are\n");
	// Write the code to print the given array elements before sorting
	for(int i=0; i<n; i++){
		printf("Value of a[%d] = %d\n", i, a[i]);
	}

	// Write the code for selection sort largest element method
	for(i=n-1; i>0; i--){
		large = 0;
		for(j=1; j<=i; j++){
			if(a[j]>a[large]){
				large = j;
			}
		}
		index = a[large];
		a[large] = a[i];
		a[i] = index;
	}
	
	printf("After sorting the elements in the array are\n");
	// Write the code to print the given array elements after sorting
	for(i = 0; i<n; i++){
		printf("Value of a[%d] = %d\n", i, a[i]);
	}
	
	
}