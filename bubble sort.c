// bubble sorting
#include<stdio.h>
void bs(int a[], int n){
	int i,j;
	int flag;
	for(i=0;i<n-1;i++)//('n-1'=passes) so that it doesnt goes till last element, as the last element can't be compared to anything. 
	{
		flag=0;
		for(j=0;j<n-i-1;j++)// (j=comparisions) as 'i' inc, 'j' dec.
		{
			if(a[j]>a[j+1])
			{
				int temp=a[j];
				a[j]=a[j+1];
				a[j+1]=temp;
				flag=1;
			}
		}
		if(flag==0)
		{
			break;
		}
	}
}

int main(){
	int n1,i;
	int arr[n1];
	printf("Enter the no. of array elements: ");
	scanf("%d", &n1);
	printf("\nEnter the array elements:\n");
	for(i=0;i<n1;i++)
	{
		scanf("%d", &arr[i]);
	}
	printf("\nThe array is:\n "); 
	for(i=0;i<n1;i++)
	{
		printf(" %d", arr[i]);
	}
	bs(arr, n1);
	printf("\nThe sorted array is: ");
	for(i=0;i<n1;i++)
	{
		printf(" %d", arr[i]);
	}
}








