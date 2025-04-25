#include<stdio.h>
void main() {
	int a[20], i, n, key, flag = 0, pos;
	printf("Enter value of n : ");
	scanf("%d", &n);
	// Write code to read array elements
	int count;
	for(int i=0; i<n; i++){
		printf("Enter element for a[%d] : ", i);
		scanf("%d", &a[i]);
	}	
	printf("Enter key element : ");
	scanf("%d", &key);
	for(int i=0; i<20; i++){
		if(a[i]==key){
			// printf("The key element %d is found at the position %d\n", key, i);
			pos = i;
			flag = 1;
			break;
		}
		else{
			// printf("The key element %d is not found in the array\n", key);
			flag = 0;
			
		}
		
	}
	
	if (flag==1) { //Write the condition part
		printf("The key element %d is found at the position %d\n", key, pos); //Complete the statement
	} else {
		printf("The key element %d is not found in the array\n", key); //Complete the statement
	}
}