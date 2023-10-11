#include<stdio.h>
void isort(int a[], int n)
{
    int i, j, flag;
    for(i=0;i<n;i++)//last element also considered(no. of passes= no. of ele)
    {
        for(j=i;j>0;j--)
        {
            if(a[j]<a[j-1])
            {
                int temp=a[j];
                a[j]=a[j-1];
                a[j-1]=temp;   
            }
            else
            {
            	break;
			}
        }
        printf("pass %d: ", i);
        for(int k=0;k<n;k++)
        {
        	printf("%d", a[k]);
		}
		printf("\n");
    }
}

int main()
{
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
	isort(arr, n1);
	printf("\nThe sorted array is: ");
	for(x=0;x<n1;x++)
	{
		printf(" %d", arr[x]);
	}
}
