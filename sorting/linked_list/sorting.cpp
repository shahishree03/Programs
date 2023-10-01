#include<iostream>
using namespace std;
class Node{
     public:
    int data;
    Node* next;
   
    Node(int data)
    {
        this->data = data;
        this->next = nullptr;
    }

    ~Node()
    {
        int value= this->data;
        if(this->next!=nullptr)
        {
            delete next;
            this->next=nullptr;
        }
        cout<<"memeory is free for data "<<value<<endl;
    }
};
   void insertionatbeg(Node*& head, int data )
   {
    Node* n1= new Node(data);
         
            n1->next = head;
            head = n1;

   }

   void insertionatend(Node*& head, int data)
   {
    Node* n1= new Node(data);
    if(head==nullptr)
    {
        head = n1;

    }
    Node* temp = head;
    while(temp->next!=nullptr)
    {
        temp = temp->next;
    }
    temp->next = n1;
   }
   void insertAtPosition(Node*& head, int pos , int data)
{
    if(pos==1)
    {
        insertionatbeg(head, data);
        return;
    }
    Node* temp = head;
    int count =1;
    while(count<pos-1)
    {
        temp = temp->next;
        count++;
    }
    if (temp->next==nullptr)
    {
      insertionatend(head , data);
      return;
    }
    Node* n1= new Node(data);
    n1->next = temp->next;
    temp->next = n1;
    
}
void print(Node* head)
{
    if(head==nullptr)
    {
        cout<<"list is empty"<<endl;
        return;
    }
    Node* temp = head;
    while(temp!=nullptr)
    {
       cout<<temp->data<<" ";
       temp= temp->next;
    }
    cout<<endl;
}

void sorting_selection(Node*& head)
{
   // Node* min_node = head;
   
   
    if(head==nullptr|| head->next ==nullptr)
    {
        return;
    }

    Node* i = head;
   
    while(i!=nullptr)
    {
        Node* min_node = i;
        Node* j = i->next;
        while(j!=nullptr)
        {
            if(j->data< min_node->data)
            {
                min_node=j;
            }
            j = j->next;
        }
            int temp = i->data;
            i->data = min_node->data;
            min_node->data = temp;
            i=i->next;
    }
 
}

void bubble_sort(Node*& head)
{
   if(head==nullptr|| head->next ==nullptr)
    {
        return;
    }

   bool sorted;
   Node* prev;
   Node* curr = nullptr;
   do{

    sorted = true;
    prev =nullptr;
    curr= head;
    while(curr->next!= nullptr)
    {
        if(curr->data> curr->next->data)
        {
            int temp = curr->data;
            curr->data = curr->next->data;
            curr->next->data = temp;
            sorted = false;
        }

        prev = curr;
        curr= curr->next;
    }

   }while(!sorted );
   
   
}
void deleteNode(int pos, Node*& head)
{
    if(pos==1)
    {
        Node* temp = head;
        head= head->next;
        temp->next = nullptr;
        delete temp;
    }
    else{
        Node* curr= head;
        Node* prev =nullptr;
        int cnt =1;
        while(cnt<pos)
        {
            prev = curr;
            curr= curr->next;
            cnt++;
        }
        prev->next = curr->next;
        curr->next = nullptr;
        delete curr;
    }
}
int main()
{
  //int arr[5]={64,57,12,13,56};
  Node* head = NULL;
  insertionatbeg(head,13);
   insertionatend(head, 56);
   insertionatbeg(head, 57);
   insertionatbeg(head, 64);
   insertAtPosition(head, 3, 12);

   print(head);
   cout<<"\n sorted linked list ..........\n";
  // sorting_selection(head);
  bubble_sort(head);
   print(head);


}