#include<iostream>
using namespace std;

class Queue
{
    char* arr;
    int front;
    int rear;
    int capacity;

    public:
    Queue(int size)
    {
        this->capacity = size;
        this-> arr = new char[size];
        this->front = rear-1;

    }
    ~Queue()
    {
        delete [] arr;
    }

    bool isEmpty()
    {
        return front == -1;
    }

    bool isFull()
    {
        return (rear+1)%capacity == front;
    }

    void push(char value)
    {
        if(isFull())
        {
            cout<<"Queueu is full"<<endl;
            return;
        }
        
            if(isEmpty())
            {
                 front=rear=0;
            }
            else{
               rear =(rear+1)%capacity;
            }

            arr[rear] = value;
            
        
    }
    char pop()
    {
        if(isEmpty()){
         //   cout<<"Queue is empty "<<endl;
            return '\0';
        }
        char value = arr[front];
        if(front==rear)
        {
            front = rear=-1;

        }
        else{
            front = (front+1)%capacity;
        }
        return value;
    }

};

int main()
{
    Queue q(10);
   string sequence = "EAS*Y*QUE***ST***IO***N***";
  //int size =10;
  for(char c:sequence)
  {
    if(c>=65 && c<=90)
    {
        q.push(c);
    }
    else if(c=='*')
    {
        char popped = q.pop();
            if (popped != '\0') {
                cout << "Popped: " << popped <<endl;
            }
    }
  }


}