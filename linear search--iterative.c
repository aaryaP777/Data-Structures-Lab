// linear search
#include<stdio.h>
int main(){
	int a[5];
	int i,k;
	printf("Enter the array elements: \n");
	for(i=0;i<5;i++){
		scanf("%d", &a[i]);
	}
	printf("Enter the element to be searched: ");
	scanf("%d", &k);
	for(i=0;i<5;i++){
		if(k!=a[i]){
		}
		else{
			printf("The given element is present in the array at index :%d ",i);
			break;
		}	
	}
	if(i==5){
		printf("The given element is not present in the array");
	}
	
	
}
