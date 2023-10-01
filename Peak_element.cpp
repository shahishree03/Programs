/*Find a peak element which is not smaller than its neighbours*/

#include<iostream>
using namespace std;

int arr(int* a, int low , int high, int n)
{
   int mid = low +(high-low)/2;
   if((mid==0 || a[mid-1]<=a[mid])&&(mid == n-1 || a[mid+1]<=a[mid]))
   return mid;

   else if (mid>0 && a[mid-1]>a[mid])
     return arr(a, low, mid-1, n );

    else
    return arr(a, mid+1, high, n);
}
int main()
{
    int ar[6]={ 1, 3, 20, 4, 1, 0 };
     cout<<arr(ar,0,5, 6);
}