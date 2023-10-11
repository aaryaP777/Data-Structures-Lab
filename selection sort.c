#include<stdio.h>
//selection sort -- side by side comparision

void ssort(int a[], int n)
{
    int i,j,flag;
    for(i=0;i<n-1;i++)
    {
        flag=0;
        for(j=i+1;j<n;j++)
        {
           if(a[j]<a[i])
           {
               int temp=a[j];
               a[j]=a[i];
               a[i]=temp;
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
	int n1,x;
	int arr[n1];
	printf("Enter the no. of array elements: ");
	scanf("%d", &n1);
	printf("\nEnter the array elements:\n");
	for(x=0;x<n1;x++)
	{
		scanf("%d", &arr[x]);
	}
	printf("\nThe array is: "); 
	for(x=0;x<n1;x++)
	{
		printf(" %d", arr[x]);
	}
	ssort(arr, n1);
	printf("\nThe sorted array is:\n ");
	for(x=0;x<n1;x++)
	{
		printf(" %d", arr[x]);
	}
}

