#include<iostream>
using namespace std;

class linked_list_implementation
{
private:
   int data;
   linked_list_implementation* next;
public:
    linked_list_implementation(int data) {
     this->data = data;
        this->next = NULL;    }
   // ~linked_list_implementation();

};

int main()
{
    linked_list_implementation* node1 = new linked_list_implementation(10);
     cout << "Data inside node1: " << node1->data << endl;
    cout << "Next pointer inside node1: " << node1->next << endl;

}

int main()
{

}
