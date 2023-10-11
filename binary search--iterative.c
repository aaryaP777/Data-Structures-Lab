// binary search
//iterative
#include<stdio.h>
int main()
{
	int a[9]={1,2,3,4,5,6,7,8,9};
	int k=3;
	int l=0;
	int h=8;
	int mid = (l + h)/2;
	while(l<=h){
		if(a[mid]==k)
		{
			printf("Element found at %d", mid);	
			break;
		}
		else if(k>a[mid])
		{
			l=mid+1;
			mid=(l+h)/2;
		}
		else if(k<a[mid])
		{
			h=mid-1;
			mid=(l+h)/2;
		}
    }
    if(l>h)
	{
		printf("ELement not found");
	}
}
