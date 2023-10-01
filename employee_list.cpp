#include<iostream>
using namespace std;
class Employee
{
    public:
int Id;
int age;
string name;    
Employee* next;
Employee(int Id, string name, int age)
{
    this->Id = Id;
    this->name= name;
    this->age = age;
    this->next= NULL;
}

static void insertionAtbeg(Employee*& head, int Id, string name, int age)
{
    Employee* n = new Employee(Id, name, age);
    n->next = head;
    head =n;
}
static void insertionAtEnd(Employee*& head, int Id, string name, int age)
{
    Employee* n = new Employee(Id, name , age);
    if(head==NULL)
    {
        head=n;
        return;
    }
    Employee* temp =head;
    while(temp->next!=NULL)
    {
        temp = temp->next;
    }
    temp->next = n;
    
}

static void atSpecificId(Employee*& head, int d, int Id, string name , int age)
{
    Employee* n = new Employee(Id, name, age);
    if(head==NULL)
    {
        head=n;
        return ;
    }
    Employee* temp = head;
    while(temp->next!=NULL)
    {
        if(temp->Id==d)
        {
            n->next = temp->next;
            temp->next =n;
            break;
        }
        temp=temp->next;
    }

}
static void deleteById(Employee*& head, int d )
{
    if(head==NULL)
    {
        cout<<"No elemeent is there :ERROR!!\n";
        return;
    }
    if(head->Id ==d)
    {
        Employee* temp= head;
        head= head->next;
        delete temp;
    }

    Employee* prev =NULL;
    Employee* curr= head;

    while(curr->next!=NULL )
    {
        prev= curr;
        curr=curr->next;
        if(curr->Id==d)
        {
            prev->next= curr->next;
            delete curr;
        }
        
    }
}

static void delete_last_record(Employee*& head)
{
    if(head!=NULL)
    {
        Employee* temp = head;
        Employee* prev = NULL;
        while(temp->next!=NULL)
        {
            prev = temp;
            temp=temp->next;
        }
        if(prev==NULL)
        {
            delete head;
            head= NULL;
        }
        else{
            delete temp;
            prev->next = NULL;
        }
        
    }
}
}; 

void display(Employee* head)
{
    Employee* temp= head;
    while(temp!=NULL)
    {
       cout<<"Employee ID: "<<temp->Id<<", Name: "<<temp->name<<", Age: "<<temp->age<<endl;
         temp=temp->next;
    }
}

Employee* merge(Employee* left , Employee* right)
{
    if(!left)
    {
        return right;
    }

    if(!right)
    {
        return left;
    }
Employee* result=NULL;
    if(left->age<=right->age)
    {
        result= left;
        return merge(left->next, right);
    }
    else{
        result = right;
        return merge(left , right->next);
    }
    return result;
}
void mergeSort(Employee*& head)
{
    if(head==NULL||head->next == NULL)
    {
        return;
    }
    Employee* middle = head;
    Employee* fast = head->next;

    while(fast)
    {
        fast=fast->next;
        if(fast)
        {
            middle= middle->next;
            fast= fast->next;
        }

    }
    Employee* left = head;
    Employee* right = middle->next;
    middle->next = NULL;
    mergeSort(left);
    mergeSort(right);
    head = merge(left , right);
}
int main()
{
    Employee* head = NULL;
    
    int input;
   do{
       
       cout<<"Menu driven program \n";
    cout<<"Select an following to do the changing of the list \n";
    cout<<"1 . Insert a new record at the beginning\n 2. Insert a new record at the ned of list \n 3. Insert at specific Id record \n 4. Delete the employee record for specific employee ID \n 5. Sort the record based on employee age \n 6. Delete the last record in the current sorted list \n 7. Display element  \n 8. Selcting other than will give error and out of loop\n";
    
    cin>>input;
    switch (input)
    {
        case 1 :
        {
            string name;
            int id , age;
            cout<<"Enter Employee ID: ";
            cin>>id;
            cout<<"Enter Employee name: ";
            cin>>name;
            cout<<"Enter Employee age: ";
            cin>>age;
            cout<<"\nInserting new record...........\n";
            Employee::insertionAtbeg(head, id, name , age);
            break;
        }
        case 2:
        {
            int id, age;
            string name;
            cout<<"Enter Employee ID: ";
            cin>>id;
            cout<<"Enter Employee name: ";
            cin>>name;
            cout<<"Enter Employee age: ";
            cin>>age;
              cout<<"\nInserting new record...........\n";
            Employee::insertionAtEnd(head, id , name , age);
            break;
        }
        case 3:
        {
            int id,d, age;
            string name;
            cout<<"Enter at specific Employee ID: ";
            cin>>d;
            cout<<"Enter Employee ID: ";
            cin>>id;
            cout<<"Enter Employee name: ";
            cin>>name;
            cout<<"Enter Employee age: ";
            cin>>age;
              cout<<"\nInserting new record...........\n";
            Employee::atSpecificId(head, d, id , name , age);
            break;
        }
        
        case 4:
        {
            int id;
            cout<<"Enter employee id";
            cin>>id;
              cout<<"\nDeleting record...........\n";
            Employee::deleteById(head, id);
            break;
        }
        
        case 5:
        {
            mergeSort(head);
              cout<<"\nSorted record...........\n";
            cout<<"Employee record sorted by age: "<<endl;
            display(head);
            break;
        }
        case 6:
        {   
        Employee::delete_last_record(head);
          cout<<"\nDelete last record...........\n";
            break;
        }
        case 7:
        {
            cout<<"\ndisplay\n";
            display(head);
            
        }
        default:
        {
            cout<<"\nInvalid choice\n"<<endl;
        }
    }
    
   }while(input!=8);
}