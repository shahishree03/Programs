#include<iostream>
#include<vector>
using namespace std;
void binary_search(int* arr, int s,int e, int key, vector<int>& indexes)
{
    if(s>e)
    {
        return;
    }
    int mid;
    mid = (e+s)/2;
    if(arr[mid]==key)
    {
      indexes.push_back(mid);
    
    binary_search(arr, s,mid-1, key, indexes);
    binary_search(arr, mid+1,e, key, indexes);
    }
    else if(arr[mid]<key)
    {
        binary_search(arr,mid+1, e, key , indexes);
    }
    else{
        binary_search(arr, s, mid-1, key , indexes);
    }
   
}
int main()
{
    int arr[]={10,20,20,20,14,25,30};
    int n =sizeof(arr)/sizeof(arr[0]);
  vector<int> indexes;
  int search_ele =20;
  binary_search(arr, 0, n-1, search_ele, indexes);
  if(!indexes.empty())
  {
     for (int index : indexes) {
            cout << index << " ";
        }
  }
  else{
   cout<<"\n No elements found";
  }



}