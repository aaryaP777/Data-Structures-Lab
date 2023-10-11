#include<stdio.h>

int binsearch(int a[], int n, int x)
{
    int beg=0, end=n-1, mid;
    while(beg<=end)
    {
        mid=(beg+end)/2;
        if(x == a[mid])
        {
            return 1;
        }
            
        
        else if(x < a[mid])
        {
            end = mid - 1;
        }
        
        else if(x > a[mid])
        {
            beg = mid + 1;
        }
    }
    if(x != a[mid])
    {
        return 0;
    }
}
    
int main()
{
       int arr[] = {1,2,3,4,5,6,7};
       int n1 = sizeof(arr)/sizeof(arr[0]);
       int x1;
       printf("Enter the ele to be searched: ");
       scanf("%d", &x1);
       int r=binsearch(arr, n1, x1);
       if(r==1){
           printf("ele present");
       }
       else if(r==0){
           printf("ele not present");
       }
}

