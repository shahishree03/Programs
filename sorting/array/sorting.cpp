#include<iostream>
using namespace std;
void swap(int *a , int *b)
{
    int temp =*a;
    *a=*b;
    *b=temp;

}
void selection_sort(int* arr, int n)
{
     int i, j ,min;
     for(int i=0;i<n-1;i++)
     {
        min=i;
        for(int j=i+1;j<n;j++)
        {
            if(arr[j]<arr[min])
            min =j;
        }

        if(min!=i)
        swap(&arr[min], &arr[i]);

     }
}

void print_selection(int* arr, int n)
{
    for(int i=0;i<n;i++)
    {
       
        cout<<arr[i]<<"\n";
    }
}
int main()
{
 int arr[5]={64, 25, 12, 22, 11};
 selection_sort(arr, 5);   
  cout<<"selection_sorting .........."<<endl;
 print_selection(arr, 5);
}