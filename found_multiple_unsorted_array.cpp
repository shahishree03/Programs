#include<iostream>
#include<vector>
using namespace std;
vector<int> findIndexes(int* arr, int size, int target , int cur_index)
{
    vector<int> indexes;
  if(cur_index>=size)
  {
    return indexes;
  }

if(arr[cur_index]== target)
{
    indexes.push_back(cur_index);

 // findIndexes(arr, size, target , cur_index+1);

}

vector<int> remaining_index = findIndexes(arr, size, target , cur_index+1);
indexes.insert(indexes.end(), remaining_index.begin(), remaining_index.end());

return indexes;
}

int main()
{
int arr[]={10,14,20,20,8,20,25,69,20};
int size = sizeof(arr)/sizeof(arr[0]);
vector<int> indexes= findIndexes(arr, size,20, 0 );
if (!indexes.empty()) {
        cout << "Element 20  found at indexes: ";
        for (int index : indexes) {
            cout << index << " ";
        }
       
    } else {
       cout << "Element 20 not found in the array" << endl;
    }

    return 0;
}