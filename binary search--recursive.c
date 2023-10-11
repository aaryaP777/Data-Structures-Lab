//binary search
//recursive
#include<stdio.h>
int main()
{
	int a[9]={1,2,3,4,5,6,7,8,9};
	int k=10;
	int l=0;
	int h=8;
	int x=recfunc(a,l,h,k);        //func. def
	if(x==-1)
	{
		printf("Not found");
	}
	else
	{
		printf("Element found at %d",x);
	}
}
int recfunc(int a[],int l,int h,int key){   //func def.
	int mid;
	mid = (l + h)/2;
	if(a[mid]==key){
		return mid;
	}
	else if(key>a[mid]){
		return recfunc(a,mid+1,h,key);	
	}
	else if(key<a[mid]){
		return recfunc(a,l,mid-1,key);
	}
	else{
		return -1;
	}
	
}
